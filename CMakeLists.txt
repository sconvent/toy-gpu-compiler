cmake_minimum_required(VERSION 3.0)
project(ToyGPUCompiler)

set(CMAKE_CXX_STANDARD 17)

# Add compiler flags
add_compile_options(
    -D_GNU_SOURCE
    -D__STDC_CONSTANT_MACROS
    -D__STDC_FORMAT_MACROS
    -D__STDC_LIMIT_MACROS
)

# Add include directories
include_directories(/usr/include/antlr4-runtime)
include_directories(/usr/lib/llvm-15/include)

link_directories(/usr/lib/llvm-15/lib)

# Gather all source files in the current directory and its subdirectories
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create an executable from the gathered source files
add_executable(tgc ${SOURCES})

target_link_libraries(tgc /usr/lib/x86_64-linux-gnu/libantlr4-runtime.a)
target_link_libraries(tgc LLVM-15)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
