//
// Created by guan on 2025/3/10.
//

#ifndef PARALLELLJ_SHAREDVALUE_H
#define PARALLELLJ_SHAREDVALUE_H
#include <lua.h>
#include <lauxlib.h>
#include "lua-seri.h"
#include "DataStructure/map.h"
#include <pthread.h>

/*
typedef struct SharedValue;

typedef struct{
    SharedValue* array_part;
    std::map<const char*,SharedValue*,cmp_str>* hash_part;
} Table;

typedef struct SharedValue {
    int type;
    union Data{
        int boolean;
        double number;
        char* string;
        //可嵌套
        Table table;
    } data;
    pthread_mutex_t mutex;
    int ref_count;
} SharedValue;

SharedValue* Lua2SharedValue(lua_State* L, int index);
int Shared2Lua(const char* key);
*/

//暂时不考虑gc机制
typedef struct{
    pthread_mutex_t mutex;
    int ref_count;
    void* buffer;
} CacheEntry;

extern Map* SharedCache;
extern pthread_rwlock_t cache_mutex;

extern void SharedCacheInit();
//
extern void SharedCacheFree();


LUAMOD_API int luaopen_shared(lua_State *L);


#endif //PARALLELLJ_SHAREDVALUE_H
