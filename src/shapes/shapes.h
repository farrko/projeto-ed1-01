#ifndef SHAPES_H
#define SHAPES_H

#include <stdbool.h>

#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "text.h"
#include "../datast/linkedlist.h"

typedef struct shape_t shape_t;
typedef enum {
  CIRCLE,
  RECTANGLE,
  LINE,
  TEXT,
} E_SHAPETYPE;

/** @brief    Inicialização de um shape.
  *
  * @param    type    O tipo da forma armazenada pelo shape.
  * @param    shape   Um pointer para a forma a ser armazenada.
  *
  * @return   Uma instância de shape.
  */
shape_t *shape_init(E_SHAPETYPE type, void *shape);

/** @brief    Destrói um shape e a sua forma associada.
  *
  * @param    shape   Uma instância de shape.
  */
void shape_destroy(void *shape);

/** @brief    Retorna o tipo da forma armazenada no shape.
  *
  * @param    shape   Uma instância de shape.
  *
  * @return   Um membro de E_SHAPETYPE que define o tipo do elemento associado.
  */
E_SHAPETYPE shape_get_type(shape_t *shape);

/** @brief    Retorna a forma associada ao shape como um círculo.
  *
  * @param    shape   Uma instância de shape.
  *
  * @return   Uma instância de círculo.
  */
circle_t *shape_as_circle(shape_t *shape);

/** @brief    Retorna a forma associada ao shape como um retângulo.
  *
  * @param    shape   Uma instância de shape.
  *
  * @return   Uma instância de retângulo.
  */
rectangle_t *shape_as_rectangle(shape_t *shape);

/** @brief    Retorna a forma associada ao shape como uma linha.
  *
  * @param    shape   Uma instância de shape.
  *
  * @return   Uma instância de linha.
  */
line_t *shape_as_line(shape_t *shape);

/** @brief    Retorna a forma associada ao shape como um texto.
  *
  * @param    shape   Uma instância de shape.
  *
  * @return   Uma instância de texto.
  */
text_t *shape_as_text(shape_t *shape);


/** @brief    Inicializa um node com um shape associado.
  *
  * @param    shape   Uma instância de shape.
  *
  * @return   Uma instância de node.
  */
node_t *shape_as_node(shape_t *shape);

size_t shape_get_id(shape_t *shape);
double shape_get_x(shape_t *shape);
double shape_get_y(shape_t *shape);
void shape_set_x(shape_t *shape);
void shape_set_y(shape_t *shape);
char *shape_get_color(shape_t *shape);
char *shape_get_border_color(shape_t *shape);

void shape_move(shape_t *shape, double lx, double ly, double dx, double dy);

double shape_get_area(shape_t *shape);

shape_t *shape_clone(shape_t *shape, size_t id);

void shape_swap_colors(shape_t *shape);

bool shape_overlap(shape_t *i, shape_t *j);

#endif
