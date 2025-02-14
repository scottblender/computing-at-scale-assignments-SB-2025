cmake_minimum_required(VERSION 3.28.3)
project(assignment1 CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# first executable 
add_executable(unit_tests 
    UnitTests.cpp
)

# Include directories for header files
target_include_directories(unit_tests PRIVATE ${CMAKE_SOURCE_DIR})

# Link the math library for the unit tests
target_link_libraries(unit_tests m)

