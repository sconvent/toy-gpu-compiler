# Toy GPU Compiler
A Toy Compiler to compile a C-style language to NVPTX. It is partially based on a [User Guide](https://llvm.org/docs/NVPTXUsage.html) by the LLVM Project: 

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
- CUDA needs to be installed
- Run `make` in the `examples` directory. This will compile and run two examples.
- They are compiled to `.ptx` files which are loaded and executed in `main.cpp`, which also contains code to set up a CUDA context and example data.
- The examples are:
  - `addition.toy`: Adds two vector and stores it in a third vector. It is not optimized, but only used to check correctness
  - `saxpy.toy`: Performs a scaled vector addition. It is optimized to achieve a decent memory bandwidth usage (for a fun project)

### Example output
- Tested on a machine with an NVIDIA RTX 3090
- Note the achieved memory bandwidth of 388 GB/sec

Output logs:
```
Using CUDA Device [0]: NVIDIA GeForce RTX 3090
Device Compute Capability: 8.6

Starting Addition Example
Addition results (only the first 5 of 32):
0 + 0 = 0
2 + 4 = 6
4 + 8 = 12
6 + 12 = 18
8 + 16 = 24

Starting Saxpy Example
Time taken by saxpy kernel: 3235 microseconds
Total bytes read: 838860800
Total bytes written: 419430400
Achieved memory bandwidth: 388 GB/sec
Saxpy results (only the first 5):
12.345 * 180.429 + 84.6931 = 2312.09
12.345 * 168.169 + 171.464 = 2247.51
12.345 * 195.775 + 42.4238 = 2459.26
12.345 * 71.9885 + 164.976 = 1053.67
12.345 * 59.6517 + 118.964 = 855.364
```
