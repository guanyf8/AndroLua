//
// Created by guan on 2025/3/13.
//

#ifndef PARALLELLJ_SCHEDULER_H
#define PARALLELLJ_SCHEDULER_H

#include <bits/stdatomic.h>

typedef struct Threadwarp{
    int parent;
    int* threads;
    atomic_int alive;

} threadwarp;

#endif //PARALLELLJ_SCHEDULER_H
