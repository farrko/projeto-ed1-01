#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"

typedef struct stack_t stack_t;

/** @brief    Inicialização de uma pilha.
  *
  * @return   Um pointer para uma pilha.
  * @warning  Em caso de erro na alocação de memória, o programa será encerrado.
  */
stack_t *stack_init();

/** @brief    Retorna o node no topo de uma pilha.
  *
  * @param    stack   Pointer para uma pilha.
  *
  * @return   O node no topo da pilha.
  */
node_t *stack_peek(stack_t *stack);

/** @brief    Remove e retorna o node no topo de uma pilha.
  *
  * @param    stack   Pointer para uma pilha.
  *
  * @return   O node no topo da pilha.
  */
node_t *stack_pop(stack_t *stack);

/** @brief    Insere um node no topo de uma pilha.
 *
  * @param    stack   Pointer para uma pilha.
  * @param    node    Node a ser inserido.
  */
void stack_push(stack_t *stack, node_t *node);

/** @brief    Retorna o tamanho de uma pilha.
  *
  * @param    stack   Pointer para uma pilha.
  *
  * @return   A quantidade de nodes de uma pilha.
  *
  */
size_t stack_get_length(stack_t *stack);

/** @brief    Destrói por completo uma pilha e seus nodes.
  *
  * @param    stack   Pointer para uma pilha.
  */
void stack_destroy(stack_t *stack);

#endif
