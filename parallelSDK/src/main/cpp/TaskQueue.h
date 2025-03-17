//
// Created by guan on 2025/3/2.
//


#ifndef PARALLELLJ_TASKQUEUE_H
#define PARALLELLJ_TASKQUEUE_H

#define QUEUE_SIZE 512

#include <bits/stdatomic.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "DataStructure/hashTable.h"

#define TYPE_REQUIRE 0
#define TYPE_INVOKE  1
#define TYPE_CALLBACK 2

typedef struct {
    void* buffer;
    int size;
    int target_id;
    short type;
} task_item;

typedef struct {
    task_item buffer[QUEUE_SIZE];
    atomic_int f;        // 原子队首索引
    atomic_int r;
    atomic_int size;
    atomic_flag lock;
} Queue;


extern hashMap* queue_record;     //todo 注意线程安全
extern pthread_rwlock_t rwlock;

Queue* QueueInit(int id);
void QueueClose(int id);
char PopTask(Queue* q, task_item* out);
char PushTask(Queue* q, task_item item);
int luatask_push(lua_State* L);
int luatask_pop(lua_State* L);

LUAMOD_API int luaopen_taskqueue(lua_State *L);


#endif //PARALLELLJ_TASKQUEUE_H
