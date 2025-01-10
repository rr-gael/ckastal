#include "../core/main.c"

Ck_Treebi ck_treebi_init_with_int(Ck_DataType* type, int from, int to, int step) {
    Ck_Treebi tree = ck_treebi_init(type);

    for (int i = from; i <= to; i += step) {
        int* iptr = ck_memory.alloc(sizeof(i));
        *iptr = i;
        ck_treebi_insert(&tree, iptr);
    }

    return tree;
}

Ck_Treebi* ck_treebi_fill_with_int(Ck_Treebi* tree, int from, int to, int step) {
    for (int i = from; i <= to; i += step) {
        int* iptr = ck_memory.alloc(sizeof(i));
        *iptr = i;
        ck_treebi_insert(tree, iptr);
    }

    return tree;
}
