//
// Created by guan on 2025/3/2.
//


#ifndef PARALLELLJ_TASKQUEUE_H
#define PARALLELLJ_TASKQUEUE_H

#define QUEUE_SIZE 1024

#include <bits/stdatomic.h>
#include "lua.h"

typedef struct {
    void* buffer;
    int size;
    int target_id;
    short type;
} task;

typedef struct {
    task buffer[QUEUE_SIZE];
    atomic_int f;        // 原子队首索引
    atomic_int r;
    atomic_int size;
    atomic_flag lock;
} CirQue;

extern CirQue queue;

CirQue* CirQueInit(CirQue* q);
void CirQueClose(CirQue* que);
char PopTask(CirQue* q,task* out);
char PushTask(CirQue* q, task item);
int luatask_push(lua_State* L);
int luatask_pop(lua_State* L);

LUAMOD_API int luaopen_taskqueue(lua_State *L);


#endif //PARALLELLJ_TASKQUEUE_H
