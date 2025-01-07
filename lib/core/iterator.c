#ifndef __CKASTAL_CORE_ITERATOR__
#define __CKASTAL_CORE_ITERATOR__

typedef struct Ck_Iterator Ck_Iterator;

typedef void *(*Ck_IteratorNext)(Ck_Iterator *self);

typedef struct Ck_Iterator {
    void *_collection;

    void *_cursor;
    size_t _index;

    void *_ctx;

    Ck_IteratorNext next;
} Ck_Iterator;

#endif /** __CKASTAL_CORE_ITERATOR__ */