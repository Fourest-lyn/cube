cmake_minimum_required(VERSION 3.17)
project(cube)

set(CMAKE_CXX_STANDARD 14)

add_executable(cube
        main.cpp
        block.h block.cpp
        cube.h cube.cpp
        error.h
        )