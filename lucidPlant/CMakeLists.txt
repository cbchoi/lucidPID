cmake_minimum_required(VERSION 3.7)
PROJECT(LucidPlant)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)

set(INCLUDE_PATH ../include)
file(GLOB HEADER_FILES "*.h")

add_definitions(-std=c++11 -D_GLIBCXX_USE_NANOSLEEP)

add_library(LucidPlant STATIC lucidPlant.cpp)
file(COPY ${HEADER_FILES} DESTINATION ${INCLUDE_PATH})
