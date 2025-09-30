#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

typedef struct queue_t queue_t;

/** @brief    Inicialização de uma fila
  *
  * @return   Um pointer para uma fila.
  * @warning  Em caso de erro na alocação de memória, o programa será encerrado.
  */ 
queue_t *queue_init();

/** @brief    Retorna o item na head de uma fila.
  *
  * @param    queue   Pointer para uma fila.
  *
  * @return   O node na head da fila.
  */
node_t *queue_peek(queue_t *queue);

/** @brief    Remove e retorna o item na head de uma fila.
  *
  * @param    queue   Pointer para uma fila.
  *
  * @return   O node na head da fila.
  */
node_t *queue_dequeue(queue_t *queue);

/** @brief    Insere um node na fila como tail.
  *
  * @param    queue   Pointer para uma fila.
  * @param    node    O node a ser inserido.
  */
void queue_enqueue(queue_t *queue, node_t *node);

/** @brief    Retorna o tamanho de uma fila.
  *
  * @param    queue   Pointer para uma fila.
  *
  * @return   A quantidade de nodes de uma fila.
  */
size_t queue_get_length(queue_t *queue);

/** @brief    Destrói por completo uma fila e seus nodes.
  *
  * @param    queue   Pointer para uma fila.
  */
void queue_destroy(queue_t *queue);

#endif
