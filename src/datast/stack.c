#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

struct stack_t {
  llist_t *ll;
};

stack_t *stack_init() {
  llist_t *ll = llist_init();

  stack_t *stack = malloc(sizeof(stack_t));
  if (stack == NULL) {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }
  stack->ll = ll;

  return stack;
}

node_t *stack_peek(stack_t *stack) {
  return llist_get_tail(stack->ll);
}

node_t *stack_pop(stack_t *stack) {
  return llist_popat_end(stack->ll);
}

void stack_push(stack_t *stack, node_t *node) {
  llist_insertat_end(stack->ll, node);
}

size_t stack_get_length(stack_t *stack) {
  return llist_get_length(stack->ll);
}

void stack_destroy(stack_t *stack) {
  llist_destroy(stack->ll);
  free(stack);
}
