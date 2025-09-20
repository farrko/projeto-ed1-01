#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

typedef struct queue_t queue_t;

queue_t *queue_init();
node_t *queue_peek(queue_t *queue);
node_t *queue_dequeue(queue_t *queue);
void queue_enqueue(queue_t *queue, node_t *node);
size_t queue_get_length(queue_t *queue);
void queue_destroy(queue_t *queue);

#endif
