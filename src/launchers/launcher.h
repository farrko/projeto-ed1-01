#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <stddef.h>

#include "../shapes/shapes.h"
#include "loader.h"

typedef struct launcher_t launcher_t;

launcher_t *ln_init(size_t id, double x, double y);
void ln_attach_loader(launcher_t *launcher, size_t side, loader_t *loader);
void ln_shift_loaders(launcher_t *launcher, size_t side, size_t amount);
node_t *ln_get_loaded(launcher_t *launcher);
size_t ln_get_id(launcher_t *launcher);
double ln_get_x(launcher_t *launcher);
double ln_get_y(launcher_t *launcher);
void ln_set_loaded(launcher_t *launcher, node_t *loaded);
loader_t *ln_get_left_ld(launcher_t *launcher);
loader_t *ln_get_right_ld(launcher_t *launcher);

#endif
