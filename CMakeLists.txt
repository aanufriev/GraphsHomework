cmake_minimum_required(VERSION 3.11)

project(graphs)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
    ListGraph.cpp
    MatrixGraph.cpp
    SetGraph.cpp
    ArcGraph.cpp
)

add_library(graph_lib STATIC ${SOURCE_FILES})

add_executable(test test.cpp)

target_link_libraries(test graph_lib)
