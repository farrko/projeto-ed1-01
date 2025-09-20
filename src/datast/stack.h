#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"

typedef struct stack_t stack_t;

stack_t *stack_init();
node_t *stack_peek(stack_t *stack);
node_t *stack_pop(stack_t *stack);
void stack_push(stack_t *stack, node_t *node);
size_t stack_get_length(stack_t *stack);
void stack_destroy(stack_t *stack);

#endif
