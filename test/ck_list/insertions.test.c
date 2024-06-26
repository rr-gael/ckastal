#include <assert.h>
#include <stdlib.h>

#include "../../lib/ck_list.c"
#include "../../package/clogg/src/clogg.c"

Ckastal_Memory ckastal_memory = {
    .alloc = malloc,
    .free = free,
};

int main(void) {
    Ckastal_List list = ck_list_new(NULL, CK_LIST_LINEAR);

    for (int i = 1; i <= 100; i++) {
        ck_list_push(&list, (void*)i);
        ck_list_unshift(&list, (void*)i);

        assert(list.length == i * 2);
        assert(((int)list.tail->data) == i);
        assert(((int)list.head->data) == i);
    }

    cloggln(CLOGG_INFO, "All tests passed");

    return 0;
}