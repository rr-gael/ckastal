#include <stdio.h>
#include <stdlib.h>

#include "../../lib/provider/list/single/index.c"
#include "../../vendor/clogg/src/clogg.c"

int main(int argc, char **argv) {
    Ck_List list = ck_list_init(NULL, CK_LIST_LINEAR);

    ck_list_push(&list, "");

    clogg(CLOGG_INFO, "Testing list");

    return 0;
}