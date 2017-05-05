cmake_minimum_required(VERSION 3.7)
PROJECT(lucidPIDController)

add_subdirectory(lucidPID)
add_subdirectory(lucidPlant)
add_subdirectory(example)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
file(COPY ./visualize DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
