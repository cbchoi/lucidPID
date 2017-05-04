cmake_minimum_required(VERSION 3.7)
PROJECT(LucidPID)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)
set(INCLUDE_PATH ../include)
file(GLOB HEADER_FILES "*.h")

MESSAGE(STATUS "${HEADER_FILES}")

add_library(LucidPID STATIC lucidDrvtCtrl.cpp
            lucidIntgCtrl.cpp
            lucidPDCtrl.cpp
            lucidPICtrl.cpp
            lucidPIDCtrl.cpp
            lucidPropCtrl.cpp)

add_definitions(-std=c++11 -D_GLIBCXX_USE_NANOSLEEP)

file(COPY ${HEADER_FILES} DESTINATION ${INCLUDE_PATH})