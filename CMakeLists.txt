cmake_minimum_required(VERSION 3.20)
project(KaZeMathLib)

set(CMAKE_CXX_STANDARD 14)

add_library(KaZeMathLib library.cpp MathLib/Vector.cpp)

add_executable(my_lib_tests catch.hpp MathLib/Tests/MainTest.cpp MathLib/Tests/VectorTests.cpp)
target_link_libraries(my_lib_tests PRIVATE KaZeMathLib)
