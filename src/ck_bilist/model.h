#ifndef __CKASTAL_BILIST_MODEL_H__
#define __CKASTAL_BILIST_MODEL_H__

#include "../util/std.h"

#ifndef size_t
#include <stdlib.h>
#endif

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

#endif /** __CKASTAL_BILIST_MODEL_H__ */
