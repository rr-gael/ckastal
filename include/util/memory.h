#ifndef __CKASTAL_UTIL_MEMORY_H__
#define __CKASTAL_UTIL_MEMORY_H__

typedef void* (*Ckastal_AllocOperation)(size_t);
typedef void (*Ckastal_FreeOperation)(void*);

typedef struct Ckastal_Memory {
    Ckastal_AllocOperation alloc;
    Ckastal_FreeOperation free;
} Ckastal_Memory;

extern Ckastal_Memory ckastal_memory;

#endif /* __CKASTAL_UTIL_MEMORY_H__ */
