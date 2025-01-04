#ifndef __CKASTAL_CORE_DATA_H__
#define __CKASTAL_CORE_DATA_H__

#include "init.c"

#define Ck_Data void*

typedef void (*Ck_DataTypeToStr)(void*);

typedef enum Ck_IteratorResult {
    CK_ITERATOR_CONTINUE = 0,
    CK_ITERATOR_STOP,
} Ck_IteratorResult;

typedef Ck_IteratorResult (*Ck_IteratorCallback)(Ck_Data data, void* ctx);

typedef struct {
    size_t size;
    Ck_DataTypeToStr to_str;
} Ck_DataType;

#endif /* __CKASTAL_CORE_DATA_H__ */
