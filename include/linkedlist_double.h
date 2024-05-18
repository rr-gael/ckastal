#ifndef __LLD_H__
#define __LLD_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LLDNode {
    void *value_addr;
    struct LLDNode *next;
    struct LLDNode *prev;
} LLDNode;

typedef struct {
    size_t length;
    struct LLDNode *head;
    struct LLDNode *tail;
} LLD;

LLD *lld();

LLDNode *lld_node_new(void *value_addr);

LLDNode *lld_append(LLD *list, void *value_addr);
LLDNode *lld_unshift(LLD *list, void *value_addr);
LLDNode *lld_insert(LLD *list, int index, void *value_addr);
LLDNode *lld_delwhere(LLD *list, bool predicate(void *, int));
LLDNode *lld_delrange(LLD *list, int from, int to);
LLDNode *lld_cutfrom(LLD *list_source, LLD *list_target, int target_index);

void lld_empty(LLD *list);
void lld_free(LLD **list);
void lld_print(LLD *list, void print_element(void *));

#endif /* __LLD_H__ */
