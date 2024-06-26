#ifndef __CKASTAL_LIST_C__
#define __CKASTAL_LIST_C__

#include "../include/util/memory.h"
#include "../include/util/std.h"
#include "../include/util/unit.h"

typedef enum Ckastal_ListMode {
    CK_LIST_LINEAR = 0,
    CK_LIST_CIRCULAR,
} Ckastal_ListMode;

typedef struct Ckastal_ListNode {
    void* data;
    struct Ckastal_ListNode* next;
} Ckastal_ListNode;

typedef struct Ckastal_List {
    size_t length;

    Ckastal_ListMode mode;

    Ckastal_ListNode* head;
    Ckastal_ListNode* tail;

    Ckastal_Unit* unit;
} Ckastal_List;

/**
 * Utility functions.
 */

/**
 * @brief Creates a new node.
 *
 * @param data The pointer to store as the data address.
 * @return Ckastal_ListNode*
 */
Ckastal_ListNode* _ck_list_node_new(void* data) {
    Ckastal_ListNode* node = ckastal_memory.alloc(sizeof(Ckastal_ListNode));

    node->data = data;
    node->next = NULL;

    return node;
}
void _ck_list_push_head(Ckastal_List* list, Ckastal_ListNode* node) {
    list->head = node;
    list->tail = list->head;

    if (list->mode == CK_LIST_CIRCULAR) {
        list->head->next = list->tail;
        list->tail->next = list->head;
    }

    list->length += 1;
}

Ckastal_List ck_list_new(Ckastal_Unit* unit, Ckastal_ListMode mode) {
    Ckastal_List list = {
        .unit = unit,
        .head = NULL,
        .tail = NULL,
        .length = 0,
        .mode = mode,
    };

    return list;
}

void ck_list_push(Ckastal_List* list, void* data) {
    Ckastal_ListNode* node = _ck_list_node_new(data);

    if (!list->head) {
        _ck_list_push_head(list, node);
        return;
    }

    list->tail->next = node;
    list->tail = node;

    if (list->mode == CK_LIST_CIRCULAR) {
        list->tail->next = list->head;
    }

    list->length += 1;
}

void ck_list_unshift(Ckastal_List* list, void* data) {
    Ckastal_ListNode* node = _ck_list_node_new(data);

    if (!list->head) {
        _ck_list_push_head(list, node);
        return;
    }

    node->next = list->head;
    list->head = node;

    if (list->mode == CK_LIST_CIRCULAR) {
        list->tail->next = list->head;
    }

    list->length += 1;
}

#endif /* __CKASTAL_LIST_C__ */