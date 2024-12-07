cmake_minimum_required(VERSION 3.10)

project(CHIP-8 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(CHIP-8 
    src/main.cpp
    src/chip8.cpp
    src/display.cpp
    src/mem.cpp
    src/register.cpp
    src/stack.cpp
    src/timer.cpp
)

target_include_directories(CHIP-8 PRIVATE ${CMAKE_SOURCE_DIR}/include)