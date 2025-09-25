#ifndef LINE_H
#define LINE_H

#include <stddef.h>

typedef struct line_t line_t;

line_t *line_init(size_t id, double x1, double y1, double x2, double y2, char *color);
void line_destroy(void *line);

void line_set_x1(line_t *line, double x1);
void line_set_y1(line_t *line, double y1);
void line_set_x2(line_t *line, double x2);
void line_set_y2(line_t *line, double y2);
void line_set_color(line_t *line, char *color);

size_t line_get_id(line_t *line);
double line_get_x1(line_t *line);
double line_get_y1(line_t *line);
double line_get_x2(line_t *line);
double line_get_y2(line_t *line);
char *line_get_color(line_t *line);

double line_get_area(line_t *line);

#endif
