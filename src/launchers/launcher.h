#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <stddef.h>

#include "../shapes/shapes.h"
#include "loader.h"

typedef struct launcher_t launcher_t;

launcher_t *ln_init(size_t id, double x, double y);
void ln_destroy(void *launcher);
void ln_attach_loader(launcher_t *launcher, size_t side, loader_t *loader);
void ln_shift_loaders(launcher_t *launcher, size_t side, size_t amount);
node_t *ln_get_loaded(launcher_t *launcher);
size_t ln_get_id(launcher_t *launcher);
double ln_get_x(launcher_t *launcher);
double ln_get_y(launcher_t *launcher);
void ln_set_loaded(launcher_t *launcher, node_t *loaded);
loader_t *ln_get_left_ld(launcher_t *launcher);
loader_t *ln_get_right_ld(launcher_t *launcher);

/** @brief    Inicializa uma nova instância de launcher.
  *
  * @param    id    Identificador único do launcher.
  * @param    x     Coordenada X de posição.
  * @param    y     Coordenada Y de posição.
  *
  * @return   Uma nova instância de launcher.
  */
launcher_t *ln_init(size_t id, double x, double y);

/** @brief    Destrói uma instância de launcher.
  *
  * @param    launcher   Uma instância de launcher.
  *
  * @warning  A destruição do launcher não destrói os loaders associados.
  */
void ln_destroy(void *launcher);

/** @brief    Associa um loader a um dos lados do launcher.
  *
  * @param    launcher   Uma instância de launcher.
  * @param    side       Lado onde o loader será acoplado (0 = esquerdo, 1 = direito).
  * @param    loader     Loader a ser associado.
  */
void ln_attach_loader(launcher_t *launcher, size_t side, loader_t *loader);

/** @brief    Desloca os nodes dos loaders entre si.
  *
  * @param    launcher   Uma instância de launcher.
  * @param    side       Lado do launcher a ser deslocado (0 = esquerdo, 1 = direito).
  * @param    amount     Quantidade de nodes a deslocar.
  */
void ln_shift_loaders(launcher_t *launcher, size_t side, size_t amount);

/** @brief    Retorna o node atualmente carregado no launcher.
  *
  * @param    launcher   Uma instância de launcher.
  *
  * @return   O node carregado.
  */
node_t *ln_get_loaded(launcher_t *launcher);

/** @brief    Retorna o identificador do launcher.
  *
  * @param    launcher   Uma instância de launcher.
  *
  * @return   O identificador único do launcher.
  */
size_t ln_get_id(launcher_t *launcher);

/** @brief    Retorna a coordenada X do launcher.
  *
  * @param    launcher   Uma instância de launcher.
  *
  * @return   A posição X do launcher.
  */
double ln_get_x(launcher_t *launcher);

/** @brief    Retorna a coordenada Y do launcher.
  *
  * @param    launcher   Uma instância de launcher.
  *
  * @return   A posição Y do launcher.
  */
double ln_get_y(launcher_t *launcher);

/** @brief    Define o node carregado atualmente no launcher.
  *
  * @param    launcher   Uma instância de launcher.
  * @param    loaded     O node a ser definido como carregado.
  */
void ln_set_loaded(launcher_t *launcher, node_t *loaded);

/** @brief    Retorna o loader do lado esquerdo do launcher.
  *
  * @param    launcher   Uma instância de launcher.
  *
  * @return   O loader associado ao lado esquerdo.
  */
loader_t *ln_get_left_ld(launcher_t *launcher);

/** @brief    Retorna o loader do lado direito do launcher.
  *
  * @param    launcher   Uma instância de launcher.
  *
  * @return   O loader associado ao lado direito.
  */
loader_t *ln_get_right_ld(launcher_t *launcher);

#endif
