#ifndef LOADER_H
#define LOADER_H

#include <stddef.h>
#include "../datast/stack.h"

typedef struct loader_t loader_t;

loader_t *ld_init(size_t id);
node_t *ld_pop(loader_t *loader);
void ld_push(loader_t *loader, node_t *node);
void ld_destroy(void *l);
size_t ld_get_id(loader_t *loader);
size_t ld_get_length(loader_t *loader);

#endif
