#ifndef TEXT_H
#define TEXT_H

#include <stddef.h>

typedef struct text_t text_t;

text_t *text_init(size_t id, double x, double y, char anchor, char *color, char *border_color, char *ffam, char *fweight, char *fsize, char *content);
void text_destroy(void *text);

void text_set_x(text_t *text, double x);
void text_set_y(text_t *text, double y);
void text_set_anchor(text_t *text, char anchor);
void text_set_color(text_t *text, char *color);
void text_set_border_color(text_t *text, char *border_color);
void text_set_ffam(text_t *text, char *ffam);
void text_set_fweight(text_t *text, char *fweight);
void text_set_fsize(text_t *text, char *fsize);
void text_set_content(text_t *text, char *content);

size_t text_get_id(text_t *text);
double text_get_x(text_t *text);
double text_get_y(text_t *text);
char text_get_anchor(text_t *text);
char *text_get_color(text_t *text);
char *text_get_border_color(text_t *text);
char *text_get_ffam(text_t *text);
char *text_get_fweight(text_t *text);
char *text_get_fsize(text_t *text);
char *text_get_content(text_t *text);

double text_get_area(text_t *text);

#endif
