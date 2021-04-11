cmake_minimum_required(VERSION 3.17)
project(hash_table)

set(CMAKE_CXX_STANDARD 20)

include_directories(Generation)
include_directories(ClassHashTable)

add_executable(hash_table main.cpp ClassHashTable/HashTable.cpp Generation/Generation.cpp)