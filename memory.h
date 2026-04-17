#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

// define GROW_CAPACITY
// return 8 if capacity is less than 8 otherwise reutrn capacity * 2
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

// define #GROW_ARRAY
// take in the type, the pointer, the oldCount and the newCount
// reallocate  array to basically make sure theres enough memory for the new
// array
// you have to typecast because reallocate returns a void pointer but we need to
// have a pointer to the array
#define GROW_ARRAY(type, pointer, oldCount, newCount)                          \
  (type *)reallocate(pointer, sizeof(type) * (oldCount),                       \
                     sizeof(type) * (newCount))

// define FREE_ARRAY
// take in the type, pointer, old count
// reallocate the old backign array using our helper function
#define FREE_ARRAY(type, pointer, oldCount)                                    \
  reallocate(pointer, sizeof(type) * (oldCount), 0)

// function we will use for memory management to reallocation
void *reallocate(void *pointer, size_t oldSize, size_t newSize);

#endif
