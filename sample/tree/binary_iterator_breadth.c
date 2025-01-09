#include <stdio.h>
#include <stdlib.h>

#include "../../lib/provider/queue/simple/index.c"
#include "../../lib/provider/tree/binary/index.c"

#define deref(ptr, type) (*(type *)(ptr))
#define cast(type, void_ptr) ((type *)(void_ptr))

Ck_DataTypeCompareResult compare(void *a, void *b) {
    int l = deref(a, int);
    int r = deref(b, int);

    if (l < r) {
        return CK_LT;
    }
    if (l > r) {
        return CK_GT;
    }
    return CK_EQ;
}

Ck_DataType integer = {
    .size = sizeof(int),
    .to_str = NULL,
    .compare = compare,
};

int main(void) {
    Ck_Treebi tree = ck_treebi_new(&integer);

    int integers[10] = {1, 1, 1, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        ck_treebi_insert(&tree, &integers[i]);
    }

    Ck_Queue queue = ck_queue_new(&integer);
    Ck_Iterator iterator = ck_treebi_iterator_breadth(&tree, &queue);

    Ck_TreebiNode *node = NULL;
    while ((node = iterator.next(&iterator))) {
        printf("Tree Node %zu: %d\n", iterator._index, deref(node->data, int));
    }

    return 0;
}
