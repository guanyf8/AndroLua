//
// Created by guan on 2025/3/10.
//

#include <bits/stdatomic.h>
#include "SharedMem.h"
#include "JNInfo.h"

static atomic_char flag=1;
map* SharedCache;
pthread_rwlock_t cache_mutex=PTHREAD_RWLOCK_INITIALIZER;

void SharedCacheInit(){
    SharedCache=map_init(NULL);
}

void SharedCacheFree(){
    map_free(SharedCache);
}

int lua_sharedindex(lua_State* L){
    //只会有一个变量在buffer里面
    int ret=1;
    CacheEntry * entry= map_get(SharedCache, (union key_type)lua_tostring(L, -1));
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
    CacheEntry * e= map_get(SharedCache, (union key_type) dst);

    if(lua_isnil(L,3)){
        //delete
        map_erase(SharedCache,(union key_type)dst);
        return 1;
    }

    void* buf= seri_pack(L,2,&size);

    if(e==NULL){
        //insert
        e=(CacheEntry*) malloc(sizeof(CacheEntry));
        e->buffer=buf;
        map_node * n=new(map_node);
        n->key=(union key_type)dst;
        n->value=e;
        map_insert(SharedCache,n);
    }else{
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
    return 0;
}

int luashared_rwrlock(lua_State* L){
    pthread_rwlock_rdlock(&cache_mutex);
    return 0;
}

int luashared_rwunlock(lua_State* L){
    pthread_rwlock_unlock(&cache_mutex);
    return 0;
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
            { "rdlock",luashared_rwrlock },
            {"wtlock",luashared_rwwlock},
            { "unlock", luashared_rwunlock },
            { NULL, NULL },
    };
    luaL_newlib(L, l);
    return 1;
}