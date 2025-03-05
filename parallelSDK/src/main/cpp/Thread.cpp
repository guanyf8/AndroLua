//
// Created by guan on 2025/3/4.
//

#include <jni.h>
#include "Thread.h"
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
#include "JNInfo.h"
#include "TaskQueue.h"




static int new_thread(){
    JNIEnv *env;
    jvm->AttachCurrentThread(&env, NULL);
    jclass clazz = env->FindClass("com/lockheed/parallelsdk/parallelSDK");
    jmethodID tick = env->GetStaticMethodID( clazz,"Tick","(I)V");
    jmethodID getInstance = env->GetStaticMethodID( clazz,"getInstance", "()Lcom/lockheed/parallelsdk/parallelSDK;");
    jobject sdkInstance = env->CallStaticObjectMethod(  clazz, getInstance);
    jmethodID mtd = env->GetMethodID(  clazz, "luaNewStateC", "()I");
    jint id=env->CallIntMethod(  sdkInstance, mtd);
//    jvm->DetachCurrentThread();
    return id;
}

int luathread_new(lua_State* L){
    lua_pushinteger(L,new_thread());
    return 1;
}

int luathread_free(lua_State* L){
    lua_close(L);
    jvm->DetachCurrentThread();
    return 0;
}

int luathread_post(lua_State* L){
    //todo:应该要通知对方才行，因为不能一直tick去占用cpu，通知上面handler去发一个popstack
    luatask_push(L);
    JNIEnv *env;
    jvm->AttachCurrentThread(&env, NULL);
    jclass clazz = env->FindClass("com/lockheed/parallelsdk/parallelSDK");
    jmethodID tick = env->GetStaticMethodID( clazz,"Tick","(I)V");
    env->CallStaticVoidMethod(clazz,tick,(int)lua_tointeger(L,3));
//    jvm->DetachCurrentThread();
    return 0;
}

//#define batch 20
int luathread_processTask(lua_State* L){
//    for(int i=0;i<batch;i++){
    int ret=luatask_pop(L);
//    }
    if(queue_record.at((int)lua_tointeger(L,3))->size!=0){
        JNIEnv *env;
        jvm->AttachCurrentThread(&env, NULL);
        jclass clazz = env->FindClass("com/lockheed/parallelsdk/parallelSDK");
        jmethodID tick = env->GetStaticMethodID( clazz,"Tick","(I)V");
        env->CallStaticVoidMethod(clazz,tick,(int)lua_tointeger(L,3));
//        jvm->DetachCurrentThread();
    }
    return ret;
}

LUAMOD_API int
luaopen_thread(lua_State *L) {
    luaL_checkversion(L);
    luaL_Reg l[] = {
            {"new",luathread_new},
            {"post",luathread_post},
            {"free",luathread_free},
            {"processtask",luathread_processTask},
            { NULL, NULL },
    };
    luaL_newlib(L, l);
    return 1;
}