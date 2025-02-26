#include "party_iroiro_luajava_lua53_Lua53Natives.h"

//@line:107

            #include "luacustomamalg.h"

            #include "lua.hpp"
            #include "jni.h"

            #include "jua.h"

            #include "luacomp.h"

            #include "juaapi.h"
            #include "jualib.h"
            #include "juaamalg.h"

            #include "luacustom.h"
         static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_reopenGlobal
(JNIEnv* env, jobject object, jstring obj_file, char* file) {

//@line:155

        return (jint) reopenAsGlobal((const char *) file);
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_reopenGlobal(JNIEnv* env, jobject object, jstring obj_file) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_reopenGlobal(env, object, obj_file, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_initBindings(JNIEnv* env, jclass clazz) {


//@line:159

        return (jint) initLua53Bindings(env);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_getRegistryIndex(JNIEnv* env, jobject object) {


//@line:166

        return LUA_REGISTRYINDEX;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1absindex(JNIEnv* env, jobject object, jlong ptr, jint idx) {


//@line:191

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_absindex((lua_State *) L, (int) idx);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1arith(JNIEnv* env, jobject object, jlong ptr, jint op) {


//@line:260

        lua_State * L = (lua_State *) ptr;

        lua_arith((lua_State *) L, (int) op);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1checkstack(JNIEnv* env, jobject object, jlong ptr, jint n) {


//@line:295

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_checkstack((lua_State *) L, (int) n);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1close(JNIEnv* env, jobject object, jlong ptr) {


//@line:327

        lua_State * L = (lua_State *) ptr;

        lua_close((lua_State *) L);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1compare(JNIEnv* env, jobject object, jlong ptr, jint index1, jint index2, jint op) {


//@line:376

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_compare((lua_State *) L, (int) index1, (int) index2, (int) op);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1concat(JNIEnv* env, jobject object, jlong ptr, jint n) {


//@line:408

        lua_State * L = (lua_State *) ptr;

        lua_concat((lua_State *) L, (int) n);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1copy(JNIEnv* env, jobject object, jlong ptr, jint fromidx, jint toidx) {


//@line:437

        lua_State * L = (lua_State *) ptr;

        lua_copy((lua_State *) L, (int) fromidx, (int) toidx);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1createtable(JNIEnv* env, jobject object, jlong ptr, jint narr, jint nrec) {


//@line:471

        lua_State * L = (lua_State *) ptr;

        lua_createtable((lua_State *) L, (int) narr, (int) nrec);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1error(JNIEnv* env, jobject object, jlong ptr) {


//@line:500

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_error((lua_State *) L);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1gc(JNIEnv* env, jobject object, jlong ptr, jint what, jint data) {


//@line:593

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_gc((lua_State *) L, (int) what, (int) data);
        return returnValueReceiver;
    

}

static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1getfield
(JNIEnv* env, jobject object, jlong ptr, jint index, jstring obj_k, char* k) {

//@line:628

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_getfield((lua_State *) L, (int) index, (const char *) k);
        return returnValueReceiver;
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1getfield(JNIEnv* env, jobject object, jlong ptr, jint index, jstring obj_k) {
	char* k = (char*)env->GetStringUTFChars(obj_k, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1getfield(env, object, ptr, index, obj_k, k);

	env->ReleaseStringUTFChars(obj_k, k);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1getfield(JNIEnv* env, jobject object, jlong ptr, jint index, jstring obj_k) {
	char* k = (char*)env->GetStringUTFChars(obj_k, 0);


//@line:662

        lua_State * L = (lua_State *) ptr;

        lua_getfield((lua_State *) L, (int) index, (const char *) k);
    
	env->ReleaseStringUTFChars(obj_k, k);

}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1getextraspace(JNIEnv* env, jobject object, jlong ptr) {


//@line:701

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) lua_getextraspace((lua_State *) L);
        return returnValueReceiver;
    

}

static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1getglobal
(JNIEnv* env, jobject object, jlong ptr, jstring obj_name, char* name) {

//@line:729

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_getglobal((lua_State *) L, (const char *) name);
        return returnValueReceiver;
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1getglobal(JNIEnv* env, jobject object, jlong ptr, jstring obj_name) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1getglobal(env, object, ptr, obj_name, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1getglobal(JNIEnv* env, jobject object, jlong ptr, jstring obj_name) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);


//@line:756

        lua_State * L = (lua_State *) ptr;

        lua_getglobal((lua_State *) L, (const char *) name);
    
	env->ReleaseStringUTFChars(obj_name, name);

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1geti(JNIEnv* env, jobject object, jlong ptr, jint index, jlong i) {


//@line:790

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_geti((lua_State *) L, (int) index, (lua_Integer) i);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1geti(JNIEnv* env, jobject object, jlong ptr, jint index, jlong i) {


//@line:824

        lua_State * L = (lua_State *) ptr;

        lua_geti((lua_State *) L, (int) index, (lua_Integer) i);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1getmetatable(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:853

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_getmetatable((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1gettable(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:893

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_gettable((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1gettable(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:932

        lua_State * L = (lua_State *) ptr;

        lua_gettable((lua_State *) L, (int) index);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1gettop(JNIEnv* env, jobject object, jlong ptr) {


//@line:960

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_gettop((lua_State *) L);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1getuservalue(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:992

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_getuservalue((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1insert(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1021

        lua_State * L = (lua_State *) ptr;

        lua_insert((lua_State *) L, (int) index);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1isboolean(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1048

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_isboolean((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1iscfunction(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1076

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_iscfunction((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1isfunction(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1104

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_isfunction((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1isinteger(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1133

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_isinteger((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1islightuserdata(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1161

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_islightuserdata((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1isnil(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1189

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_isnil((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1isnone(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1217

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_isnone((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1isnoneornil(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1246

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_isnoneornil((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1isnumber(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1275

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_isnumber((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1isstring(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1304

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_isstring((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1istable(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1332

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_istable((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1isthread(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1360

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_isthread((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1isuserdata(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1388

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_isuserdata((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1isyieldable(JNIEnv* env, jobject object, jlong ptr) {


//@line:1415

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_isyieldable((lua_State *) L);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1len(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1444

        lua_State * L = (lua_State *) ptr;

        lua_len((lua_State *) L, (int) index);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1newtable(JNIEnv* env, jobject object, jlong ptr) {


//@line:1469

        lua_State * L = (lua_State *) ptr;

        lua_newtable((lua_State *) L);
    

}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1newthread(JNIEnv* env, jobject object, jlong ptr) {


//@line:1504

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) lua_newthread((lua_State *) L);
        return returnValueReceiver;
    

}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1newuserdata(JNIEnv* env, jobject object, jlong ptr, jlong size) {


//@line:1534

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) lua_newuserdata((lua_State *) L, (size_t) size);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1next(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:1596

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_next((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1pcall(JNIEnv* env, jobject object, jlong ptr, jint nargs, jint nresults, jint msgh) {


//@line:1696

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_pcall((lua_State *) L, (int) nargs, (int) nresults, (int) msgh);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1pop(JNIEnv* env, jobject object, jlong ptr, jint n) {


//@line:1722

        lua_State * L = (lua_State *) ptr;

        lua_pop((lua_State *) L, (int) n);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1pushboolean(JNIEnv* env, jobject object, jlong ptr, jint b) {


//@line:1747

        lua_State * L = (lua_State *) ptr;

        lua_pushboolean((lua_State *) L, (int) b);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1pushglobaltable(JNIEnv* env, jobject object, jlong ptr) {


//@line:1771

        lua_State * L = (lua_State *) ptr;

        lua_pushglobaltable((lua_State *) L);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1pushinteger(JNIEnv* env, jobject object, jlong ptr, jlong n) {


//@line:1796

        lua_State * L = (lua_State *) ptr;
        // What we want to achieve here is:
        // Pushing any Java number (long or double) always results in an approximated number on the stack,
        // unless the number is a Java long integer and the Lua version supports 64-bit integer,
        // when we just push an 64-bit integer instead.
        // The two cases either produce an approximated number or the exact integer value.

        // The following code ensures that no truncation can happen,
        // and the pushed number is either approximated or precise.

        // If the compiler is smart enough, it will optimize
        // the following code into a branch-less single push.
        if (sizeof(lua_Integer) == 4) {
          lua_pushnumber((lua_State *) L, (lua_Number) n);
        } else {
          lua_pushinteger((lua_State *) L, (lua_Integer) n);
        }
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1pushlightuserdata(JNIEnv* env, jobject object, jlong ptr, jlong p) {


//@line:1845

        lua_State * L = (lua_State *) ptr;

        lua_pushlightuserdata((lua_State *) L, (void *) p);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1pushnil(JNIEnv* env, jobject object, jlong ptr) {


//@line:1869

        lua_State * L = (lua_State *) ptr;

        lua_pushnil((lua_State *) L);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1pushnumber(JNIEnv* env, jobject object, jlong ptr, jdouble n) {


//@line:1894

        lua_State * L = (lua_State *) ptr;

        lua_pushnumber((lua_State *) L, (lua_Number) n);
    

}

static inline jstring wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1pushstring
(JNIEnv* env, jobject object, jlong ptr, jstring obj_s, char* s) {

//@line:1932

        lua_State * L = (lua_State *) ptr;

        const char * returnValueReceiver = (const char *) lua_pushstring((lua_State *) L, (const char *) s);
        return env->NewStringUTF(returnValueReceiver);
    
}

JNIEXPORT jstring JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1pushstring(JNIEnv* env, jobject object, jlong ptr, jstring obj_s) {
	char* s = (char*)env->GetStringUTFChars(obj_s, 0);

	jstring JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1pushstring(env, object, ptr, obj_s, s);

	env->ReleaseStringUTFChars(obj_s, s);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1pushstring(JNIEnv* env, jobject object, jlong ptr, jstring obj_s) {
	char* s = (char*)env->GetStringUTFChars(obj_s, 0);


//@line:1970

        lua_State * L = (lua_State *) ptr;

        lua_pushstring((lua_State *) L, (const char *) s);
    
	env->ReleaseStringUTFChars(obj_s, s);

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1pushthread(JNIEnv* env, jobject object, jlong ptr) {


//@line:1996

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_pushthread((lua_State *) L);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1pushvalue(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2023

        lua_State * L = (lua_State *) ptr;

        lua_pushvalue((lua_State *) L, (int) index);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1rawequal(JNIEnv* env, jobject object, jlong ptr, jint index1, jint index2) {


//@line:2054

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_rawequal((lua_State *) L, (int) index1, (int) index2);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1rawget(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2082

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_rawget((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1rawget(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2109

        lua_State * L = (lua_State *) ptr;

        lua_rawget((lua_State *) L, (int) index);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1rawgeti(JNIEnv* env, jobject object, jlong ptr, jint index, jlong n) {


//@line:2143

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_rawgeti((lua_State *) L, (int) index, (lua_Integer) n);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1rawgeti(JNIEnv* env, jobject object, jlong ptr, jint index, jint n) {


//@line:2177

        lua_State * L = (lua_State *) ptr;

        lua_rawgeti((lua_State *) L, (int) index, (lua_Integer) n);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1rawgetp(JNIEnv* env, jobject object, jlong ptr, jint index, jlong p) {


//@line:2212

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_rawgetp((lua_State *) L, (int) index, (const void *) p);
        return returnValueReceiver;
    

}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1rawlen(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2245

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) lua_rawlen((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1rawset(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2272

        lua_State * L = (lua_State *) ptr;

        lua_rawset((lua_State *) L, (int) index);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1rawseti(JNIEnv* env, jobject object, jlong ptr, jint index, jint i) {


//@line:2306

        lua_State * L = (lua_State *) ptr;

        lua_rawseti((lua_State *) L, (int) index, (lua_Integer) i);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1rawsetp(JNIEnv* env, jobject object, jlong ptr, jint index, jlong p) {


//@line:2341

        lua_State * L = (lua_State *) ptr;

        lua_rawsetp((lua_State *) L, (int) index, (const void *) p);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1remove(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2369

        lua_State * L = (lua_State *) ptr;

        lua_remove((lua_State *) L, (int) index);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1replace(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2397

        lua_State * L = (lua_State *) ptr;

        lua_replace((lua_State *) L, (int) index);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1resume(JNIEnv* env, jobject object, jlong ptr, jlong from, jint nargs) {


//@line:2460

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_resume((lua_State *) L, (lua_State *) from, (int) nargs);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1rotate(JNIEnv* env, jobject object, jlong ptr, jint idx, jint n) {


//@line:2496

        lua_State * L = (lua_State *) ptr;

        lua_rotate((lua_State *) L, (int) idx, (int) n);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1setfield(JNIEnv* env, jobject object, jlong ptr, jint index, jstring obj_k) {
	char* k = (char*)env->GetStringUTFChars(obj_k, 0);


//@line:2530

        lua_State * L = (lua_State *) ptr;

        lua_setfield((lua_State *) L, (int) index, (const char *) k);
    
	env->ReleaseStringUTFChars(obj_k, k);

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1setglobal(JNIEnv* env, jobject object, jlong ptr, jstring obj_name) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);


//@line:2556

        lua_State * L = (lua_State *) ptr;

        lua_setglobal((lua_State *) L, (const char *) name);
    
	env->ReleaseStringUTFChars(obj_name, name);

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1seti(JNIEnv* env, jobject object, jlong ptr, jint index, jlong n) {


//@line:2590

        lua_State * L = (lua_State *) ptr;

        lua_seti((lua_State *) L, (int) index, (lua_Integer) n);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1setmetatable(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2616

        lua_State * L = (lua_State *) ptr;

        lua_setmetatable((lua_State *) L, (int) index);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1setmetatable(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2642

        lua_State * L = (lua_State *) ptr;

        lua_setmetatable((lua_State *) L, (int) index);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1settable(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2676

        lua_State * L = (lua_State *) ptr;

        lua_settable((lua_State *) L, (int) index);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1settop(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2705

        lua_State * L = (lua_State *) ptr;

        lua_settop((lua_State *) L, (int) index);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1setuservalue(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2731

        lua_State * L = (lua_State *) ptr;

        lua_setuservalue((lua_State *) L, (int) index);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1status(JNIEnv* env, jobject object, jlong ptr) {


//@line:2770

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_status((lua_State *) L);
        return returnValueReceiver;
    

}

static inline jlong wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1stringtonumber
(JNIEnv* env, jobject object, jlong ptr, jstring obj_s, char* s) {

//@line:2807

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) lua_stringtonumber((lua_State *) L, (const char *) s);
        return returnValueReceiver;
    
}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1stringtonumber(JNIEnv* env, jobject object, jlong ptr, jstring obj_s) {
	char* s = (char*)env->GetStringUTFChars(obj_s, 0);

	jlong JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1stringtonumber(env, object, ptr, obj_s, s);

	env->ReleaseStringUTFChars(obj_s, s);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1toboolean(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2841

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_toboolean((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1tointeger(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2868

        lua_State * L = (lua_State *) ptr;
        // See lua_pushinteger for comments.
        if (sizeof(lua_Integer) == 4) {
          return (jlong) lua_tonumber(L, index);
        } else {
          return (jlong) lua_tointeger(L, index);
        }
    

}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1tointegerx(JNIEnv* env, jobject object, jlong ptr, jint index, jlong isnum) {


//@line:2909

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) lua_tointegerx((lua_State *) L, (int) index, (int *) isnum);
        return returnValueReceiver;
    

}

JNIEXPORT jdouble JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1tonumber(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:2936

        lua_State * L = (lua_State *) ptr;

        jdouble returnValueReceiver = (jdouble) lua_tonumber((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jdouble JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1tonumberx(JNIEnv* env, jobject object, jlong ptr, jint index, jlong isnum) {


//@line:2974

        lua_State * L = (lua_State *) ptr;

        jdouble returnValueReceiver = (jdouble) lua_tonumberx((lua_State *) L, (int) index, (int *) isnum);
        return returnValueReceiver;
    

}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1topointer(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:3010

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) lua_topointer((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jstring JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1tostring(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:3037

        lua_State * L = (lua_State *) ptr;

        const char * returnValueReceiver = (const char *) lua_tostring((lua_State *) L, (int) index);
        return env->NewStringUTF(returnValueReceiver);
    

}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1tothread(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:3067

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) lua_tothread((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1touserdata(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:3098

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) lua_touserdata((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1type(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:3138

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_type((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jstring JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1typename(JNIEnv* env, jobject object, jlong ptr, jint tp) {


//@line:3166

        lua_State * L = (lua_State *) ptr;

        const char * returnValueReceiver = (const char *) lua_typename((lua_State *) L, (int) tp);
        return env->NewStringUTF(returnValueReceiver);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1upvalueindex(JNIEnv* env, jobject object, jint i) {


//@line:3193

        jint returnValueReceiver = (jint) lua_upvalueindex((int) i);
        return returnValueReceiver;
    

}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1version(JNIEnv* env, jobject object, jlong ptr) {


//@line:3223

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) lua_version((lua_State *) L);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1xmove(JNIEnv* env, jobject object, jlong from, jlong to, jint n) {


//@line:3255

        lua_xmove((lua_State *) from, (lua_State *) to, (int) n);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1yield(JNIEnv* env, jobject object, jlong ptr, jint nresults) {


//@line:3283

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_yield((lua_State *) L, (int) nresults);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1gethookcount(JNIEnv* env, jobject object, jlong ptr) {


//@line:3309

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_gethookcount((lua_State *) L);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1gethookmask(JNIEnv* env, jobject object, jlong ptr) {


//@line:3335

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) lua_gethookmask((lua_State *) L);
        return returnValueReceiver;
    

}

JNIEXPORT jstring JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1getupvalue(JNIEnv* env, jobject object, jlong ptr, jint funcindex, jint n) {


//@line:3382

        lua_State * L = (lua_State *) ptr;

        const char * returnValueReceiver = (const char *) lua_getupvalue((lua_State *) L, (int) funcindex, (int) n);
        return env->NewStringUTF(returnValueReceiver);
    

}

JNIEXPORT jstring JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1setupvalue(JNIEnv* env, jobject object, jlong ptr, jint funcindex, jint n) {


//@line:3422

        lua_State * L = (lua_State *) ptr;

        const char * returnValueReceiver = (const char *) lua_setupvalue((lua_State *) L, (int) funcindex, (int) n);
        return env->NewStringUTF(returnValueReceiver);
    

}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1upvalueid(JNIEnv* env, jobject object, jlong ptr, jint funcindex, jint n) {


//@line:3464

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) lua_upvalueid((lua_State *) L, (int) funcindex, (int) n);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_lua_1upvaluejoin(JNIEnv* env, jobject object, jlong ptr, jint funcindex1, jint n1, jint funcindex2, jint n2) {


//@line:3495

        lua_State * L = (lua_State *) ptr;

        lua_upvaluejoin((lua_State *) L, (int) funcindex1, (int) n1, (int) funcindex2, (int) n2);
    

}

static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1callmeta
(JNIEnv* env, jobject object, jlong ptr, jint obj, jstring obj_e, char* e) {

//@line:3532

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaL_callmeta((lua_State *) L, (int) obj, (const char *) e);
        return returnValueReceiver;
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1callmeta(JNIEnv* env, jobject object, jlong ptr, jint obj, jstring obj_e) {
	char* e = (char*)env->GetStringUTFChars(obj_e, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1callmeta(env, object, ptr, obj, obj_e, e);

	env->ReleaseStringUTFChars(obj_e, e);

	return JNI_returnValue;
}

static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1dostring
(JNIEnv* env, jobject object, jlong ptr, jstring obj_str, char* str) {

//@line:3569

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaL_dostring((lua_State *) L, (const char *) str);
        return returnValueReceiver;
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1dostring(JNIEnv* env, jobject object, jlong ptr, jstring obj_str) {
	char* str = (char*)env->GetStringUTFChars(obj_str, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1dostring(env, object, ptr, obj_str, str);

	env->ReleaseStringUTFChars(obj_str, str);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1execresult(JNIEnv* env, jobject object, jlong ptr, jint stat) {


//@line:3598

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaL_execresult((lua_State *) L, (int) stat);
        return returnValueReceiver;
    

}

static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1fileresult
(JNIEnv* env, jobject object, jlong ptr, jint stat, jstring obj_fname, char* fname) {

//@line:3628

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaL_fileresult((lua_State *) L, (int) stat, (const char *) fname);
        return returnValueReceiver;
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1fileresult(JNIEnv* env, jobject object, jlong ptr, jint stat, jstring obj_fname) {
	char* fname = (char*)env->GetStringUTFChars(obj_fname, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1fileresult(env, object, ptr, stat, obj_fname, fname);

	env->ReleaseStringUTFChars(obj_fname, fname);

	return JNI_returnValue;
}

static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1getmetafield
(JNIEnv* env, jobject object, jlong ptr, jint obj, jstring obj_e, char* e) {

//@line:3660

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaL_getmetafield((lua_State *) L, (int) obj, (const char *) e);
        return returnValueReceiver;
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1getmetafield(JNIEnv* env, jobject object, jlong ptr, jint obj, jstring obj_e) {
	char* e = (char*)env->GetStringUTFChars(obj_e, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1getmetafield(env, object, ptr, obj, obj_e, e);

	env->ReleaseStringUTFChars(obj_e, e);

	return JNI_returnValue;
}

static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1getmetatable
(JNIEnv* env, jobject object, jlong ptr, jstring obj_tname, char* tname) {

//@line:3690

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaL_getmetatable((lua_State *) L, (const char *) tname);
        return returnValueReceiver;
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1getmetatable(JNIEnv* env, jobject object, jlong ptr, jstring obj_tname) {
	char* tname = (char*)env->GetStringUTFChars(obj_tname, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1getmetatable(env, object, ptr, obj_tname, tname);

	env->ReleaseStringUTFChars(obj_tname, tname);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1getmetatable(JNIEnv* env, jobject object, jlong ptr, jstring obj_tname) {
	char* tname = (char*)env->GetStringUTFChars(obj_tname, 0);


//@line:3719

        lua_State * L = (lua_State *) ptr;

        luaL_getmetatable((lua_State *) L, (const char *) tname);
    
	env->ReleaseStringUTFChars(obj_tname, tname);

}

static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1getsubtable
(JNIEnv* env, jobject object, jlong ptr, jint idx, jstring obj_fname, char* fname) {

//@line:3751

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaL_getsubtable((lua_State *) L, (int) idx, (const char *) fname);
        return returnValueReceiver;
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1getsubtable(JNIEnv* env, jobject object, jlong ptr, jint idx, jstring obj_fname) {
	char* fname = (char*)env->GetStringUTFChars(obj_fname, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1getsubtable(env, object, ptr, idx, obj_fname, fname);

	env->ReleaseStringUTFChars(obj_fname, fname);

	return JNI_returnValue;
}

static inline jstring wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1gsub
(JNIEnv* env, jobject object, jlong ptr, jstring obj_s, jstring obj_p, jstring obj_r, char* s, char* p, char* r) {

//@line:3786

        lua_State * L = (lua_State *) ptr;

        const char * returnValueReceiver = (const char *) luaL_gsub((lua_State *) L, (const char *) s, (const char *) p, (const char *) r);
        return env->NewStringUTF(returnValueReceiver);
    
}

JNIEXPORT jstring JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1gsub(JNIEnv* env, jobject object, jlong ptr, jstring obj_s, jstring obj_p, jstring obj_r) {
	char* s = (char*)env->GetStringUTFChars(obj_s, 0);
	char* p = (char*)env->GetStringUTFChars(obj_p, 0);
	char* r = (char*)env->GetStringUTFChars(obj_r, 0);

	jstring JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1gsub(env, object, ptr, obj_s, obj_p, obj_r, s, p, r);

	env->ReleaseStringUTFChars(obj_s, s);
	env->ReleaseStringUTFChars(obj_p, p);
	env->ReleaseStringUTFChars(obj_r, r);

	return JNI_returnValue;
}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1len(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:3817

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) luaL_len((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1loadstring
(JNIEnv* env, jobject object, jlong ptr, jstring obj_s, char* s) {

//@line:3855

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaL_loadstring((lua_State *) L, (const char *) s);
        return returnValueReceiver;
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1loadstring(JNIEnv* env, jobject object, jlong ptr, jstring obj_s) {
	char* s = (char*)env->GetStringUTFChars(obj_s, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1loadstring(env, object, ptr, obj_s, s);

	env->ReleaseStringUTFChars(obj_s, s);

	return JNI_returnValue;
}

static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1newmetatable
(JNIEnv* env, jobject object, jlong ptr, jstring obj_tname, char* tname) {

//@line:3894

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaL_newmetatable((lua_State *) L, (const char *) tname);
        return returnValueReceiver;
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1newmetatable(JNIEnv* env, jobject object, jlong ptr, jstring obj_tname) {
	char* tname = (char*)env->GetStringUTFChars(obj_tname, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1newmetatable(env, object, ptr, obj_tname, tname);

	env->ReleaseStringUTFChars(obj_tname, tname);

	return JNI_returnValue;
}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1newstate(JNIEnv* env, jobject object, jint lid) {


//@line:3930

        lua_State* L = luaL_newstate();
        luaJavaSetup(L, env, lid);
        return (jlong) L;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1openlibs(JNIEnv* env, jobject object, jlong ptr) {


//@line:3954

        lua_State * L = (lua_State *) ptr;

        luaL_openlibs((lua_State *) L);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1ref(JNIEnv* env, jobject object, jlong ptr, jint t) {


//@line:3998

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaL_ref((lua_State *) L, (int) t);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1setmetatable(JNIEnv* env, jobject object, jlong ptr, jstring obj_tname) {
	char* tname = (char*)env->GetStringUTFChars(obj_tname, 0);


//@line:4026

        lua_State * L = (lua_State *) ptr;

        luaL_setmetatable((lua_State *) L, (const char *) tname);
    
	env->ReleaseStringUTFChars(obj_tname, tname);

}

static inline jlong wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1testudata
(JNIEnv* env, jobject object, jlong ptr, jint arg, jstring obj_tname, char* tname) {

//@line:4055

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) luaL_testudata((lua_State *) L, (int) arg, (const char *) tname);
        return returnValueReceiver;
    
}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1testudata(JNIEnv* env, jobject object, jlong ptr, jint arg, jstring obj_tname) {
	char* tname = (char*)env->GetStringUTFChars(obj_tname, 0);

	jlong JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1testudata(env, object, ptr, arg, obj_tname, tname);

	env->ReleaseStringUTFChars(obj_tname, tname);

	return JNI_returnValue;
}

JNIEXPORT jstring JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1tolstring(JNIEnv* env, jobject object, jlong ptr, jint idx, jlong len) {


//@line:4095

        lua_State * L = (lua_State *) ptr;

        const char * returnValueReceiver = (const char *) luaL_tolstring((lua_State *) L, (int) idx, (size_t *) len);
        return env->NewStringUTF(returnValueReceiver);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1traceback(JNIEnv* env, jobject object, jlong ptr, jlong L1, jstring obj_msg, jint level) {
	char* msg = (char*)env->GetStringUTFChars(obj_msg, 0);


//@line:4128

        lua_State * L = (lua_State *) ptr;

        luaL_traceback((lua_State *) L, (lua_State *) L1, (const char *) msg, (int) level);
    
	env->ReleaseStringUTFChars(obj_msg, msg);

}

JNIEXPORT jstring JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1typename(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:4154

        lua_State * L = (lua_State *) ptr;

        const char * returnValueReceiver = (const char *) luaL_typename((lua_State *) L, (int) index);
        return env->NewStringUTF(returnValueReceiver);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1unref(JNIEnv* env, jobject object, jlong ptr, jint t, jint ref) {


//@line:4190

        lua_State * L = (lua_State *) ptr;

        luaL_unref((lua_State *) L, (int) t, (int) ref);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaL_1where(JNIEnv* env, jobject object, jlong ptr, jint lvl) {


//@line:4231

        lua_State * L = (lua_State *) ptr;

        luaL_where((lua_State *) L, (int) lvl);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1openlib(JNIEnv* env, jobject object, jlong ptr, jstring obj_lib) {
	char* lib = (char*)env->GetStringUTFChars(obj_lib, 0);


//@line:4248

        lua_State * L = (lua_State *) ptr;

        luaJ_openlib((lua_State *) L, (const char *) lib);
    
	env->ReleaseStringUTFChars(obj_lib, lib);

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1compare(JNIEnv* env, jobject object, jlong ptr, jint index1, jint index2, jint op) {


//@line:4268

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaJ_compare((lua_State *) L, (int) index1, (int) index2, (int) op);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1len(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:4287

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaJ_len((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1loadbuffer
(JNIEnv* env, jobject object, jlong ptr, jobject obj_buffer, jint size, jstring obj_name, unsigned char* buffer, char* name) {

//@line:4308

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaJ_loadbuffer((lua_State *) L, (unsigned char *) buffer, (int) size, (const char *) name);
        return returnValueReceiver;
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1loadbuffer(JNIEnv* env, jobject object, jlong ptr, jobject obj_buffer, jint size, jstring obj_name) {
	unsigned char* buffer = (unsigned char*)(obj_buffer?env->GetDirectBufferAddress(obj_buffer):0);
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1loadbuffer(env, object, ptr, obj_buffer, size, obj_name, buffer, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1dobuffer
(JNIEnv* env, jobject object, jlong ptr, jobject obj_buffer, jint size, jstring obj_name, unsigned char* buffer, char* name) {

//@line:4329

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaJ_dobuffer((lua_State *) L, (unsigned char *) buffer, (int) size, (const char *) name);
        return returnValueReceiver;
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1dobuffer(JNIEnv* env, jobject object, jlong ptr, jobject obj_buffer, jint size, jstring obj_name) {
	unsigned char* buffer = (unsigned char*)(obj_buffer?env->GetDirectBufferAddress(obj_buffer):0);
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1dobuffer(env, object, ptr, obj_buffer, size, obj_name, buffer, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1resume(JNIEnv* env, jobject object, jlong ptr, jint nargs) {


//@line:4348

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaJ_resume((lua_State *) L, (int) nargs);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1pushobject(JNIEnv* env, jobject object, jlong ptr, jobject obj) {


//@line:4366

        lua_State * L = (lua_State *) ptr;

        luaJ_pushobject((JNIEnv *) env, (lua_State *) L, (jobject) obj);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1pushclass(JNIEnv* env, jobject object, jlong ptr, jobject clazz) {


//@line:4383

        lua_State * L = (lua_State *) ptr;

        luaJ_pushclass((JNIEnv *) env, (lua_State *) L, (jobject) clazz);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1pusharray(JNIEnv* env, jobject object, jlong ptr, jobject array) {


//@line:4400

        lua_State * L = (lua_State *) ptr;

        luaJ_pusharray((JNIEnv *) env, (lua_State *) L, (jobject) array);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1pushfunction(JNIEnv* env, jobject object, jlong ptr, jobject func) {


//@line:4417

        lua_State * L = (lua_State *) ptr;

        luaJ_pushfunction((JNIEnv *) env, (lua_State *) L, (jobject) func);
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1isobject(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:4435

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaJ_isobject((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jobject JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1toobject(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:4454

        lua_State * L = (lua_State *) ptr;

        jobject returnValueReceiver = (jobject) luaJ_toobject((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jlong JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1newthread(JNIEnv* env, jobject object, jlong ptr, jint lid) {


//@line:4473

        lua_State * L = (lua_State *) ptr;

        jlong returnValueReceiver = (jlong) luaJ_newthread((lua_State *) L, (int) lid);
        return returnValueReceiver;
    

}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1initloader(JNIEnv* env, jobject object, jlong ptr) {


//@line:4491

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaJ_initloader((lua_State *) L);
        return returnValueReceiver;
    

}

static inline jint wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1invokespecial
(JNIEnv* env, jobject object, jlong ptr, jclass clazz, jstring obj_method, jstring obj_sig, jobject obj, jstring obj_params, char* method, char* sig, char* params) {

//@line:4515

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaJ_invokespecial((JNIEnv *) env, (lua_State *) L, (jclass) clazz, (const char *) method, (const char *) sig, (jobject) obj, (const char *) params);
        return returnValueReceiver;
    
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1invokespecial(JNIEnv* env, jobject object, jlong ptr, jclass clazz, jstring obj_method, jstring obj_sig, jobject obj, jstring obj_params) {
	char* method = (char*)env->GetStringUTFChars(obj_method, 0);
	char* sig = (char*)env->GetStringUTFChars(obj_sig, 0);
	char* params = (char*)env->GetStringUTFChars(obj_params, 0);

	jint JNI_returnValue = wrapped_Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1invokespecial(env, object, ptr, clazz, obj_method, obj_sig, obj, obj_params, method, sig, params);

	env->ReleaseStringUTFChars(obj_method, method);
	env->ReleaseStringUTFChars(obj_sig, sig);
	env->ReleaseStringUTFChars(obj_params, params);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1isinteger(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:4534

        lua_State * L = (lua_State *) ptr;

        jint returnValueReceiver = (jint) luaJ_isinteger((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1removestateindex(JNIEnv* env, jobject object, jlong ptr) {


//@line:4551

        lua_State * L = (lua_State *) ptr;

        luaJ_removestateindex((lua_State *) L);
    

}

JNIEXPORT void JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1gc(JNIEnv* env, jobject object, jlong ptr) {


//@line:4567

        lua_State * L = (lua_State *) ptr;

        luaJ_gc((lua_State *) L);
    

}

JNIEXPORT jobject JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1dumptobuffer(JNIEnv* env, jobject object, jlong ptr) {


//@line:4584

        lua_State * L = (lua_State *) ptr;

        jobject returnValueReceiver = (jobject) luaJ_dumptobuffer((lua_State *) L);
        return returnValueReceiver;
    

}

JNIEXPORT jobject JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1tobuffer(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:4603

        lua_State * L = (lua_State *) ptr;

        jobject returnValueReceiver = (jobject) luaJ_tobuffer((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

JNIEXPORT jobject JNICALL Java_party_iroiro_luajava_lua53_Lua53Natives_luaJ_1todirectbuffer(JNIEnv* env, jobject object, jlong ptr, jint index) {


//@line:4622

        lua_State * L = (lua_State *) ptr;

        jobject returnValueReceiver = (jobject) luaJ_todirectbuffer((lua_State *) L, (int) index);
        return returnValueReceiver;
    

}

