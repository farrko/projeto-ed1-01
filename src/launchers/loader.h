#ifndef LOADER_H
#define LOADER_H

#include <stddef.h>
#include "../datast/stack.h"

typedef struct loader_t loader_t;

/** @brief    Inicializa uma nova instância de loader.
  *
  * @param    id    Identificador único do loader.
  *
  * @return   Uma nova instância de loader.
  */
loader_t *ld_init(size_t id);

/** @brief    Remove e retorna o elemento do topo do loader.
  *
  * @param    loader   Uma instância de loader.
  *
  * @return   O node removido do topo da pilha.
  */
node_t *ld_pop(loader_t *loader);

/** @brief    Insere um node no topo do loader.
  *
  * @param    loader   Uma instância de loader.
  * @param    node     O node a ser inserido na pilha.
  */
void ld_push(loader_t *loader, node_t *node);

/** @brief    Libera a memória associada a uma instância de loader.
  *
  * @param    l    Uma instância de loader.
  */
void ld_destroy(void *l);

/** @brief    Retorna o identificador do loader.
  *
  * @param    loader   Uma instância de loader.
  *
  * @return   O identificador único do loader.
  */
size_t ld_get_id(loader_t *loader);

/** @brief    Retorna a quantidade de elementos armazenados no loader.
  *
  * @param    loader   Uma instância de loader.
  *
  * @return   O número de elementos contidos na pilha do loader.
  */
size_t ld_get_length(loader_t *loader);

#endif
