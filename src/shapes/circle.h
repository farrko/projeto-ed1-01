#ifndef CIRCLE_H
#define CIRCLE_H

#include <stddef.h>

typedef struct circle_t circle_t;

circle_t *circle_init(size_t id, double x, double y, double radius, char *color, char *border_color);
void circle_destroy(void *circle);

void circle_set_x(circle_t *circle, double x);
void circle_set_y(circle_t *circle, double y);
void circle_set_radius(circle_t *circle, double radius);
void circle_set_color(circle_t *circle, char *color);
void circle_set_border_color(circle_t *circle, char *border_color);

double circle_get_x(circle_t *circle);
double circle_get_y(circle_t *circle);
double circle_get_radius(circle_t *circle);
char *circle_get_color(circle_t *circle);
char *circle_get_border_color(circle_t *circle);

double circle_get_area(circle_t *circle);

#endif
