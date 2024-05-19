#ifndef __CKASTAL_LIST_H__

#define __CKASTAL_LIST_H__

typedef struct CK_ListNode {
    void *data;
    struct CK_ListNode *next;
    struct CK_ListNode *prev;
} CK_ListNode;

typedef struct CK_List {
    size_t length;

    CK_ListNode *head;
    CK_ListNode *tail;
} CK_List;

/**
 * Writes
 */

void ck_list_push(CK_List *list, void *data);

void ck_list_unshift(CK_List *list, void *data);

void ck_list_insert(CK_List *list, size_t index, void *data);

/**
 * Reads
 */

void *ck_list_get(CK_List *list, size_t index);

/**
 * Updates
 */

void ck_list_set(CK_List *list, size_t index, void *data);

/**
 * Deletes
 */

void ck_list_pop(CK_List *list);

#endif  // !__CKASTAL_LIST_H__