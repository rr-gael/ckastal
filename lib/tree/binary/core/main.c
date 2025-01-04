#ifndef __CKASTAL_BITREE_CORE_MAIN__
#define __CKASTAL_BITREE_CORE_MAIN__

#include "../../../../include/core/data.h"
#include "../../../../include/core/init.c"

typedef struct Ck_BitreeNode {
    Ck_Data data;
    struct Ck_BitreeNode* left;
    struct Ck_BitreeNode* right;
} Ck_BitreeNode;

typedef struct Ck_Bitree {
    size_t size;
    Ck_BitreeNode* root;

    Ck_DataType* type;
} Ck_Bitree;

typedef enum Ck_Bitree_TraverseMode {
    CKASTAL_BITREE_TRAVERSE_BREADTH = 0,
    CKASTAL_BITREE_TRAVERSE_DEPTH = 0,
} Ck_Bitree_TraverseMode;

#endif /** __CKASTAL_BITREE_CORE_MAIN__ */
