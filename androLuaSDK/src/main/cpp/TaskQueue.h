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
#include "lua-seri.h"
#include "DataStructure/hashTable.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>


#define TYPE_INVOKE  1
#define TYPE_CALLBACK 2
#define TYPE_INTRODUCE 3
#define TYPE_TERMINATE 4


typedef struct {
    void* buffer;
    struct queue* q;
    int target_id;
    short type;
} task_item;

typedef struct queue{
    task_item buffer[QUEUE_SIZE];
    atomic_int f;        // 原子队首索引
    atomic_int r;
    atomic_int size;
    atomic_flag lock;
} Queue;


extern hashMap* queue_record;     //todo 注意线程安全
extern pthread_rwlock_t rwlock;

Queue* QueueInit(int id);
void QueueClose(Queue*);
char PopTask(Queue* q, task_item* out);
char PushTask(Queue* q, task_item item);
int luatask_push(lua_State* L);
int luatask_pop(lua_State* L);

LUAMOD_API int luaopen_taskqueue(lua_State *L);


#endif //PARALLELLJ_TASKQUEUE_H
