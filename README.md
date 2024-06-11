# Toy GPU Compiler
A Toy Compiler to compile a C-style language to NVPTX

## Prerequisites
Under Ubuntu:
- CMake (`sudo apt install cmake`)
- A C++ compiler (will be picked up by CMake)
- Antlr 4 Runtime (`sudo apt install libantlr4-runtime-dev`)
- LLVM 15 (`sudo apt install llvm-15`)

To actually run compiled code, a CUDA installation is necessary:
- CUDA (`sudo apt install ...`)

## Compilation
- Create a cmake build directory: `mkdir build && cd build && cmake ..`
- Compile the project: `make`

## Examples
