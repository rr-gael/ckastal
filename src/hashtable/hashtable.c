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

bool ck_hashtable_is_key_match(CK_HashTable *ht, void *a, void *b) {
    switch (ht->_key_type) {
        case CK_HASHTABLE_KEY_STRING:
            return ck_strcmp((char *)a, (char *)b) == 0;
        case CK_HASHTABLE_KEY_VALUE:
        default:
            return *(size_t *)a - *(size_t *)b == 0;
    }
}

CK_HashTable_SetStatus ck_hashtable_set(CK_HashTable *ht, CK_DataRef key, CK_DataRef data) {
    size_t index = ht->_hash_function(ht, key);

    CK_HashTable_Bucket *bucket = ck_arraylist_get(&ht->_buckets, index);

    if (!bucket) {
        bucket = calloc(1, sizeof(CK_HashTable_Bucket));
        bucket->item = (CK_HashTable_Item){
            .key = key,
            .value = data,
        };

        ck_arraylist_set(&ht->_buckets, index, bucket);

        return CK_HASHTABLE_SET_SUCCESS;
    }

    CK_HashTable_Bucket *current = bucket;

    while (current->next) {
        if (ck_hashtable_is_key_match(ht, current->item.key, key)) {
            if (ht->_buckets._data._delete_mode == CK_DATA_DELMODE_FREE) {
                free(current->item.value);
            }

            current->item.value = data;

            return CK_HASHTABLE_SET_REPLACED;
        }

        current = current->next;
    }

    current->next = calloc(1, sizeof(CK_HashTable_Bucket));
    current->next->item = (CK_HashTable_Item){
        .key = key,
        .value = data,
    };

    return CK_HASHTABLE_SET_PUSHED;
}

size_t ck_hashtable_len(CK_HashTable *ht) {
    return ht->_buckets._length;
}
size_t ck_hashtable_capacity(CK_HashTable *ht) {
    return ht->_buckets._current_capacity;
}