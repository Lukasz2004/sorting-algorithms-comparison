cmake_minimum_required(VERSION 3.30)
project(Sorting)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Sorting main.cpp
        Timer.cpp
        Timer.h
        Array.h
        FileLoader.h
        FunctionalArray.h
)
