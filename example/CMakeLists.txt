cmake_minimum_required(VERSION 3.7)
PROJECT(lucidTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
set(CUSTOM_LIBRARY_PATH ${CMAKE_BINARY_DIR}/lib)

include_directories(${CMAKE_BINARY_DIR}/include)
link_directories(${CMAKE_BINARY_DIR}/lib)

MESSAGE(STATUS ${LIBS})
add_definitions(-D_GLIBCXX_USE_NANOSLEEP)
add_executable(lucidTest lucidTest.cpp)
target_link_libraries(lucidTest ${CUSTOM_LIBRARY_PATH}/libLucidPID.a
                                ${CUSTOM_LIBRARY_PATH}/libLucidPlant.a)

include(debug_macro.cmake)