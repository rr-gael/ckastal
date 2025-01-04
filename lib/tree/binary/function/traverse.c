#ifndef __CKASTAL_BITREE_FOR_EACH__
#define __CKASTAL_BITREE_FOR_EACH__

#include "../../../queue/simple/index.c"
#include "../core/main.c"

void ck_bitree_traverse(Ck_Bitree *tree, Ck_Bitree_TraverseMode mode, Ck_IteratorCallback callback, void *ctx) {
    switch (mode) {
        case CKASTAL_BITREE_TRAVERSE_BREADTH:
            _ck_bitree_traverse_breadth(tree, mode, callback, ctx);
            break;
        default:
            break;
    }
}

void _ck_bitree_traverse_breadth(
    Ck_Bitree *tree,
    Ck_Bitree_TraverseMode mode,
    Ck_IteratorCallback callback,
    void *ctx) {
    if (tree->size == 0) {
        return;
    }

    Ck_Queue queue = ck_queue_new(tree->type);

    ck_queue_enqueue(&queue, tree->root);

    bool is_empty = ck_queue_size(&queue) == 0;

    while (!is_empty) {
        Ck_BitreeNode *node = ck_queue_dequeue(&queue);
        Ck_IteratorResult result = callback(node->data, ctx);

        if (result == CK_ITERATOR_STOP) {
            break;
        }

        if (node->left) {
            ck_queue_enqueue(&queue, node->left);
        }
        if (node->right) {
            ck_queue_enqueue(&queue, node->right);
        }

        ck_memory.free(node);

        is_empty = ck_queue_size(&queue) == 0;
    }

    ck_queue_free(&queue);
}

#endif /** __CKASTAL_BITREE_FOR_EACH__ */
