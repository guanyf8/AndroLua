//
// Created by guan on 2025/3/13.
//

#ifndef PARALLELLJ_SCHEDULER_H
#define PARALLELLJ_SCHEDULER_H

#include <bits/stdatomic.h>
#include "DataStructure/map.h"
#include "DataStructure/hashTable.h"
#include "lua.h"


typedef struct ThreadBundle{
    int parent;         //线程所有者，返回值去往的地方
    Map* threads;  //子线程id对应的返回值buffer
    int bundle_size;
    atomic_int alive;   //子线程活着的记录，用于join的semaphore
    pthread_cond_t cond;
    pthread_mutex_t mutex;
} threadBundle;

typedef struct {
    void* buf;
    atomic_bool flag;
}ret_record;

int luasched_fork(lua_State* L);
int luasched_ret(lua_State* L);
int luasched_join(lua_State*);

LUAMOD_API int
luaopen_sched(lua_State *L);

#endif //PARALLELLJ_SCHEDULER_H
