#ifndef SVG_H
#define SVG_H

#include "../shapes/circle.h"
#include "../shapes/rectangle.h"
#include "../shapes/line.h"
#include "../shapes/text.h"

typedef struct svg_t svg_t;

svg_t *svg_init(char *path);
void svg_close(svg_t *svg);

void svg_write_circle(svg_t *svg, circle_t *circle);
void svg_write_rectangle(svg_t *svg, rectangle_t *rect);
void svg_write_line(svg_t *svg, line_t *line);
void svg_write_text(svg_t *svg, text_t *text);

#endif
