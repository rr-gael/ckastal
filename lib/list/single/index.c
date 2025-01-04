#ifndef __CKASTAL_LIST_SINGLE__
#define __CKASTAL_LIST_SINGLE__

#include "../../../include/core/data.h"
#include "../../../include/core/init.c"

typedef enum Ck_ListMode {
    CK_LIST_LINEAR = 0,
    CK_LIST_CIRCULAR,
} Ck_ListMode;

typedef struct Ck_ListNode {
    Ck_Data data;
    struct Ck_ListNode* next;
} Ck_ListNode;

typedef struct Ck_List {
    size_t length;

    Ck_ListMode mode;

    Ck_ListNode* head;
    Ck_ListNode* tail;

    Ck_DataType* type;
} Ck_List;

/**
 * Utility functions.
 */

/**
 * @brief Creates a new node.
 *
 * @param data The pointer to store as the data address.
 * @return Ck_ListNode*
 */
Ck_ListNode* _ck_list_node_new(void* data) {
    Ck_ListNode* node = ck_memory.alloc(sizeof(Ck_ListNode));

    node->data = data;
    node->next = NULL;

    return node;
}
void _ck_list_push_head(Ck_List* list, Ck_ListNode* node) {
    list->head = node;
    list->tail = list->head;

    if (list->mode == CK_LIST_CIRCULAR) {
        list->head->next = list->tail;
        list->tail->next = list->head;
    }

    list->length += 1;
}

Ck_List ck_list_new(Ck_DataType* type, Ck_ListMode mode) {
    Ck_List list = {
        .type = type,
        .head = NULL,
        .tail = NULL,
        .length = 0,
        .mode = mode,
    };

    return list;
}

void ck_list_push(Ck_List* list, void* data) {
    Ck_ListNode* node = _ck_list_node_new(data);

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

void ck_list_unshift(Ck_List* list, void* data) {
    Ck_ListNode* node = _ck_list_node_new(data);

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

#endif /* __CKASTAL_LIST_SINGLE__ */