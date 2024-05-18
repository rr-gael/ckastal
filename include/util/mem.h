#ifndef __CK_ALLOC_H__

#define __CK_ALLOC_H__

#ifndef NULL

#define NULL (void *)0

#endif  // !NULL

typedef size_t;

void *malloc(size_t size);
void *calloc(size_t count, size_t size);
void *realloc(void *src, size_t size);
void free(void *ptr);

void *memset(void *dest, int value, size_t size);
void *memcpy(void *dest, const void *src, size_t size);

#endif  // !__CK_ALLOC_H__