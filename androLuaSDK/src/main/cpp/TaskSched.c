//
// Created by guan on 2025/3/13.
//
#include <unistd.h>
#include "TaskSched.h"
#include "lauxlib.h"
#include "lua-seri.h"
#include "JNInfo.h"
#include <pthread.h>

static const char* THREAD_BUNDLE_KEY = "__THREAD_BUNDLE";

static ISPair* new_light_thread(){
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm,&env, NULL);
    jclass clazz = (*env)->FindClass(env,"com/lockheed/androlua/androLuaSDK");
    jmethodID getInstance = (*env)->GetStaticMethodID( env,clazz,"getInstance", "()Lcom/lockheed/androlua/androLuaSDK;");
    jobject sdkInstance = (*env)->CallStaticObjectMethod(  env,clazz, getInstance);
    jmethodID mtd = (*env)->GetMethodID(  env,clazz, "luaNewLightStateC", "()J");
    ISPair* id= (ISPair*) (*env)->CallLongMethod(  env,sdkInstance, mtd);

//    jvm->DetachCurrentThread();
    return id;
}

static void* free_light_thread(int id){
//    hashErase(queue_record,id);
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm,&env, NULL);
    jclass clazz = (*env)->FindClass(env,"com/lockheed/androlua/androLuaSDK");
    jmethodID getInstance =  (*env)->GetStaticMethodID(env,clazz,"getInstance", "()Lcom/lockheed/androlua/androLuaSDK;");
    jobject sdkInstance = (*env)->CallStaticObjectMethod(env,  clazz, getInstance);
    jmethodID mtd = (*env)->GetMethodID(env, clazz, "closeLightStateC", "(I)V");
    (*env)->CallVoidMethod(env,sdkInstance, mtd,id);
}


static threadBundle * bundleGet(lua_State* L){
    lua_pushstring(L, THREAD_BUNDLE_KEY);
    lua_rawget(L, LUA_REGISTRYINDEX);  // 从注册表获取值

    threadBundle* tbun = (threadBundle*)lua_touserdata(L, -1);
    lua_pop(L, 1);  // 弹出值
    return tbun;
}

static void bundleSet(lua_State* L, threadBundle* tbun){
    lua_pushstring(L, THREAD_BUNDLE_KEY);
    lua_pushlightuserdata(L, tbun);
    lua_rawset(L, LUA_REGISTRYINDEX);
}

typedef struct{
    lua_State * L;
    void* buf;
} thread_arg;

void* luasched_task(void* temp){
    thread_arg * args=temp;
    lua_State * L=args->L;
    void* buf=args->buf;
    //栈空
    lua_settop(L,0);
    lua_pushlightuserdata(L,buf);
    luaseri_unpack_remove(L);
    //栈顶runnable, ...
    if (lua_pcall(L, lua_gettop(L)-2,LUA_MULTRET,0) != LUA_OK) {
        char str[100];
        sprintf(str, "Error calling require: %s\n", lua_tostring(L, -1));
        luaL_error(L,str);
    } else {
        //栈里除了最底下，全是返回值
        int t= lua_gettop(L);
        int a= lua_tointeger(L,2);
        int b= lua_tointeger(L,3);
        lua_pushcfunction(L,luaseri_pack);
        lua_replace(L,1);
        lua_pcall(L, lua_gettop(L)-1,2,0);
        lua_pop(L,1);
        void* ret= lua_touserdata(L,-1);
        pthread_exit(ret);
    }

}

static int pthread_exec(lua_State* L ,pthread_t* pid,void* buf){
    thread_arg* args=new(thread_arg);
    args->L=L;
    args->buf=buf;
    return pthread_create(pid,NULL,luasched_task,args);
}

int luasched_fork(lua_State* L){
    int a= lua_gettop(L);
    //fork(runnable,...)
    luaseri_pack(L);
    lua_pop(L,1);
    void* args= lua_touserdata(L,-1);
    lua_getglobal(L,"ID");
    int selfid= lua_tointeger(L,-1);

    threadBundle * tbun= bundleGet(L);
    if(!tbun) {
        //初始化
        tbun = (threadBundle *) malloc(sizeof(threadBundle));
        tbun->parent = selfid;
        tbun->threads=map_init(numcmp);
        tbun->bundle_size=0;

        bundleSet(L, tbun);
    }

    //新lua vm
    ISPair* pair=new_light_thread() ;

    //执行且获取pid
    pthread_t* pid=new(pthread_t);
    pthread_exec(pair->s,pid,args);

    //新建图节点
    int* key=(int*) malloc(sizeof(int));
    *key = pair->id;
    //todo 注意非线程安全，但没有关系因为只有一个线程在操纵它
    map_insert(tbun->threads, key, (void*)pid);
    tbun->bundle_size++;
    free(pair);

    //回传id
    lua_pushinteger(L,*key);
    return 1;
}

int luasched_join(lua_State* L){
    //join(id)

    int join_id= lua_tointeger(L,1);

    threadBundle * tbun= bundleGet(L);
    if (!tbun) {
        luaL_error(L, "threadBundle not initialized");
        return 0;
    }
    pthread_t * t=map_find(tbun->threads,&join_id);
    void* buf;
    pthread_join(*t,&buf);

    //清理线程树的节点
    map_erase(tbun->threads,&join_id);

    tbun->bundle_size--;

    //回收线程
    free_light_thread(join_id);

    //释放哈希表
    if(!tbun->bundle_size) {
        // 从注册表移除 threadBundle
        lua_pushstring(L, THREAD_BUNDLE_KEY);
        lua_pushnil(L);
        lua_rawset(L, LUA_REGISTRYINDEX);
        // 释放 threadBundle 内存
        free(tbun);
    }

    if(buf)
        return  seri_unpack(L, buf);
    else
        return 0;
}

LUAMOD_API int
luaopen_sched(lua_State *L) {
    luaL_checkversion(L);
    luaL_Reg l[] = {
            {"fork",luasched_fork},
            {"join",luasched_join},
            { NULL, NULL },
    };
    luaL_newlib(L, l);
    return 1;
}
