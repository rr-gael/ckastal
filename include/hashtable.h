#ifndef __CK_HASHTABLE_H__

#define __CK_HASHTABLE_

#include "arraylist.h"
#include "util/collection.h"

typedef enum CK_HashTable_KeyType {
    CK_HASHTABLE_KEY_STRING = 0,
    /** For single number values or chars */
    CK_HASHTABLE_KEY_VALUE,
} CK_HashTable_KeyType;

typedef enum CK_HashTable_SetStatus {
    CK_HASHTABLE_INSERT_ERROR = -1,
    CK_HASHTABLE_INSERT_SUCCESS,
    CK_HASHTABLE_INSERT_REPLACED,
} CK_HashTable_SetStatus;

typedef size_t (*CK_HashTable_HashFunction)(CK_HashTable ht, CK_DataRef key);

typedef struct CK_HashTable_Item {
    void *key;
    void *value;
} CK_HashTable_Item;

typedef CK_HashTable_Item *Ck_HashTable_Bucket;

typedef struct CK_HashTable {
    CK_Collection_ResizeMode resize_mode;
    CK_HashTable_KeyType _key_type;

    CK_ArrayList _buckets;

    CK_HashTable_HashFunction _hash_function;
} CK_HashTable;

CK_HashTable ck_hashtable_new(size_t capacity, CK_Collection_ResizeMode resize_mode, CK_HashTable_KeyType key_type, CK_Data data);

CK_HashTable_SetStatus ck_hashtable_set();

size_t ck_hashtable_len(CK_HashTable *ht);
size_t ck_hashtable_capacity(CK_HashTable *ht);

#endif  // !__CK_HASHTABLE_H__