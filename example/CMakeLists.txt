cmake_minimum_required(VERSION 3.7)
PROJECT(lucidTest)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_PREFIX_PATH ..)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
set(CMAKE_LIBRARY_PATH ../lib)
set(CMAKE_INCLUDE_PATH ../include)

include_directories("../include")

add_executable(lucidTest lucidTest.cpp)

add_definitions(-std=c++11 -D_GLIBCXX_USE_NANOSLEEP)
