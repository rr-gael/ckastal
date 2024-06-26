/**
 * @file std.h
 * @author your name (you@domain.com)
 * @brief The purpose of this file is to provide common macro
 * and type definitions from stdlib with out the need to include
 * it in case the implementation does not wishes to do that.
 * @version 0.1
 * @date 2024-06-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __CKASTAL_UTIL_STD_H__
#define __CKASTAL_UTIL_STD_H__

/**
 * size_t definition
 */
#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

/**
 * NULL definition
 */
#ifndef NULL
#define NULL ((void*)0)
#endif

/**
 * Boolean definitions
 */
#ifndef bool

#define false FALSE
#define true TRUE

typedef enum {
    false = 0,
    true = 1
} bool;

#endif

#endif /* __CKASTAL_UTIL_STD_H__ */