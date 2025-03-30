//
// Created by guan on 2025/2/28.
//

#include "ToolFunction.h"

#define INDENT_SIZE 2
static void add_indent(luaL_Buffer *buf, int depth) {
    int spaces = depth * INDENT_SIZE;
    for (int i = 0; i < spaces; i++) {
        luaL_addchar(buf, '  ');
    }
}


// 处理userdata类型
void handle_userdata(lua_State *L, int index, luaL_Buffer *buf) {
    void *p = lua_touserdata(L, index);
    luaL_addstring(buf, "userdata<");

    if (lua_getmetatable(L, index)) {
        lua_pushstring(L, "__name");
        lua_rawget(L, -2);
        if (lua_isstring(L, -1)) {
            luaL_addstring(buf, lua_tostring(L, -1));
        } else {
            luaL_addstring(buf, "unknown");
        }
        lua_pop(L, 2);  // 弹出__name值和metatable
    } else {
        luaL_addstring(buf, "unknown");
    }

    char addr[32];
    snprintf(addr, sizeof(addr), ">: %p", p);
    luaL_addstring(buf, addr);
}


// 处理table类型
#define MAX_DEPTH 10  // 最大递归深度
void handle_table(lua_State *L, int index, luaL_Buffer *buf, int depth) {
    if (depth >= MAX_DEPTH) {
        luaL_addstring(buf, "{...}");
        return;
    }

    lua_pushvalue(L, index);           //+1,1为表格，2复制表格
    const int table_abs = lua_gettop(L); // 以复制的表格为绝对索引

    // 检查循环引用
    const void *p = lua_topointer(L, table_abs);
    lua_pushlightuserdata(L, (void*)p);
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (!lua_isnil(L, -1)) {
        char addr[32];
        snprintf(addr, sizeof(addr), "table: %p", p);
        luaL_addstring(buf, addr);
        lua_pop(L, 2); // 弹出查询结果和复制的表格
        //不一定要退出，写入表格指针即可
        return;
    }

    // 标记处理中的表格
    lua_pushlightuserdata(L, (void*)p);
    lua_pushboolean(L, 1);
    lua_rawset(L, LUA_REGISTRYINDEX);

    char addr[32];
    snprintf(addr, sizeof(addr), "table: %p", p);
    luaL_addstring(buf, addr);
    luaL_addstring(buf, "{\n");
    lua_pushnil(L); // 初始键

    int item_count = 0;
    while (lua_next(L, table_abs) != 0) {
        // 处理键值对
        if (item_count++ > 0) {
            luaL_addstring(buf, ",\n");
        }
        add_indent(buf, depth + 1);

        /* 键处理（保持栈平衡的关键） */
        const int key_type = lua_type(L, -2);
        if (key_type == LUA_TSTRING) {
            // 字符串键直接使用
            luaL_addstring(buf, lua_tostring(L, -2));
        } else {
            // 非字符串键特殊处理
            luaL_addstring(buf, "[");
            // 创建临时拷贝处理键
            lua_pushvalue(L, -2); // 复制原始键
            dump_value(L, -1, buf, depth + 1);
            lua_pop(L, 1); // 弹出拷贝键
            luaL_addstring(buf, "]");
        }

        luaL_addstring(buf, " => ");

        /* 值处理 */
        dump_value(L, -1, buf, depth + 1);

        lua_pop(L, 1); // 弹出值，保留键用于下次迭代
    }

    // 后处理
    if (item_count > 0) {
        luaL_addstring(buf, "\n");
        add_indent(buf, depth);
    }
    luaL_addstring(buf, "}");

    // 清除循环标记
    lua_pushlightuserdata(L, (void*)p);
    lua_pushnil(L);
    lua_rawset(L, LUA_REGISTRYINDEX);

    lua_pop(L, 2); // 弹出复制的表格
}

// 递归处理各种类型的值
void dump_value(lua_State *L, int index, luaL_Buffer *buf, int depth) {
    int type = lua_type(L, index);
    switch (type) {
        case LUA_TNIL:
            luaL_addstring(buf, "nil");
            break;

        case LUA_TBOOLEAN:
            luaL_addstring(buf, lua_toboolean(L, index) ? "true" : "false");
            break;

        case LUA_TNUMBER: {
            lua_pushvalue(L, index);
            luaL_addstring(buf, lua_tostring(L, -1));
            lua_pop(L, 1);
            break;
        }

        case LUA_TFUNCTION:
            const char* func_type = lua_iscfunction(L, index) ? "C_function" : "Lua_function";
            // 获取函数指针地址
            const void *p = lua_topointer(L, index);  // 不改变栈
            // 构造输出字符串
            char func_info[64];
            snprintf(func_info, sizeof(func_info), "%s: %p", func_type, p);
            luaL_addstring(buf, func_info);
            break;

        case LUA_TSTRING: {
            const char *str = lua_tostring(L, index);
            luaL_addstring(buf, "\"");
            luaL_addstring(buf, str);
            luaL_addstring(buf, "\"");
            break;
        }

        case LUA_TTABLE:
            handle_table(L, index, buf, depth);
            break;

        case LUA_TUSERDATA:
            handle_userdata(L, index, buf);
            break;

        case LUA_TLIGHTUSERDATA:
            luaL_addstring(buf, "lightuserdata");
            const void *__p = lua_touserdata(L, index);
            char addr[32];
            snprintf(addr, sizeof(addr), ": %p", __p);
            luaL_addstring(buf, addr);
            break;

        default: {
            const char *type_name = lua_typename(L, type);
            luaL_addstring(buf, type_name);
            break;
        }
    }
}

// 新的print函数实现
int lua_print(lua_State *L) {
    luaL_Buffer buf;
    luaL_buffinit(L, &buf);

    int n = lua_gettop(L);
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            luaL_addstring(&buf, "\t");
        }
        dump_value(L, i, &buf, 0);
    }

    luaL_pushresult(&buf);
    const char *output = lua_tostring(L, -1);
    int ID= lua_getglobal(L,"ID");
    const char *idStr = lua_tostring(L, -1);
    if (idStr == NULL) {
        idStr = "";
    }

    char buffer[8];
    snprintf(buffer, sizeof(buffer), "Lua%s", idStr);
    __android_log_write(ANDROID_LOG_DEBUG, buffer, output);
    lua_pop(L, 1);  // 弹出生成的字符串
    return 0;
}

int lua_my_tostring(lua_State* L){
        luaL_Buffer buf;
        luaL_buffinit(L, &buf);

        // 处理第一个参数（模仿标准tostring行为）
        dump_value(L, 1, &buf, 0);

        luaL_pushresult(&buf);
        return 1; // 返回生成的字符串
}
