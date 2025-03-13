//
// Created by guan on 2025/3/2.
//

#include "TaskQueue.h"
#include "lua-seri.h"
#include <stdlib.h>
#include <string.h>

static atomic_char flag=1;
CirQue* queue_record[128];

//原子操作+自旋锁实现producer-consumer问题
CirQue* CirQueInit(int id) {
    CirQue * q=(CirQue*) malloc(sizeof(CirQue));
    atomic_init(&q->f, 0);
    atomic_init(&q->r, 0);
    atomic_init(&q->size, 0);
    atomic_flag_clear(&q->lock);
    queue_record[id]=q;
    return q;
}

void CirQueClose(int id){
    CirQue* que=queue_record[id];
    free(que);
    queue_record[id]=NULL;
}

char PopTask(CirQue* q, task_item* out) {
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

char PushTask(CirQue* q, task_item item) {
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
    task_item temp={0, 0, 0, 0};
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
    PushTask(queue_record[temp.target_id],temp);

    return 0;
}



int luatask_pop(lua_State* L){
    task_item popped_task;
    lua_getglobal(L,"tqueue");
    CirQue* q= (CirQue *)(lua_touserdata(L, -1));
    lua_pop(L,1);   //恢复栈平衡
    char result=PopTask(q,&popped_task); // 从队列弹出一个任务

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
    if(flag){
        memset(queue_record,0,sizeof(CirQue*)*128);
        flag=0;
    }
    luaL_checkversion(L);
    luaL_Reg l[] = {
            { "pushtask", luatask_push },
            { "poptask", luatask_pop },
            { NULL, NULL }
    };
    luaL_newlib(L, l);
    return 1;
}




