#ifndef JUAAPI_H
#define JUAAPI_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "jni.h"

#include "jua.h"

/*
 * These methods are called by the lua environment
 * and thus raises errors to the lua environment.
 */


static int gc_CLASS(lua_State * L) {
  jobject * data = (jobject *) luaL_checkudata(L, 1, JAVA_CLASS_META_REGISTRY);
  JNIEnv * env = getJNIEnv(L);
  env->DeleteGlobalRef(*data);
  return 0;
}

static int gc_OBJECT(lua_State * L) {
    jobject * data = (jobject *) luaL_checkudata(L, 1, JAVA_OBJECT_META_REGISTRY);
    JNIEnv * env = getJNIEnv(L);
    env->DeleteGlobalRef(*data);
    return 0;
}

static int gc_ARRAY(lua_State * L) {
    jobject * data = (jobject *) luaL_checkudata(L, 1, JAVA_ARRAY_META_REGISTRY);
    JNIEnv * env = getJNIEnv(L);
    env->DeleteGlobalRef(*data);
    return 0;
}

/**
 * Expects the obj is a global ref
 */
static int pushJ(lua_State * L, jobject obj,const char *R) {
  jobject * data = (jobject *) lua_newuserdata(L, sizeof(jobject));
  *data = obj;

  luaL_setmetatable(L, R);
  return 1;
}

#define HANDLE_EXCEPTION(env) \
    jthrowable e = env->ExceptionOccurred(); \
    if (e != NULL)

int jclassIndex(lua_State * L);
int jclassNewIndex(lua_State * L);
int jclassCall(lua_State * L);
int jclassSigCall(lua_State * L);
int jobjectIndex(lua_State * L);
int jobjectSigCall(lua_State * L);
int jobjectNewIndex(lua_State * L);
int jobjectEquals(lua_State * L);
int jarrayLength(lua_State * L);
int jarrayIndex(lua_State * L);
int jarrayNewIndex(lua_State * L);
int jfunctionWrapper(lua_State * L);
int jmoduleLoad(lua_State * L);
int jloadModule(lua_State * L);

int jpackageImport(lua_State * L);

#endif /* JUAAPI_H! */
