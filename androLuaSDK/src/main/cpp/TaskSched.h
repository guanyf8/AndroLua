//
// Created by guan on 2025/3/13.
//

#ifndef PARALLELLJ_SCHEDULER_H
#define PARALLELLJ_SCHEDULER_H

#include <bits/stdatomic.h>
#include "DataStructure/map.h"
#include "DataStructure/hashTable.h"
#include "lua.h"
#include "jni.h"

typedef struct {
    int id;
    lua_State * s;
} ISPair;

typedef struct ThreadBundle{
    int parent;         //线程所有者，返回值去往的地方
    map* threads;  //子线程id对应的pid buffer
    int bundle_size;
} threadBundle;

int luasched_fork(lua_State* L);
int luasched_join(lua_State*);

LUAMOD_API int
luaopen_sched(lua_State *L);

#endif //PARALLELLJ_SCHEDULER_H
