cmake_minimum_required(VERSION 3.12)
project(A-Proyecto)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(A-Proyecto main.cpp Graph.cpp UnionFind.cpp probConnex.cpp GreatGraph.cpp)

