type double Value;

pub enum OpCode {
    OP_RETURN,
}

impl TryFrom<u8> for OpCode {
    type Error = u8;

    fn try_from(byte: u8) -> Result<Self, Self::Error> {
        match byte {
            0 => Ok(OpCode::OP_RETURN),
            unknown => Err(unknown),
        }
    }
}

impl From<OpCode> for u8 {
    fn from(op: OpCode) -> u8 {
        match op {
            OpCode::OP_RETURN => 0,
        }
    }
}

pub struct Chunk {
    pub code: Vec<u8>,
    pub lines: Vec<Value>,
}

impl Chunk {
    pub fn new() -> Self {
        Chunk {
            code: Vec::new(),
        }
    }

    pub fn writeChunk(&mut self, byte: u8) {
        self.code.push(byte);
    }

    pub fn writeOp(&mut self, op: OpCode) {
        self.code.push(op.into());
    }
}
