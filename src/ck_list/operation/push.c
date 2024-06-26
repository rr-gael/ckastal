#ifndef __CKASTAL_LIST_OPERATION_PUSH_C__
#define __CKASTAL_LIST_OPERATION_PUSH_C__

#include "../model.h"
#include "node_new.c"

Ckastal_ListNode* ck_list_push(Ckastal_List* list, void* data) {
    Ckastal_ListNode* node = ck_list_node_new(data);

    if (!list->head) {
        list->head = node;
        list->tail = list->head;
        return;
    }

    if (list->head != list->tail) {
        node->next = list->tail;
        list->tail = node;
        return;
    }
}

#endif /** __CKASTAL_LIST_OPERATION_PUSH_C__ */
