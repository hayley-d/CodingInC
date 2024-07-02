cmake_minimum_required(VERSION 3.28)
project(COnwayGameOfLife)

set(CMAKE_CXX_STANDARD 17)

add_executable(COnwayGameOfLife main.cpp
        Grid.cpp
        Grid.h
        Cell.cpp
        Cell.h
        ansi_escapes.cpp
        ansi_escapes.h
        Life.h)
