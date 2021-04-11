cmake_minimum_required(VERSION 3.17)
project(Queue)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(Queue main.cpp src/Queue.cpp src/Queue.h)