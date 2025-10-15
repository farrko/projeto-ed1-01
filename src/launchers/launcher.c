#include "launcher.h"
#include "../datast/linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct launcher_t {
  size_t id;
  double x, y;
  node_t *loaded;
  loader_t *leftl;
  loader_t *rightl;
};

launcher_t *ln_init(size_t id, double x, double y) {
  launcher_t *launcher = malloc(sizeof(launcher_t));
  if (launcher == NULL) {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }

  launcher->id = id;
  launcher->x = x;
  launcher->y = y;
  launcher->loaded = NULL;
  launcher->leftl = NULL;
  launcher->rightl = NULL;

  return launcher;
}

void ln_attach_loader(launcher_t *launcher, size_t side, loader_t *loader) {
  if (launcher == NULL || side >= 2) return;

  if (!side) {
    launcher->leftl = loader;
  } else launcher->rightl = loader;
}

void ln_shift_loaders(launcher_t *launcher, size_t side, size_t amount) {
  if (launcher == NULL || launcher->leftl == NULL || launcher->rightl == NULL || side >= 2) return;

  if (!side) {
    for (size_t i = 0; i < amount; i++) {
      if (launcher->loaded != NULL) ld_push(launcher->rightl, launcher->loaded);
      launcher->loaded = ld_pop(launcher->leftl);
    }
  } else {
    for (size_t i = 0; i < amount; i++) {
      if (launcher->loaded != NULL) ld_push(launcher->leftl, launcher->loaded); 
      launcher->loaded = ld_pop(launcher->rightl);
    }
  }
}

loader_t *ln_get_left_ld(launcher_t *launcher) {
  return launcher->leftl;
}

loader_t *ln_get_right_ld(launcher_t *launcher) {
  return launcher->rightl;
}

node_t *ln_get_loaded(launcher_t *launcher) {
  return launcher->loaded;
}

size_t ln_get_id(launcher_t *launcher) {
  return launcher->id;
}

double ln_get_x(launcher_t *launcher) {
  return launcher->x;
}

double ln_get_y(launcher_t *launcher) {
  return launcher->y;
}

void ln_set_loaded(launcher_t *launcher, node_t *loaded) {
  launcher->loaded = loaded;
}
