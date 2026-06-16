use crate::chunk::{Chunk, OpCode};

pub fn disassembleChunk(chunk: &Chunk, name: &str) {
    println!("== {} ==", name);

    let mut offset = 0;
    while offset < chunk.code.len() {
        offset = disassembleInstruction(chunk, offset);
    }
}

pub fn disassembleInstruction(chunk: &Chunk, offset: usize) -> usize {
    print!("{:04} ", offset);

    let byte = chunk.code[offset];
    match OpCode::try_from(byte) {
        Ok(OpCode::OP_RETURN) => simpleInstruction("OP_RETURN", offset),
        Err(unknown) => {
            println!("Unknown opcode {}", unknown);
            offset + 1
        }
    }
}

pub fn simpleInstruction(name: &str, offset: usize) -> usize {
    println!("{}", name);
    offset + 1
}
