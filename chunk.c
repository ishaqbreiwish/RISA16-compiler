#include "chunk.h"
#include "memory.h"
#include <stdlib.h>

// initializes chunk
// set count to 0
// set capacity to 0
// set code to NULL (code is a pointer)
void initChunk(Chunk *chunk) {}

// free th ebacking array for the free chunk
// free the array
// intiialize the chunk
void freeChunk(Chunk *chunk) {}

// write to the chunk function
// first we need to see if the array has space for the new byte
// if capacity is too small for the next chunk then:
    // call GROW_CAPACITY to grow the capacity of the array and make sure to save it
    // to the current capacity
    // make the chunk's code equal to the return value of the GROW_ARRAY function
//
// once the chunk is big enough, make the val at the count in code (since thats
// the latest value in the array) equal to the byte
// increase the count of the chunk
//
// at a high level basically just grow the backing array if its full
// and if not just save the byte in the chunk
void writeChunk(Chunk *chunk, uint8_t byte) {}
