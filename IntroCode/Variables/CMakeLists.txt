cmake_minimum_required(VERSION 3.28)
project(variablePractice)

set(CMAKE_CXX_STANDARD 17)

add_executable(variablePractice main.cpp
        Entity.cpp
        Entity.h
        Url.cpp
        Url.h)
