LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
 
LOCAL_MODULE    := lua53JNI
LOCAL_C_INCLUDES := ../../jni/luajava ../../jni/mod ../../jni/lua53 
 
LOCAL_CFLAGS := $(LOCAL_C_INCLUDES:%=-I%) -O2 -Wall -D__ANDROID__ -DLUA_COMPAT_5_2 -D_FORTIFY_SOURCE=1 -DLUA_USE_DLOPEN 
LOCAL_CPPFLAGS := $(LOCAL_C_INCLUDES:%=-I%) -O2 -Wall -D__ANDROID__ -DLUA_COMPAT_5_2 -D_FORTIFY_SOURCE=1 -DLUA_USE_DLOPEN 
LOCAL_LDLIBS := -lm -Wl,-z,max-page-size=0x4000
LOCAL_ARM_MODE  := arm
 
LOCAL_SRC_FILES :=  $(wildcard *.c) $(wildcard *.cpp)
include $(BUILD_SHARED_LIBRARY)
