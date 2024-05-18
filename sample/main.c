#include <stdio.h>

#include "../include/heap.h"

void int_print(void *data) {
    printf("%d", *(int *)data);
}

short int_compare(void *a, void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main(int argc, char **argv) {
    Heap heap = heap_new(
        HEAP_TYPE_MAX,
        HEAP_CAPACITY_DYNAMIC,
        HEAP_DELETE_RETURN_REFERENCE,
        HEAP_STORE_COPY,
        10,
        (HeapData){
            ._unit_size = sizeof(int),
            .print = int_print,
            .compare = int_compare,
            /** Don't update int elements */
            .index_update = NULL,
        }

    );

    printf("--- CKASTAL HEAP SAMPLE ---\n\n");
    printf("[INFO]: Inserting 5 integers on heap:\n");

    for (int i = 1; i <= 5; i++) {
        heap_insert(&heap, &i);
    }

    printf("[INFO]: Current heap: ");
    heap_print(&heap);

    heap_delete_all(&heap);
    printf("[INFO]: Deleted heap.\n");

    printf("\n[BYE]: See you in space cowboy!\n");

    return 0;
}