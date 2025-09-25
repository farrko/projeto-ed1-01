#ifndef SHAPES_H
#define SHAPES_H

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

shape_t *shape_init(E_SHAPETYPE type, void *shape);
void shape_destroy(void *shape);

circle_t *shape_as_circle(shape_t *shape);
rectangle_t *shape_as_rectangle(shape_t *shape);
line_t *shape_as_line(shape_t *shape);
text_t *shape_as_text(shape_t *shape);

node_t *shape_as_node(shape_t *shape);

#endif
