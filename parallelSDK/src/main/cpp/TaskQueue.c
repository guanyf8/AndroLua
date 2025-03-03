//
// Created by guan on 2025/3/2.
//

#include "TaskQueue.h"
#include "lua-seri.h"
#include "lauxlib.h"
#include <stdlib.h>

//原子操作+自旋锁实现producer-consumer问题

CirQue queue;

CirQue* CirQueInit(CirQue* q) {
    atomic_init(&q->f, 0);
    atomic_init(&q->r, 0);
    atomic_init(&q->size, 0);
    atomic_flag_clear(&q->lock);
    return q;
}

void CirQueClose(CirQue* que){
    free(que);
}

char PopTask(CirQue* q,task* out) {
    while (atomic_flag_test_and_set(&q->lock))
        ;

    if (atomic_load(&q->size) == 0) {
        atomic_flag_clear(&q->lock);
        return false;
    }

    *out = q->buffer[atomic_load(&q->f)];
    atomic_store(&q->f, (atomic_load(&q->f) + 1) % QUEUE_SIZE);
    atomic_fetch_sub(&q->size, 1);
    atomic_flag_clear(&q->lock);
    return true;
}

char PushTask(CirQue* q, task item) {
    while (atomic_flag_test_and_set(&q->lock))
        ; // 自旋等待

    if (atomic_load(&q->size) == QUEUE_SIZE) {
        atomic_flag_clear(&q->lock);
        return false; // 队列已满
    }

    q->buffer[atomic_load(&q->r)] = item;
    atomic_store(&q->r, (atomic_load(&q->r) + 1) % QUEUE_SIZE);
    atomic_fetch_add(&q->size, 1);
    atomic_flag_clear(&q->lock);
    return true;
}


int luatask_push(lua_State* L){
    task temp={0,0,0,0};
//    buffer,size,target_lua_id,type
    switch(lua_gettop(L)){
        case 4:
            temp.type= lua_tointeger(L,4);
        case 3:
            temp.target_id= lua_tointeger(L,3);
        case 2:
            temp.size = lua_tointeger(L,2);
        case 1:
            temp.buffer= lua_touserdata(L,1);
            break;
        default:
            luaL_error(L,"invalid args");
    }
    PushTask(&queue,temp);
    return 0;
}


int luatask_pop(lua_State* L){
    task popped_task;
    char result=PopTask(&queue,&popped_task); // 从队列弹出一个任务

    if (result == 0) {
        lua_pushnil(L); // 队列为空时返回 nil
        return 1;
    }

    // 按顺序将任务字段压入栈（与 lua_pushtask 的参数顺序一致）
    lua_pushlightuserdata(L, popped_task.buffer); // buffer
    lua_pushinteger(L, popped_task.size);         // size
    lua_pushinteger(L, popped_task.target_id);    // target_id
    lua_pushinteger(L, popped_task.type);         // type

    return 4; // 返回 4 个值
}

LUAMOD_API int
luaopen_taskqueue(lua_State *L) {
    luaL_checkversion(L);
    luaL_Reg l[] = {
            { "pushtask", luatask_push },
            { "poptask", luatask_pop },
            { NULL, NULL }
    };
    luaL_newlib(L, l);
    return 1;
}




