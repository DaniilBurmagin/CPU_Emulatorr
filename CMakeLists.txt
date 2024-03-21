cmake_minimum_required(VERSION 3.26)
project(CPU_Emulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)

add_executable(CPU_Emulator main.cpp
        lib/src/CPU.cpp
        lib/src/program.cpp
        lib/src/Commands.cpp
        lib/src/Parser.cpp
        lib/test/test.cpp)
