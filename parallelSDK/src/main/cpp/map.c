//
// Created by guan on 2025/3/11.
//

#include "map.h"

struct rb_root map_init(void){
    return RB_ROOT;
}

int map_insert(struct rb_root *root, const char* key, void *value) {
    struct rb_node **_new = &(root->rb_node);
    struct rb_node *parent = NULL;
    struct map *node;

    // 查找插入位置
    while (*_new) {
        struct map *_this = rb_entry(*_new, struct map, rb_node);
        parent = *_new;

        if (strcmp(key,_this->key)<0)
            _new = &((*_new)->rb_left);
        else if (strcmp(key,_this->key)>0)
            _new = &((*_new)->rb_right);
        else
            return -1; // 键已存在
    }

    // 创建新节点
    node = (struct map*) malloc(sizeof(struct map));
    node->key = key;
    node->value = value;

    // 链接节点
    rb_link_node(&node->rb_node, parent, _new);
    rb_insert_color(&node->rb_node, root);

    return 0;
}

// 查找键值对
void *map_find(struct rb_root *root, const char* key) {
    struct rb_node *node = root->rb_node;

    while (node) {
        struct map *_this = rb_entry(node, struct map, rb_node);

        if (strcmp(key,_this->key)<0)
            node = node->rb_left;
        else if (strcmp(key,_this->key)>0)
            node = node->rb_right;
        else
            return _this->value;
    }
    return NULL;
}

// 删除键值对
void map_erase(struct rb_root *root, const char* key) {
    struct rb_node *node = root->rb_node;

    while (node) {
        struct map *_this = rb_entry(node, struct map, rb_node);

        if (strcmp(key,_this->key)<0)
            node = node->rb_left;
        else if (strcmp(key,_this->key)>0)
            node = node->rb_right;
        else {
            rb_erase(node, root);
            free(_this);
            break;
        }
    }
}

static void _map_node_free(struct rb_node* node){
    if(node->rb_left){
        _map_node_free(node->rb_left);
    }
    if(node->rb_right){
        _map_node_free(node->rb_right);
    }
    struct map* map_node= rb_entry(node,struct map,rb_node);
    free(map_node->value);
    free((void*)map_node->key);
    free(map_node);
}

void map_free(struct rb_root* root){
    _map_node_free(root->rb_node);
}
