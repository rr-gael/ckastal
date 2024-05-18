#include "../../include/util/string.h"

short ck_strcmp(const char* a, const char* b) {
    const unsigned char* p1 = (const unsigned char*)a;
    const unsigned char* p2 = (const unsigned char*)b;

    while (*p1 && *p1 == *p2) {
        ++p1, ++p2;
    }

    return (*p1 > *p2) - (*p2 > *p1);
}