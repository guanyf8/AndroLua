#include <jni.h>
#include <string.h>
#include <lua.h>
#include <android/log.h>
#include "lauxlib.h"

int luaopen_serialize(lua_State *L);

#define LOG_TAG "LuaPrint"
#define MAX_DEPTH 10 // 防止无限递归

// 结构体用于跟踪已访问的 table
typedef struct {
    const void *tables[20];
    int count;
} VisitedTables;

// 递归转换函数
static void to_string(lua_State *L, int index, luaL_Buffer *buf, VisitedTables *visited) {
    int type = lua_type(L, index);

    switch (type) {
        case LUA_TNIL:
            luaL_addstring(buf, "nil");
            break;

        case LUA_TBOOLEAN:
            luaL_addstring(buf, lua_toboolean(L, index) ? "true" : "false");
            break;

        case LUA_TNUMBER: {
            double n = lua_tonumber(L, index);
            if (n == (lua_Integer)n) {
                luaL_addstring(buf, lua_tostring(L, index));
            } else {
                char num_buf[32];
                snprintf(num_buf, sizeof(num_buf), "%.14g", n);
                luaL_addstring(buf, num_buf);
            }
            break;
        }

        case LUA_TSTRING: {
            size_t len;
            const char *str = lua_tolstring(L, index, &len);
            luaL_addchar(buf, '"');
            luaL_addlstring(buf, str, len);
            luaL_addchar(buf, '"');
            break;
        }

        case LUA_TTABLE: {
            // 检测循环引用
            const void *ptr = lua_topointer(L, index);
            for (int i = 0; i < visited->count; i++) {
                if (visited->tables[i] == ptr) {
                    luaL_addstring(buf, "<循环引用>");
                    return;
                }
            }

            if (visited->count >= MAX_DEPTH) {
                luaL_addstring(buf, "<超过最大深度>");
                return;
            }

            // 记录已访问 table
            visited->tables[visited->count++] = ptr;

            luaL_addstring(buf, "{");

            lua_pushnil(L); // 第一个 key
            int is_first = 1;
            while (lua_next(L, index) != 0) {
                if (!is_first) luaL_addstring(buf, ", ");
                // 处理 key
                if (lua_type(L, -2) == LUA_TNUMBER) {
                    luaL_addchar(buf, '[');
                    to_string(L, -2, buf,visited);
                    luaL_addchar(buf, ']');
                } else {
                    to_string(L, -2, buf,visited);
                }
                luaL_addstring(buf, " = ");
                // 处理 value
                to_string(L, -1, buf, visited);

                lua_pop(L, 1); // 移出 value，保留 key
                is_first = 0;
            }
            luaL_addstring(buf, "}");
            visited->count--; // 回溯
            break;
        }
        default:
            luaL_addstring(buf, lua_typename(L, type));
            break;
    }
}

// 新 print 函数实现
static int lua_print(lua_State *L) {
    luaL_Buffer buf;
    luaL_buffinit(L, &buf);

    VisitedTables visited = {0};

    int nargs = lua_gettop(L);
    for (int i = 1; i <= nargs; i++) {
        if (i > 1) luaL_addchar(&buf, '\t');
        to_string(L, i, &buf,&visited);
    }

    luaL_pushresult(&buf);
    const char *msg = lua_tostring(L, -1);

    // 输出到 Android Logcat
    __android_log_write(ANDROID_LOG_DEBUG, LOG_TAG, msg);

    lua_pop(L, 1); // 清理缓冲区
    return 0;
}

JNIEXPORT jlong JNICALL
Java_com_lockheed_parallelsdk_parallelSDK_SDKInitLua(
        JNIEnv* env,
        jobject this,
        jlong L) {
    lua_pushcfunction((lua_State *) L, lua_print);
    lua_setglobal((lua_State *) L, "print");
    luaopen_serialize((lua_State*)L);
    return L;
}

