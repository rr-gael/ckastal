#include "../../include/arraylist.h"

size_t ck_arraylist_elment_size(CK_ArrayList *al) {
    switch (al->_data._store_mode) {
        case CK_DATA_STOREMODE_COPY:
            return al->_data._unit_size;
        case CK_DATA_STOREMODE_REF:
        default:
            return CK_DATA_REF_SIZE;
    }
}

CK_ArrayList ck_arraylist_new(size_t initial_capacity, CK_ArrayList_AccessMode access_mode, CK_Data data) {
    CK_ArrayList al = {
        ._length = 0,
        ._current_capacity = initial_capacity,

        .access_mode = access_mode,

        ._data = data,
        ._elements = NULL,
    };

    al._elements = calloc(al._current_capacity, ck_arraylist_get_element_size(&al));

    return al;
}

void *ck_arraylist_delete(CK_ArrayList *al, size_t i) {
    switch (al->_data._delete_mode) {
        case CK_DATA_DELMODE_FREE:
            free(al->_elements[i]);

            return NULL;
        case CK_DATA_DELMODE_RETURN:
        default:
            al->_data.change(CK_DATA_DELETION, al, al->_elements[i], 0);

            return al->_elements[i];
    }
}

void *ck_arraylist_set(CK_ArrayList *al, size_t i, void *data) {
    void *previous = NULL;

    if (i >= al->_length && al->access_mode == CK_ARRAYLIST_ACCESS_BEFORE_LEN) {
        /** Should crash and give a message here or something */
        return NULL;
    }
    if (i >= al->_current_capacity && al->access_mode == CK_ARRAYLIST_ACCESS_BEFORE_CAP) {
        return NULL;
    }

    switch (al->_data._store_mode) {
        case CK_DATA_STOREMODE_REF:
            previous = ck_arraylist_delete(al, i);
            al->_elements[i] = data;

            break;
        case CK_DATA_STOREMODE_COPY:
        default:
            if (data == NULL) {
                memset(&al->_elements[i], data, al->_data._unit_size);
                break;
            }

            memcpy(&al->_elements[i], data, al->_data._unit_size);

            break;
    }

    if (al->_data.change) {
        al->_data.change(CK_DATA_INSERTION, al, ck_arraylist_get(al, i), i);
    }

    return previous;
}
void ck_arraylist_push(CK_ArrayList *al, void *data) {
    if (al->_length == al->_current_capacity) {
        /** The length to be set */
        size_t length_next = al->_current_capacity * CK_ARRAYLIST_EXPANSION_FACTOR;
        /** Switches based on the store mode, if storing the pointer returns void * size */
        size_t al_element_size = ck_arraylist_elment_size(al);

        al->_elements = realloc(al->_elements, length_next * al_element_size);
    }

    switch (al->_data._store_mode) {
        case CK_DATA_STOREMODE_REF:
            al->_elements[al->_length] = data;
            break;
        case CK_DATA_STOREMODE_COPY:
        default:
            if (data == NULL) {
                memset(&al->_elements[al->_length], data, al->_data._unit_size);
                break;
            }

            memcpy(&al->_elements[al->_length], data, al->_data._unit_size);

            break;
    }

    al->_length += 1;

    if (al->_data.change) {
        al->_data.change(
            CK_DATA_INSERTION,
            al,
            ck_arraylist_get(al, al->_length - 1),
            al->_length - 1

        );
    }
}

void *ck_arraylist_get(CK_ArrayList *al, size_t i) {
    switch (al->_data._store_mode) {
        case CK_DATA_STOREMODE_REF:
            return al->_elements[i];
        case CK_DATA_STOREMODE_COPY:
        default:
            return &al->_elements[i];
    }
}
