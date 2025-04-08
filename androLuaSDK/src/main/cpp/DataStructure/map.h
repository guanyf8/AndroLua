//
// Created by guan on 2025/3/11.
//

#ifndef PARALLELLJ_MAP_H
#define PARALLELLJ_MAP_H

#include <string.h>
#include "pthread.h"
#include "rbtree.h"
#include "stdlib.h"

union key_type {
    int num;
    const char* str;
};

typedef struct map_node {
    struct rb_node rb_node;
    union key_type key;
    void *value;
} map_node;

typedef struct {
    struct rb_root root;
    int (*cmp)(union key_type key1,union key_type key2);
} tree_map;

typedef tree_map map;

extern int mystrcmp(union key_type a, union key_type b);
extern int numcmp(union key_type a, union key_type b);

tree_map* map_init(int (*cmp)(union key_type a,union key_type b));
// 插入键值对
int map_insert(tree_map* treemap, struct map_node* node) ;

// 查找键值对
void *map_get(tree_map* treemap, union key_type key);

map_node *map_search(tree_map* treemap, union key_type key);

// 删除键值对
void map_erase(tree_map* treemap, union key_type key) ;

void map_free(tree_map* treemap);

#endif //PARALLELLJ_MAP_H
