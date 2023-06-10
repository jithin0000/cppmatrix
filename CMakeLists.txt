cmake_minimum_required(VERSION 3.5)

project(matrix_library)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCES src/matrix.h)
add_library(matrix ${SOURCES})
set_target_properties(matrix PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(tests)



