#include "loader.h"

#include <stdio.h>
#include <stdlib.h>

struct loader_t {
  size_t id;
  stack_t *s;
};

loader_t *ld_init(size_t id) {
  loader_t *loader = malloc(sizeof(loader_t));
  if (loader == NULL) {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }

  loader->id = id;

  stack_t *s = stack_init();
  loader->s = s;

  return loader;
}

node_t *ld_pop(loader_t *loader) {
  return stack_pop(loader->s);
}

void ld_push(loader_t *loader, node_t *node) {
  return stack_push(loader->s, node);
}

void ld_destroy(void *l) {
  loader_t *loader = (loader_t *) l;

  stack_destroy(loader->s);
  free(loader);
}

size_t ld_get_length(loader_t *loader) {
  return stack_get_length(loader->s);
}

size_t ld_get_id(loader_t *loader) {
  return loader->id;
}

