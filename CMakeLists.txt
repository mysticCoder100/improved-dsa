cmake_minimum_required(VERSION 3.10.0)
project(IMPROVED_DSA VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCES 
    src/main.cpp 
    src/lsq/impl.cpp
        src/heap/heap.cpp
        src/list/singly_list.cpp
        src/list/doubly_list.cpp
        src/tree/bst.cpp
        src/algo.cpp
)

add_executable(IMPROVED_DSA ${SOURCES})

target_include_directories(IMPROVED_DSA PRIVATE includes)

