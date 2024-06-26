#ifndef __CKASTAL_LIST_H__
#define __CKASTAL_LIST_H__

#include "util/memory.h"
#include "util/std.h"
#include "util/unit.h"

typedef enum Ckastal_ListMode {
    CK_LIST_LINEAR = 0,
    CK_LIST_CIRCULAR,
} Ckastal_ListMode;

typedef struct Ckastal_ListNode {
    void* data;
    struct Ckastal_ListNode* next;
} Ckastal_ListNode;

typedef struct Ckastal_List {
    size_t length;

    Ckastal_ListMode mode;

    Ckastal_ListNode* head;
    Ckastal_ListNode* tail;

    Ckastal_Unit* unit;
} Ckastal_List;

/**
 * Utility functions.
 */

/**
 * @brief Creates a new node.
 *
 * @param data The pointer to store as the data address.
 * @return Ckastal_ListNode*
 */
Ckastal_ListNode* _ck_list_node_new(void* data);

/**
 * @brief Pushes a node to the head of the list.
 *
 * @param list The list to modify.
 * @param node The node to add.
 */
void _ck_list_push_head(Ckastal_List* list, Ckastal_ListNode* node);

/**
 * @brief Creates a new list.
 *
 * @param unit The unit associated with the list.
 * @param mode The mode of the list (linear or circular).
 * @return Ckastal_List
 */
Ckastal_List ck_list_new(Ckastal_Unit* unit, Ckastal_ListMode mode);

/**
 * @brief Pushes data to the tail of the list.
 *
 * @param list The list to modify.
 * @param data The data to add.
 */
void ck_list_push(Ckastal_List* list, void* data);

/**
 * @brief Unshifts data to the head of the list.
 *
 * @param list The list to modify.
 * @param data The data to add.
 */
void ck_list_unshift(Ckastal_List* list, void* data);

#endif /* __CKASTAL_LIST_H__ */
