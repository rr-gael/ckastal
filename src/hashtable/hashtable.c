#include "../../include/hashtable.h"

CK_HashTable ck_hashtable_new(
    size_t capacity,
    CK_Collection_ResizeMode resize_mode,
    CK_HashTable_KeyType key_type,
    CK_Data data

) {
    CK_HashTable ht = {
        .resize_mode = resize_mode,
        ._key_type = key_type,

        ._buckets = ck_arraylist_new(capacity, CK_ARRAYLIST_ACCESS_BEFORE_CAP, data),
    };

    return ht;
};

CK_HashTable_SetStatus ck_hashtable_set(CK_HashTable *ht, CK_DataRef key, CK_DataRef value) {
    size_t index = ht->_hash_function(ht, key);

    Ck_HashTable_Bucket *bucket = ck_arraylist_get(&ht->_buckets, index);

    if (bucket) {
    }
}

size_t ck_hashtable_len(CK_HashTable *ht) {
    return ht->_buckets._length;
}
size_t ck_hashtable_capacity(CK_HashTable *ht) {
    return ht->_buckets._current_capacity;
}