//
// Created by guan on 2025/2/28.
//

#ifndef PARALLELLJ_TOOLFUNCTION_H
#define PARALLELLJ_TOOLFUNCTION_H
#include <jni.h>
#include <string.h>
#include <lua.h>
#include <android/log.h>
#include "lauxlib.h"


void handle_userdata(lua_State *L, int index, luaL_Buffer *buf);

void handle_table(lua_State *L, int index, luaL_Buffer *buf, int depth);

void dump_value(lua_State *L, int index, luaL_Buffer *buf, int depth);

int lua_print(lua_State *L);

int lua_my_tostring(lua_State* L);

#endif //PARALLELLJ_TOOLFUNCTION_H
