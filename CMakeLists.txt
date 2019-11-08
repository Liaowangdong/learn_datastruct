cmake_minimum_required(VERSION 3.15)
project(learn_datastruct)

set(CMAKE_CXX_STANDARD 14)

include_directories(Header)

add_executable(learn_datastruct
        Header/vector.h
        main.cpp)
