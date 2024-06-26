#include <stdio.h>

#include "../lib/ck_list.h"
#include "../package/clogg/include/clogg.h"

int main(int argc, char **argv) {
    Ckastal_List list = {
        .length = 0,
        .is_circular = false,
        .head = NULL,
        .tail = NULL,
    };

    ck_list_push(&list, "");

    clogg(CLOGG_INFO, "Testing list");

    return 0;
}