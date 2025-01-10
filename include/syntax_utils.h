#ifndef __CKASTAL_CORE_FOREACH__
#define __CKASTAL_CORE_FOREACH__

#define foreach(iterator, node, type) \
    for (type node = iterator.next(&iterator); node != NULL; node = iterator.next(&iterator))

#define deref(ptr, type) (*(type *)(ptr))
#define cast(type, void_ptr) ((type *)(void_ptr))

#endif /** __CKASTAL_CORE_FOREACH__ */