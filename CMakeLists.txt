cmake_minimum_required(VERSION 3.30)
project(Sorting)

set(CMAKE_CXX_STANDARD 98)

add_executable(Sorting main.cpp
        Timer.cpp
        Timer.h
        Array.h
        FileLoader.h
        FunctionalArray.h
)
