cmake_minimum_required(VERSION 3.30)
project(sortArray)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(sortArray sortArray/main.cpp
        sortArray/Timer/Timer.cpp
        sortArray/Timer/Timer.h
        sortArray/Array/Array.h
        sortArray/Data/FileOperations.h
        sortArray/Array/FunctionalArray.h
        sortArray/Data/DataGeneration.h
        sortArray/help/Help.cpp
        sortArray/help/Help.h
        sortArray/boardGames/BoardGame.cpp
        sortArray/boardGames/BoardGame.h
)
