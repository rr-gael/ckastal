#include <stdio.h>
#include <stdlib.h>

#include "../lib/ck_list.c"
#include "../vendor/clogg/src/clogg.c"

Ckastal_Memory ckastal_memory = {
    .alloc = malloc,
    .free = free,
};

int main(int argc, char **argv) {
    Ckastal_List list = ck_list_new(NULL, CK_LIST_LINEAR);

    ck_list_push(&list, "");

    clogg(CLOGG_INFO, "Testing list");

    return 0;
}