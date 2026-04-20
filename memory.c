#include <stdlib.h>
#include <string.h>

#include "memory.h"

// reallocate function
void *reallocate(void *pointer, size_t oldSize, size_t newSize) {
  // if the newsize is empty then allocate a new block
  // do this by freeing a pointer and returning NULL
  //
  // the reason we do this is because if newsize is 0 that basically means
  // we want to delete the chunk

  // return the pointer returend by the realloc of pointer and newsize
  // check if relaloc is NULL ie. if the realloc failed
  //
  // this effectively covers the cases where newsize is smaller or bigger than
  // oldsize; if its bigger itll return a new, allocating a new block of memory
  // and copy the old data
  //  if its smaller itll return the same pointer

  // temp return
  return NULL;
}
