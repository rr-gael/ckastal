#ifndef __CK_DATA_H__

#define __CK_DATA_H__

#include "mem.h"

#define CK_DataRef void*

#define CK_DATA_REF_SIZE (sizeof(void*))

typedef enum CK_Data_StoreMode {
    CK_DATA_STOREMODE_REF,
    CK_DATA_STOREMODE_COPY,
} CK_Data_StoreMode;
typedef enum CK_Data_DeleteMode {
    /** Free the reference at deletion */
    CK_DATA_DELMODE_FREE,
    /** Return the reference at deletion */
    CK_DATA_DELMODE_RETURN,
} CK_Data_DeleteMode;

typedef enum CK_Data_ChangeType {
    CK_DATA_INSERTION,
    CK_DATA_UPDATE,
    CK_DATA_DELETION,
} CK_Data_ChangeType;

typedef void (*CK_DataPrintHandler)(void* data);
typedef void (*CK_DataCompareHandler)(void* a, void* b);

typedef void (*CK_DataChangeHandler)(CK_Data_ChangeType type, void* ctx, void* data, size_t index);

typedef struct CK_Data {
    size_t _unit_size;
    CK_Data_StoreMode _store_mode;
    CK_Data_DeleteMode _delete_mode;

    CK_DataPrintHandler print;
    CK_DataCompareHandler compare;

    CK_DataChangeHandler change;
} CK_Data;

#endif  // !__CK_DATA_H__