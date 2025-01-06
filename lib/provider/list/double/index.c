#ifndef __CKASTAL_LIST_DOUBLE__
#define __CKASTAL_LIST_DOUBLE__

#include "../../../core/data.c"
#include "../../../core/init.c"

typedef struct Ck_BilistNode {
    Ck_Data data;
    Ck_BilistNode *next;
    Ck_BilistNode *prev;
} Ck_BilistNode;

typedef struct Ck_Bilist {
    size_t length;

    bool is_circular;

    Ck_BilistNode *head;
    Ck_BilistNode *tail;
} Ck_Bilist;

#endif /** __CKASTAL_LIST_DOUBLE__ */
