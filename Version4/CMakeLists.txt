cmake_minimum_required(VERSION 3.20)
project(Version4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Version4
        nbproject/private/c_standard_headers_indexer.c
        nbproject/private/cpp_standard_headers_indexer.cpp
        main.cpp)
