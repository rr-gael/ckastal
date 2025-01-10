#include <stdio.h>
#include <stdlib.h>

#include "../../include/syntax_utils.h"
#include "../../lib/provider/queue/simple/index.c"
#include "../../lib/provider/tree/binary/index.c"

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
    Ck_Treebi tree = ck_treebi_init_with_int(&integer, 1, 10, 1);
    Ck_Queue queue = ck_queue_init(&integer);
    Ck_Iterator iterator = ck_treebi_iterator_breadth(&tree, &queue);

    ck_foreach(Ck_TreebiNode *, node, iterator) {
        printf("Tree Node %zu: %d\n", iterator._index, deref(node->data, int));
    }

    return 0;
}
