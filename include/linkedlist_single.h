#ifndef __LINKED_LIST__

#define __LINKED_LIST__

#include "util/data.h"
#include "util/mem.h"

typedef (*CK_LinkedList_Callback)(CK_LinkedList* list, CK_LLNode* node, size_t index, void* ctx);

typedef struct CK_LLNode {
    CK_DataRef data;
    struct CK_LLNode* next;
} CK_LLNode;

typedef struct CK_LinkedList {
    size_t length;

    CK_Data data;

    CK_LLNode* head;
    CK_LLNode* tail;
} CK_LinkedList;

/**
 * Creation
 */

CK_LinkedList ck_linkedlist_new(CK_Data data);

/**
 * Insertions
 */

void ck_linkedlist_push(CK_LinkedList* list, CK_DataRef data);

void ck_linkedlist_unshift(CK_LinkedList* list, CK_DataRef data);

void ck_linkedlist_insert(CK_LinkedList* list, size_t index, CK_DataRef data);

/**
 * Reads
 */

CK_DataRef ck_linkedlist_get_index(CK_LinkedList* list, size_t index);

CK_DataRef ck_linkedlist_find(CK_LinkedList* list, CK_LinkedList_Callback predicate, void* ctx);

/**
 * Deletions
 */

void ck_linkedlist_delete_index(CK_LinkedList* list, size_t index);

void ck_linkedlist_match(CK_LinkedList* list, CK_LinkedList_Callback predicate, void* ctx);

void ck_linkedlist_filter(CK_LinkedList* list, CK_LinkedList_Callback predicate, void* ctx);

/**
 * Iterators
 */

CK_LinkedList ck_linkedlist_map(CK_LinkedList* list, CK_LinkedList_Callback callback, void* ctx);

void ck_linkedlist_foreach(CK_LinkedList* list, CK_LinkedList_Callback callback, void* ctx);

/**
 * Destuctors
 */

void ck_linkedlist_empty(CK_LinkedList* list);

void ck_linkedlist_free(CK_LinkedList** list);

#endif /** __LINKED_LIST__ */