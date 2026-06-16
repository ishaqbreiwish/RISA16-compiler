// 1. Declare the modules
pub mod chunk;
pub mod debug;

// 2. Re-export their contents publicly at the root level
pub use chunk::*;
pub use debug::*;