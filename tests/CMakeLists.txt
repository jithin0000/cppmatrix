cmake_minimum_required(VERSION 3.10)
project(tests)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add Google Test subdirectory
add_subdirectory(lib/googletest)

# Include directories
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)  # Add this line to include Matrix.h

# Add the test executable
add_executable(test_matrix test_matrix.cpp)

# Link the test executable with Google Test and the Matrix library
target_link_libraries(test_matrix gtest gtest_main)
target_link_libraries(test_matrix matrix)
