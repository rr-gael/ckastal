#include <stdio.h>
#include <stdlib.h>

#include "../../include/syntax_utils.h"
#include "../../lib/provider/list/single/index.c"

Ck_DataType integer = {
    .size = sizeof(int),
    .to_str = NULL,
};

int main(void) {
    Ck_List list = ck_list_init(&integer, CK_LIST_LINEAR);
    Ck_Iterator iterator = ck_list_iterator(&list);

    int integers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++) {
        ck_list_push(&list, &integers[i]);
    }

    Ck_ListNode *current = NULL;

    while ((current = iterator.next(&iterator))) {
        printf("integers[%zu] = %d\n", iterator._index, deref(current->data, int));
    }

    return 0;
}