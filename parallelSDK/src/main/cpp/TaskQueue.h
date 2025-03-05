//
// Created by guan on 2025/3/2.
//


#ifndef PARALLELLJ_TASKQUEUE_H
#define PARALLELLJ_TASKQUEUE_H

#define QUEUE_SIZE 512

#include <atomic>
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
#include <map>

using namespace std;

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
} CirQue;

extern map<int,CirQue*> queue_record;

CirQue* CirQueInit(int id);
void CirQueClose(CirQue* que);
char PopTask(CirQue* q, task_item* out);
char PushTask(CirQue* q, task_item item);
int luatask_push(lua_State* L);
int luatask_pop(lua_State* L);

LUAMOD_API int luaopen_taskqueue(lua_State *L);


#endif //PARALLELLJ_TASKQUEUE_H
