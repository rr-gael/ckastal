#ifndef __CKASTAL_BILIST_C__
#define __CKASTAL_BILIST_C__

#include "../include/core/std.h"

typedef struct Ckastal_BilistNode {
    void *data;
    Ckastal_BilistNode *next;
    Ckastal_BilistNode *prev;
} Ckastal_BilistNode;

typedef struct Ckastal_Bilist {
    size_t length;

    bool is_circular;

    Ckastal_BilistNode *head;
    Ckastal_BilistNode *tail;
} Ckastal_Bilist;

#endif /** __CKASTAL_BILIST_C__ */
