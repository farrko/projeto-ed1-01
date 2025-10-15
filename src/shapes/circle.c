#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "circle.h"

struct circle_t {
  size_t id;
  double x, y;
  double radius;
  char *color;
  char *border_color;
};

circle_t *circle_init(size_t id, double x, double y, double radius, char *color, char *border_color) {
  circle_t *circle = malloc(sizeof(circle_t));
  if (circle == NULL) {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }

  circle->id = id;
  circle->x = x;
  circle->y = y;
  circle->radius = radius;
  circle->color = color;
  circle->border_color = border_color;

  return circle;
}

void circle_destroy(void *circle) {
  if (circle == NULL) return;
  circle_t *c = (circle_t *) circle;

  if (c->color != NULL) free(c->color);
  if (c->border_color != NULL) free(c->border_color);

  free(circle);
}

void circle_set_x(circle_t *circle, double x) {
  if (circle == NULL) return;
  circle->x = x;
}

void circle_set_y(circle_t *circle, double y) {
  if (circle == NULL) return;
  circle->y = y;
}

void circle_set_radius(circle_t *circle, double radius) {
  if (circle == NULL) return;
  circle->radius = radius;
}

void circle_set_color(circle_t *circle, char *color) {
  if (circle == NULL) return;
  if (circle->color != NULL) free(circle->color);
  circle->color = color;
}

void circle_set_border_color(circle_t *circle, char *border_color) {
  if (circle == NULL) return;
  if (circle->border_color != NULL) free(circle->border_color);
  circle->border_color = border_color;
}

size_t circle_get_id(circle_t *circle) {
  if (circle == NULL) return 0;
  return circle->id;
}

double circle_get_x(circle_t *circle) {
  if (circle == NULL) return 0;
  return circle->x;
}

double circle_get_y(circle_t *circle) {
  if (circle == NULL) return 0;
  return circle->y;
}

double circle_get_radius(circle_t *circle) {
  if (circle == NULL) return 0;
  return circle->radius;
}

char *circle_get_color(circle_t *circle) {
  if (circle == NULL) return 0;
  return circle->color;
}

char *circle_get_border_color(circle_t *circle) {
  if (circle == NULL) return 0;
  return circle->border_color;
}

double circle_get_area(circle_t *circle) {
  if (circle == NULL) return 0;
  return pow(circle->radius, 2) * 3.1415;
}

circle_t *circle_clone(circle_t *circle, size_t id) {
  char *color = malloc(8);
  if (color == NULL) {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }

  char *border_color = malloc(8);
  if (border_color == NULL) {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }

  strcpy(color, circle->color);
  strcpy(border_color, circle->border_color);

  return circle_init(id, circle->x, circle->y, circle->radius, color, border_color);
}

void circle_swap_colors(circle_t *circle) {
  char *color = circle->color;
  char *border_color = circle->border_color;

  circle->color = border_color;
  circle->border_color = color;
}
