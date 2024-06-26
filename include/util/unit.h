#ifndef __CKASTAL_UTIL_UNIT_H__
#define __CKASTAL_UTIL_UNIT_H__

#include "std.h"

typedef void (*Ckastal_UnitPrint)(void*);

typedef struct {
    size_t size;
    
    Ckastal_UnitPrint print;
} Ckastal_Unit;

#endif /* __CKASTAL_UTIL_UNIT_H__ */
