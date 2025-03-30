//
// Created by guan on 2025/3/3.
//

#ifndef PARALLELLJ_JNINFO_H
#define PARALLELLJ_JNINFO_H

#include <jni.h>


#define new(type) (type*)malloc(sizeof(type))
//extern JNIEnv* SDKEnv;
extern JavaVM *jvm;

#endif //PARALLELLJ_JNINFO_H
