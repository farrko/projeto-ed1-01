#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "text.h"

struct text_t {
  size_t id;
  double x, y;
  char *anchor;
  char *color;
  char *border_color;
  char *ffam;
  char *fweight;
  char *fsize;
  char *content;
};

text_t *text_init(size_t id, double x, double y, char *anchor, char *color, char *border_color, char *ffam, char *fweight, char *fsize, char *content) {
  text_t *text = malloc(sizeof(text_t));
  if (text == NULL) {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }

  text->id = id;
  text->x = x;
  text->y = y;
  text->anchor = anchor;
  text->color = color;
  text->border_color = border_color;
  text->ffam = ffam;
  text->fweight = fweight;
  text->fsize = fsize;
  text->content = content;

  return text;
}

void text_destroy(void *text) {
  text_t *t = (text_t *) text;

  if (t->anchor != NULL) free(t->anchor);
  if (t->color != NULL) free(t->color);
  if (t->border_color != NULL) free(t->border_color);
  if (t->ffam != NULL) free(t->ffam);
  if (t->fweight != NULL) free(t->fweight);
  if (t->fsize != NULL) free(t->fsize);
  if (t->content != NULL) free(t->content);

  free(t);
}

void text_set_x(text_t *text, double x) {
  text->x = x;
}

void text_set_y(text_t *text, double y) {
  text->y = y;
}

void text_set_anchor(text_t *text, char *anchor) {
  text->anchor = anchor;
}

void text_set_color(text_t *text, char *color) {
  if (text->color != NULL) free(text->color);
  text->color = color;
}

void text_set_border_color(text_t *text, char *border_color) {
  if (text->border_color != NULL) free(text->border_color);
  text->border_color = border_color;
}

void text_set_ffam(text_t *text, char *ffam) {
  if (text->ffam != NULL) free(text->ffam);
  text->ffam = ffam;
}

void text_set_fweight(text_t *text, char *fweight) {
  if (text->fweight != NULL) free(text->fweight);
  text->fweight = fweight;
}

void text_set_fsize(text_t *text, char *fsize) {
  if (text->fsize != NULL) free(text->fsize);
  text->fsize = fsize;
}

void text_set_content(text_t *text, char *content) {
  if (text->content != NULL) free(text->content);
  text->content = content;
}

size_t text_get_id(text_t *text) {
  return text->id;
}

double text_get_x(text_t *text) {
  return text->x;
}

double text_get_y(text_t *text) {
  return text->y;
}

char *text_get_anchor(text_t *text) {
  return text->anchor;
}

char *text_get_color(text_t *text) {
  return text->color;
}

char *text_get_border_color(text_t *text) {
  return text->border_color;
}

char *text_get_ffam(text_t *text) {
  return text->ffam;
}

char *text_get_fweight(text_t *text) {
  return text->fweight;
}

char *text_get_fsize(text_t *text) {
  return text->fsize;
}

char *text_get_content(text_t *text) {
  return text->content;
}

double text_get_area(text_t *text) {
  size_t len = strlen(text->content);
  return 20.0 * len;
}
