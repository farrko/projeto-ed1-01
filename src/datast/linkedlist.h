#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>

typedef struct llist_t llist_t;
typedef struct node_t node_t;

node_t *node_init(void *value, void (*destructor)(void*));
void *node_getvalue(node_t *node);
void node_destroy(node_t *node);

llist_t *llist_init();
void llist_destroy(llist_t *llist);

node_t *llist_get_head(llist_t *llist);
node_t *llist_get_tail(llist_t *llist);
size_t llist_get_length(llist_t *llist);

node_t *llist_getat_index(llist_t *llist, size_t index);
node_t *llist_getat_start(llist_t *llist);
node_t *llist_getat_end(llist_t *llist);

node_t *llist_popat_index(llist_t *llist, size_t index);
node_t *llist_popat_start(llist_t *llist);
node_t *llist_popat_end(llist_t *llist);

void llist_insertat_index(llist_t *llist, node_t *node, size_t index);
void llist_insertat_start(llist_t *llist, node_t *node);
void llist_insertat_end(llist_t *llist, node_t *node);

void llist_destroyat(llist_t *llist, size_t index);

#endif // !LINKEDLIST_H
