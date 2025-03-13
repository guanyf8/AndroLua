//
// Created by guan on 2025/3/11.
//

#ifndef PARALLELLJ_MAP_H
#define PARALLELLJ_MAP_H

#include <string.h>
#include "pthread.h"
#include "rbtree.h"
#include "stdlib.h"

struct map {
    struct rb_node rb_node;  // 必须作为第一个成员
    const char* key;                // 键（示例用 int）
    void *value;            // 值（泛型指针）
};

struct rb_root map_init(void);

typedef struct rb_root Map;


// 插入键值对
int map_insert(struct rb_root *root, const char* key, void *value) ;

// 查找键值对
void *map_find(struct rb_root *root, const char* key);
// 删除键值对
void map_erase(struct rb_root *root, const char* key) ;

void map_free(struct rb_root *root);

#endif //PARALLELLJ_MAP_H
