#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

struct queue_t {
  llist_t *ll;
};

queue_t *queue_init() {
  llist_t *ll = llist_init();

  queue_t *queue = malloc(sizeof(queue_t));
   if (queue == NULL) {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }

  queue->ll = ll;

  return queue;
}

node_t *queue_peek(queue_t *queue) {
  return llist_get_head(queue->ll);
}

node_t *queue_dequeue(queue_t *queue) {
  return llist_popat_start(queue->ll);
}

void queue_enqueue(queue_t *queue, node_t *node) {
  llist_insertat_end(queue->ll, node);
}

size_t queue_get_length(queue_t *queue) {
  return llist_get_length(queue->ll);
}

void queue_destroy(queue_t *queue) {
  llist_destroy(queue->ll);
  free(queue);
}
