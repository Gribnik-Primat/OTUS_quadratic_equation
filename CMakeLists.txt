cmake_minimum_required(VERSION 3.10)
project(QuadraticEquationSolver)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    src/QuadraticEquationSolver.cpp
)

# Add test files
set(TEST_SOURCES
    test/QuadraticEquationSolverTest.cpp
)

# Include directories
include_directories(include)

# Create executable for tests
add_executable(QuadraticEquationSolverTest ${TEST_SOURCES} ${SOURCES})
target_link_libraries(QuadraticEquationSolverTest gtest gmock)
