//
// Created by guan on 2025/3/10.
//

#include <bits/stdatomic.h>
#include "SharedValue.h"

static atomic_char flag=1;
Map SharedCache;
pthread_rwlock_t cache_mutex;

void SharedCacheInit(){
    SharedCache=map_init();
//    SharedCache= (std::map<const char*, CacheEntry *,cmp_str>*)malloc(sizeof(std::map<const char*,CacheEntry *,cmp_str>));
    pthread_rwlock_init(&cache_mutex, NULL);
}



void SharedCacheFree(){
    map_free(&SharedCache);
}


//new_index进来
void* getpackbuffer(lua_State* L,int from,int* sz){
    //todo : 对function要特殊处理，上值只能访问共享内存的值
    return seri_pack(L, from, sz);
}

int lua_sharedindex(lua_State* L){
    //只会有一个变量在buffer里面
    int ret=1;
    CacheEntry * entry= map_find(&SharedCache, lua_tostring(L,-1));
    if(entry){
        ret = seri_unpack(L, entry->buffer);
    }else {
        lua_pushnil(L);
    }
    return ret;
}

int lua_sharednewindex(lua_State* L){
//    table, key, value
    int size=0;
    size_t len;
    const char* str = lua_tolstring(L, 2, &len);
    const char* dst = (const char*) malloc(len+1);
    memcpy(dst,str,len+1);

    void* buf= getpackbuffer(L,2,&size);
    CacheEntry * e= map_find(&SharedCache,dst);
    if(e==NULL){
        //insert
        e=(CacheEntry*) malloc(sizeof(CacheEntry));
        e->buffer=buf;
        pthread_mutex_init(&e->mutex,NULL);
        map_insert(&SharedCache,dst,(void*)e);
    }else{
        e= (CacheEntry *)map_find(&SharedCache,dst);
        //update
        if(!memcmp(e->buffer,buf,size))
            return 0;
        free(e->buffer);
        e->buffer=buf;
    }
    return 1;
}

int luashared_rwwlock(lua_State* L){
    pthread_rwlock_wrlock(&cache_mutex);
}

int luashared_rwrlock(lua_State* L){
    pthread_rwlock_rdlock(&cache_mutex);
}

int luashared_rwunlock(lua_State* L){
    pthread_rwlock_unlock(&cache_mutex);
}

//写入shared的全局表
LUAMOD_API int luaopen_shared(lua_State *L) {
    if(flag){
        SharedCacheInit();
        flag=0;
    }
    luaL_checkversion(L);
    lua_newtable(L);         //+1
    lua_newtable(L);         //+1
    lua_pushcfunction(L,lua_sharedindex);   //+1
    lua_setfield(L,-2,"__index");
    lua_pushcfunction(L,lua_sharednewindex);
    lua_setfield(L,-2,"__newindex");
    lua_setmetatable(L,-2);
    lua_setglobal(L,"_SHARED");

    luaL_Reg l[] = {
            { "mutex_rdlock",luashared_rwrlock },
            {"mutex_wrlock",luashared_rwwlock},
            { "mutex_unlock", luashared_rwunlock },
            { NULL, NULL },
    };
    luaL_newlib(L, l);
    return 1;
}