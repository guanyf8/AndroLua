
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "ToolFunction.h"
#include "lua-seri.h"
#include "SharedValue.h"

#include <jni.h>
#include <string.h>
#include <android/log.h>
#include "TaskQueue.h"
#include "Thread.h"


extern int luaopen_seri(lua_State *L);

//JNIEnv* SDKEnv;
JavaVM * jvm;

JNIEXPORT jlong JNICALL
Java_com_lockheed_parallelsdk_parallelSDK_SDKLuaInit(JNIEnv *env, jobject thiz, jlong lua_state,
                                                     jint id) {
//    SDKEnv=env;
    (*env)->GetJavaVM(env,&jvm);
    lua_State * L=(lua_State *)lua_state;
//    走luajava
//    luaL_openlibs(L);
    lua_pushcfunction(L, lua_print);
    lua_setglobal(L, "print");
    lua_pushcfunction(L, lua_my_tostring);
    lua_setglobal(L,"tostring");
    luaL_requiref(L, "_seri", luaopen_seri, 1);
    luaL_requiref(L,"_queue",luaopen_taskqueue,1);
    luaL_requiref(L,"_thread",luaopen_thread,1);
    luaL_requiref(L,"shared",luaopen_shared,1);
    lua_pushinteger(L,id);
    lua_setglobal(L,"ID");
    CirQue * q=CirQueInit(id);
    lua_pushlightuserdata(L,q);
    lua_setglobal(L,"tqueue");
    return lua_state;
}