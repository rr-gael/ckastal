#ifndef __CK_ARRAYLIST_H__

#define __CK_ARRAYLIST_H__

#include "util/data.h"
#include "util/mem.h"

#define CK_ARRAYLIST_EXPANSION_FACTOR 1.5

typedef enum CK_ArrayList_AccessMode {
    CK_ARRAYLIST_ACCESS_BEFORE_LEN,
    CK_ARRAYLIST_ACCESS_BEFORE_CAP,
} CK_ArrayList_AccessMode;

typedef struct CK_ArrayList {
    size_t _length;
    size_t _current_capacity;

    CK_ArrayList_AccessMode access_mode;

    CK_Data _data;
    void **_elements;
} CK_ArrayList;

CK_ArrayList ck_arraylist_new(size_t initial_capacity, CK_ArrayList_AccessMode access_mode, CK_Data data);

void ck_arraylist_push(CK_ArrayList *al, void *data);

void *ck_arraylist_set(CK_ArrayList *al, size_t i, void *data);
void *ck_arraylist_get(CK_ArrayList *al, size_t i);

#endif  // !__CK_ARRAYLIST_H__
