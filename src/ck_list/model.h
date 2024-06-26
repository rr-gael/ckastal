#ifndef __CKASTAL_LIST_MODEL_H__
#define __CKASTAL_LIST_MODEL_H__

#include "../util/std.h"

#ifndef size_t
#include <stdlib.h>
#endif

typedef struct Ckastal_ListNode {
    void *data;
    Ckastal_ListNode *next;
} Ckastal_ListNode;

typedef struct Ckastal_List {
    size_t length;

    bool is_circular;

    Ckastal_ListNode *head;
    Ckastal_ListNode *tail;
} Ckastal_List;

#endif /** __CKASTAL_LIST_MODEL_H__ */
