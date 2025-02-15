cmake_minimum_required(VERSION 3.28.3)
project(assignment1 CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(polynomial_integrate PolynomialIntegrate.cpp)
target_include_directories(polynomial_integrate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# first executable 
add_executable(unit_tests 
    UnitTests.cpp
)
target_link_libraries(unit_tests PUBLIC polynomial_integrate)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC polynomial_integrate)

# Include directories for header files
target_include_directories(unit_tests PRIVATE ${CMAKE_SOURCE_DIR})

# Link the math library for the unit tests
#target_link_libraries(unit_tests m)

