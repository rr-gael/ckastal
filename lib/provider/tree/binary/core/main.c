#ifndef __CKASTAL_TREEBI_CORE_MAIN__
#define __CKASTAL_TREEBI_CORE_MAIN__

#include "../../../../core/data.c"
#include "../../../../core/init.c"

typedef struct Ck_TreebiNode {
    Ck_Data data;
    struct Ck_TreebiNode* left;
    struct Ck_TreebiNode* right;
} Ck_TreebiNode;

typedef struct Ck_Treebi {
    size_t _size;
    Ck_TreebiNode* _root;

    Ck_DataType* _type;
} Ck_Treebi;

Ck_TreebiNode _ck_treebi_node_new(Ck_Data data) {
    Ck_TreebiNode node = {
        .data = data,
        .left = NULL,
        .right = NULL,
    };

    return node;
}

Ck_Treebi ck_treebi_new(Ck_DataType* type) {
    Ck_Treebi tree = {
        ._root = NULL,
        ._size = 0,
        ._type = type,
    };

    return tree;
}

void ck_treebi_insert(Ck_Treebi* self, Ck_Data data) {
    if (NULL == self->_root) {
        Ck_TreebiNode* node = ck_memory.alloc(sizeof(Ck_TreebiNode));
        *node = _ck_treebi_node_new(data);

        self->_root = node;

        return;
    }

    Ck_TreebiNode* current = self->_root;

    while (current) {
        Ck_TreebiNode* next = NULL;
        Ck_DataTypeCompareResult comparison = self->_type->compare(current->data, data);

        if (comparison == CK_LT || comparison == CK_EQ) {
            next = current->left;
        } else {
            next = current->right;
        }

        if (next) {
            current = next;
            continue;
        }

        Ck_TreebiNode* node = ck_memory.alloc(sizeof(Ck_TreebiNode));
        *node = _ck_treebi_node_new(data);

        if (comparison == CK_LT || comparison == CK_EQ) {
            current->left = node;
        } else {
            current->right = node;
        }

        self->_size += 1;

        break;
    }
}

#endif /** __CKASTAL_TREEBI_CORE_MAIN__ */
