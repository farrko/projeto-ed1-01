#include <stdio.h>
#include <stdlib.h>

#include "datast/linkedlist.h"
#include "datast/queue.h"
#include "files/geo.h"
#include "shapes/rectangle.h"
#include "shapes/shapes.h"

int main() {
  queue_t *arena = queue_init();

  geo_processing("./retg-decres.geo", arena);

  size_t len = queue_get_length(arena);
  for (size_t i = 0; i < len; i++) {
    node_t *current = queue_dequeue(arena);
    rectangle_t *rect = shape_as_rectangle((shape_t *) node_getvalue(current));

    printf("- Forma %zu\n", i + 1);
    printf("\tid: %zu\n", rect_get_id(rect));
    printf("\tx: %lf\n", rect_get_x(rect));
    printf("\ty: %lf\n", rect_get_y(rect));
    printf("\twidth: %lf\n", rect_get_width(rect));
    printf("\theight: %lf\n", rect_get_height(rect));
    printf("\tcolor: %s\n", rect_get_color(rect));
    printf("\tborder-color: %s\n", rect_get_border_color(rect));
    printf("\n");

    node_destroy(current);
  }

  queue_destroy(arena);
}
