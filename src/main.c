#include <stdio.h>
#include <stdlib.h>

#include "datast/linkedlist.h"
#include "datast/queue.h"
#include "files/geo.h"
#include "shapes/shapes.h"
#include "files/svg.h"
#include "files/qry.h"

int main() {
  queue_t *ground = queue_init();

  size_t highest_id = geo_processing("./t-2figs-alet.geo", ground);
  svg_t *preqry_svg = svg_init("./pre-qry.svg");

  for (size_t i = 0; i < queue_get_length(ground); i++) {
    node_t *current = queue_dequeue(ground);
    shape_t *shape = (shape_t *) node_getvalue(current);

    switch (shape_get_type(shape)) {
      case CIRCLE:
        svg_write_circle(preqry_svg, shape_as_circle(shape));
        break;
      case RECTANGLE:
        svg_write_rectangle(preqry_svg, shape_as_rectangle(shape));
        break;
      case LINE:
        svg_write_line(preqry_svg, shape_as_line(shape));
        break;
      case TEXT:
        svg_write_text(preqry_svg, shape_as_text(shape));
        break;
    }

    queue_enqueue(ground, current);
  }
  svg_close(preqry_svg);

  qry_processing("./d2-1x1-norte.qry", "test.txt", ground, highest_id);

  svg_t *postqry_svg = svg_init("./post-qry.svg");

  for (size_t i = 0; i < queue_get_length(ground); i++) {
    node_t *current = queue_dequeue(ground);
    shape_t *shape = (shape_t *) node_getvalue(current);

    switch (shape_get_type(shape)) {
      case CIRCLE:
        svg_write_circle(postqry_svg, shape_as_circle(shape));
        break;
      case RECTANGLE:
        svg_write_rectangle(postqry_svg, shape_as_rectangle(shape));
        break;
      case LINE:
        svg_write_line(postqry_svg, shape_as_line(shape));
        break;
      case TEXT:
        printf("adicionado texto\n");
        svg_write_text(postqry_svg, shape_as_text(shape));
        break;
    }

    queue_enqueue(ground, current);
  }
  svg_close(postqry_svg);

  queue_destroy(ground);
}
