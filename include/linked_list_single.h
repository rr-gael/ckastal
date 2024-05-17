#ifndef __LINKED_LIST__

#define __LINKED_LIST__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LLNode {
    void* value_addr;
    struct LLNode* next;
} LLNode;
typedef struct {
    int length;
    int node_value_size;
    struct LLNode* head;
} LinkedList;

LLNode* ll_node_new(void* value_addr);
LinkedList* ll_new(int node_value_size);

/**
 * Adds a new node that contains the value address
 *
 * @returns A pointer to the new node
 */
LLNode* ll_append(LinkedList* list, void* value_addr);

/**
 * Deallocates the last Node and the value_addr of it
 *
 * @returns The new length of the list
 */
LLNode* ll_pop(LinkedList* list);

/**
 * Adds a new node in the desired index
 *
 * @returns A pointer to the node added
 */
LLNode* ll_insert(LinkedList* list, int index, void* value_addr);

/**
 * Deallocates nodes from a starting index to an specified index, both
 * inclusive.
 */
LLNode* ll_delete_index(LinkedList* list, int from, int to);

/**
 * Deletes the nodes that match the predicate
 *
 * @returns The amount of nodes deleted
 */
int ll_delete_where(LinkedList* list, bool predicate(void*, int));

void ll_foreach(LinkedList* list, void callback(void*, int, LinkedList*));

/**
 * Sets a new node with the value address to the
 * head of the list and the previous head to the next
 * pointer of the new node
 */
void ll_unshift(LinkedList* list, void* value_addr);

/**
 * @brief Bubble sort based on the get_order_weight callback, the
 * higher the value it returns for a node, the upper it will be
 * on the list.
 *
 * @param list The list to sort
 * @param get_order_weight Gets passed in two pointers to values on the list
 * and should return an int that indicates if the first element should go
 * earlier on the list by being a lower value.
 */
void ll_sort(LinkedList* list, int get_order_weight(void*, void*));

/**
 * @brief Copies a list value by value.
 *
 * @param list
 * @param get_copy_value_addr Receives a pointer to the original value to return
 * a pointer to a new allocated value that should be a copy of the original.
 * @return A linked list copy of the original
 */
LinkedList* ll_copy(LinkedList* list, void* get_copy_value_addr(void*));

/**
 * Deallocates the nodes of the linked list and frees
 * the associated value addresses of them without
 * destroying the linked list
 */
void ll_delete_all(LinkedList* list);

/**
 * Empties the linked list and frees the linked list
 */
void ll_free(LinkedList** list);

#endif /** __LINKED_LIST__ */