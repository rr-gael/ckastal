#include "../../include/linkedlist_single.h"

CK_LinkedList ck_linkedlist_new(CK_Data data) {
    CK_LinkedList list = {
        .data = data,
        .length = 0,

        .head = NULL,
        .tail = NULL,
    };

    return list;
}

CK_LLNode *ck_linkedlist_node_new(CK_DataRef data) {
    CK_LLNode *node = calloc(1, sizeof(CK_LLNode));
    *node = (CK_LLNode){data, NULL};
    return node;
}
