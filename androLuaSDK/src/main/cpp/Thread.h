//
// Created by guan on 2025/3/4.
//

#ifndef PARALLELLJ_THREAD_H
#define PARALLELLJ_THREAD_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "lua-seri.h"
#include "JNInfo.h"
#include "MsgQueue.h"
#include <jni.h>

typedef struct task_struct{
    struct task_struct* parent;
    struct task_struct* child;
    int lua_id;
    lua_State* L;
} task_struct;

typedef struct IQpair{
    int id;
    Queue * q;
} IQPair;


//void* free_thread(int id,Queue* q);
extern int luathread_new(lua_State* L);
extern int luathread_free(lua_State* L);
extern int luathread_post(lua_State* L);
extern int luathread_execute(lua_State* L);

LUAMOD_API int
luaopen_thread(lua_State *L);
#endif //PARALLELLJ_THREAD_H
