#ifndef __CK_HASHTABLE_H__

#define __CK_HASHTABLE_

#include "arraylist.h"
#include "linkedlist_single.h"
#include "util/bool.h"
#include "util/collection.h"
#include "util/string.h"

typedef enum CK_HashTable_KeyType {
    CK_HASHTABLE_KEY_STRING = 0,
    /** For single number values or chars */
    CK_HASHTABLE_KEY_VALUE,
} CK_HashTable_KeyType;

typedef enum CK_HashTable_SetStatus {
    CK_HASHTABLE_SET_ERROR = -1,
    CK_HASHTABLE_SET_SUCCESS,
    CK_HASHTABLE_SET_REPLACED,
    CK_HASHTABLE_SET_PUSHED,
} CK_HashTable_SetStatus;

typedef size_t (*CK_HashTable_HashFunction)(CK_HashTable ht, CK_DataRef key);

typedef struct CK_HashTable_Item {
    CK_DataRef key;
    CK_DataRef value;
} CK_HashTable_Item;

typedef struct CK_HashTable_Bucket {
    CK_HashTable_Item item;
    struct CK_HashTable_Bucket *next;
} CK_HashTable_Bucket;

typedef struct CK_HashTable {
    CK_Collection_ResizeMode resize_mode;
    CK_HashTable_KeyType _key_type;

    CK_ArrayList _buckets;

    CK_HashTable_HashFunction _hash_function;
} CK_HashTable;

CK_HashTable ck_hashtable_new(size_t capacity, CK_Collection_ResizeMode resize_mode, CK_HashTable_KeyType key_type, CK_Data data);

/**
 * @brief Set a value for a key.
 *
 * @param ht
 * @param key
 * @param data
 * @return CK_HashTable_SetStatus
 */

CK_HashTable_SetStatus ck_hashtable_set(CK_HashTable *ht, CK_DataRef key, CK_DataRef data);

/**
 * @brief Deletes the key.
 *
 * @param ht
 * @param key
 * @return CK_HashTable_SetStatus
 */
CK_HashTable_SetStatus ck_hashtable_delete(CK_HashTable *ht, CK_DataRef key);

/**
 * @brief Get the value for a key.
 *
 * @param ht
 * @param key
 * @return CK_DataRef
 */
CK_DataRef ck_hashtable_get(CK_HashTable *ht, CK_DataRef key);

/**
 * Helpers
 */

size_t ck_hashtable_len(CK_HashTable *ht);

size_t ck_hashtable_capacity(CK_HashTable *ht);

#ifdef _INC_STDIO

void ck_hashtable_print(CK_HashTable *ht);

#endif

#endif  // !__CK_HASHTABLE_H__