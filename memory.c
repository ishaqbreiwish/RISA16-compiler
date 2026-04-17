#include <stdlib.h>

#include "memory.h"

// reallocate function
void *reallocate(void *pointer, size_t oldSize, size_t newSize) {
  // if the newsize is empty then allocate a new block
  if (newSize == 0) {
    free(pointer);
    return NULL;
  }

  // if
  void *result = realloc(pointer, newSize);
  if (result == NULL)
    exit(1);
  return result;
}
