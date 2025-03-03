#include <jni.h>
#include <string.h>
#include <lua.h>
#include <android/log.h>
#include "lauxlib.h"
#include "ToolFunction.h"
#include "TaskQueue.h"

int luaopen_seri(lua_State *L);

JNIEnv* SDKEnv;

JNIEXPORT jlong JNICALL
Java_com_lockheed_parallelsdk_parallelSDK_SDKInitLua(
        JNIEnv* env,
        jobject this,
        jlong L) {
    SDKEnv=env;
    lua_pushcfunction((lua_State *) L, lua_print);
    lua_setglobal((lua_State *) L, "print");
    lua_pushcfunction((lua_State *) L, lua_my_tostring);
    lua_setglobal((lua_State*)L,"tostring");
    luaL_requiref((lua_State *) L, "seri", luaopen_seri, 1);
    luaL_requiref((lua_State*)L,"taskqueue",luaopen_taskqueue,1);
    CirQueInit(&queue);
    return L;
}

