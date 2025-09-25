#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stddef.h>

typedef struct rectangle_t rectangle_t;

rectangle_t *rect_init(size_t id, double x, double y, double width, double height, char *color, char *border_color);
void rect_destroy(void *rectangle);

void rect_set_x(rectangle_t *rect, double x);
void rect_set_y(rectangle_t *rect, double y);
void rect_set_width(rectangle_t *rect, double width);
void rect_set_height(rectangle_t *rect, double height);
void rect_set_color(rectangle_t *rect, char *color);
void rect_set_border_color(rectangle_t *rect, char *border_color);

size_t rect_get_id(rectangle_t *rect);
double rect_get_x(rectangle_t *rect);
double rect_get_y(rectangle_t *rect);
double rect_get_width(rectangle_t *rect);
double rect_get_height(rectangle_t *rect);
char *rect_get_color(rectangle_t *rect);
char *rect_get_border_color(rectangle_t *rect);

double rect_get_area(rectangle_t *rect);

#endif
