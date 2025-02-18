cmake_minimum_required(VERSION 3.28.3)
project(assignment1 CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(integrate Integrate.cpp)
target_include_directories(integrate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# first executable 
add_executable(unit_tests 
    UnitTests.cpp
)
target_link_libraries(unit_tests PUBLIC integrate)

# second executable
add_executable(main main.cpp)
target_link_libraries(main PUBLIC integrate)

# third executable
add_executable(polynomialintegrate PolynomialIntegrate.cpp)
target_link_libraries(polynomialintegrate PUBLIC integrate)

# Include directories for header files
target_include_directories(unit_tests PRIVATE ${CMAKE_SOURCE_DIR})



