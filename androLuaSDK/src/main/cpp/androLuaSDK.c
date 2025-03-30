
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "ToolFunction.h"
#include "lua-seri.h"
#include "SharedMem.h"

#include <jni.h>
#include <string.h>
#include <android/log.h>
#include "TaskQueue.h"
#include "Thread.h"
#include "TaskSched.h"
#include "JNInfo.h"


extern int luaopen_seri(lua_State *L);

//JNIEnv* SDKEnv;
JavaVM * jvm;


JNIEXPORT jlong JNICALL
Java_com_lockheed_androlua_androLuaSDK_SDKLuaInit(JNIEnv *env, jobject thiz, jlong lua_state,
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
    luaL_requiref(L,"_shared",luaopen_shared,1);
    luaL_requiref(L,"_sched",luaopen_sched,1);
    lua_pushinteger(L,id);
    lua_setglobal(L,"ID");
    Queue * q=QueueInit(id);
    lua_pushlightuserdata(L,q);
    lua_setglobal(L,"tqueue");
    IQPair* pair=new(IQPair);
    pair->id=id;
    pair->q=q;
    return (jlong) pair;
}

JNIEXPORT jlong JNICALL
Java_com_lockheed_androlua_androLuaSDK_SDKLightLuaInit(JNIEnv *env, jobject thiz, jlong lua_state,
                                                       jint id) {
    (*env)->GetJavaVM(env,&jvm);
    lua_State * L=(lua_State *)lua_state;
    lua_pushcfunction(L, lua_print);    //+1
    lua_setglobal(L, "print");    //-1
    lua_pushcfunction(L, lua_my_tostring);   //+1
    lua_setglobal(L,"tostring");   //-1
    luaL_requiref(L, "_seri", luaopen_seri, 1);
    luaL_requiref(L,"_shared",luaopen_shared,1);   //+1
    luaL_requiref(L,"_sched",luaopen_sched,1);    //+1
    lua_pushinteger(L,id);     //+1
    lua_setglobal(L,"ID");  //-1
    ISPair * pair=new(ISPair);
    pair->id=id;
    pair->s=L;
    lua_pop(L,2);
    return (jlong)pair;
}

JNIEXPORT void JNICALL
Java_com_lockheed_androlua_androLuaSDK_FirstContact(JNIEnv *env, jobject thiz, jlong lua_state,
                                                    jlong queue) {
    //此时栈空
    lua_State* L=(lua_State*)lua_state;
    Queue* q=(Queue* )queue;
    lua_getglobal(L, "require");
    lua_pushstring(L, "contacts");
    if (lua_pcall(L, 1, 1, 0) != LUA_OK) {
        fprintf(stderr, "Error calling require: %s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
    } else {
        //得到了0的队列
        lua_pushinteger(L,0);
        lua_pushlightuserdata(L,q);
        lua_settable(L,-3);
        lua_pop(L,1);
        //栈空
        lua_pushcfunction(L, luaseri_pack);
        lua_getglobal(L,"ID");
        lua_getglobal(L,"tqueue");
        lua_pcall(L,2,2,0);
        lua_pop(L,1);

        //向main播报自己的队列
        lua_getglobal(L, "_thread");
        lua_getfield(L, -1, "post");
        lua_pushvalue(L,-3);
        lua_pushlightuserdata(L,q);
        lua_pushinteger(L,0);
        lua_pushinteger(L,TYPE_INTRODUCE);
        lua_pcall(L,4,0,0);
    }
}