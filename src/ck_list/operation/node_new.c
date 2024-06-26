#ifndef __CKASTAL_LIST_OPERATION_NEW_NODE_C__
#define __CKASTAL_LIST_OPERATION_NEW_NODE_C__

#include "../../util/memory.h"
#include "../model.h"

Ckastal_ListNode *ck_list_node_new(void *data) {
    Ckastal_ListNode *node = ckastal_memory.alloc(sizeof(Ckastal_ListNode));

    node->data = data;
    node->next = NULL;

    return node;
}

#endif