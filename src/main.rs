use risalang::{Chunk, OpCode, disassembleChunk};


fn main() {
    let mut chunk = Chunk::new();
    let testByte: u8 = 0;
    chunk.writeChunk(testByte);

    disassembleChunk(&chunk, "test chunk");
}
