#ifndef LUA_SERIALIZE_H
#define LUA_SERIALIZE_H

#include <lua.h>
#include <stddef.h>

// todo: raise OOM error

#define TYPE_BOOLEAN 0

#define TYPE_BOOLEAN_NIL 0
#define TYPE_BOOLEAN_FALSE 1
#define TYPE_BOOLEAN_TRUE 2

// hibits 0 false 1 true
#define TYPE_NUMBER 1
// hibits 0 : 0 , 1: byte, 2:word, 4: dword, 6: qword, 8 : double
#define TYPE_NUMBER_ZERO 0
#define TYPE_NUMBER_BYTE 1
#define TYPE_NUMBER_WORD 2
#define TYPE_NUMBER_DWORD 4
#define TYPE_NUMBER_QWORD 6
#define TYPE_NUMBER_REAL 8

#define TYPE_USERDATA 2
// hibits 0 : void *
// hibits 1 : c function
#define TYPE_USERDATA_POINTER 0
#define TYPE_USERDATA_CFUNCTION 1
#define TYPE_USERDATA_JOBJECT 2
#define TYPE_USERDATA_JCLASS 3
#define TYPE_USERDATA_LFUNCTION 4

#define TYPE_SHORT_STRING 3
// hibits 0~31 : len
#define TYPE_LONG_STRING 4

// hibits 0~30 : array size , 31 : extend size
#define TYPE_TABLE 5
#define TYPE_TABLE_MARK 6

// hibits 0~30 : ref ancestor id , 31 : extend id ( number )
#define TYPE_REF 7

#define MAX_COOKIE 32    //2^5
#define EXTEND_NUMBER (MAX_COOKIE-1)
#define COMBINE_TYPE(t,v) ((t) | (v) << 3)

#define BLOCK_SIZE 128
#define MAX_DEPTH 31

#define MAX_REFERENCE 32

struct block {
    struct block * next;
    char buffer[BLOCK_SIZE];
};

struct stack {
    int depth;
    int ref_index;
    int objectid;
    int ancestor[MAX_DEPTH];
};

struct reference {
    const void * object;
    uint8_t * address;
};

struct write_block {
    struct block * head;
    struct block * current;
    int len;
    int ptr;
    struct stack s;
    struct reference r[MAX_REFERENCE];
};

struct read_block {
    char * buffer;
    int len;
    int ptr;
    struct stack s;
};

void *
seri_pack(lua_State *L, int from, int *sz);

int
seri_unpack(lua_State *L, void *buffer);

        int luaseri_pack(lua_State *L);
int luaseri_unpack(lua_State *L);
int luaseri_unpack_remove(lua_State *L);
int luaseri_remove(lua_State *L);

void * seri_packstring(const char * str, int sz, void *p, size_t *output_sz);

LUAMOD_API int
luaopen_seri(lua_State *L);

#endif
