#include <stdio.h>

#include "debug.h"
#include "value.h"


// disembles chunk
// goes through the whole chunk starting at offset 0
// uses disassemble instruction to know the offset based ont he size of the hunk
// and advance based on the size of chunk
void disassembleChunk(Chunk* chunk, const char* name) {
  printf("== %s ==\n", name);

  for (int offset = 0; offset < chunk->count;) {
    offset = disassembleInstruction(chunk, offset);
  }
}


// basically just increments the offset, and prints the name
// just a simplified way to boith print the name and advance the offset
// w/ out writing it one million times
static int simpleInstruction(const char* name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

void printValue(Value value) {
  printf("%g", value);
}

static int constantInstruction(const char* name, Chunk* chunk,
                               int offset) {
  uint8_t constant = chunk->code[offset + 1];
  printf("%-16s %4d '", name, constant);
  printValue(chunk->constants.values[constant]);
  printf("'\n");
  return offset + 2;
}

// dissaembling instructions
// the instruction is just the byte at the code in index offset
// you use a switch case  to return the instruction  using simple instruction
//
int disassembleInstruction(Chunk* chunk, int offset) {
  printf("%04d ", offset);

  uint8_t instruction = chunk->code[offset];
  switch (instruction) {
    case OP_CONSTANT:
        return constantInstruction("OP_CONSTANT", chunk, offset);
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);
    default:
      printf("Unknown opcode %d\n", instruction);
      return offset + 1;
  }
}
