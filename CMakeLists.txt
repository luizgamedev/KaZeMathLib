cmake_minimum_required(VERSION 3.20)
project(KaZeMathLib)

set(CMAKE_CXX_STANDARD 14)

add_library(KaZeMathLib MathLib/Vector/Vector2D.cpp MathLib/Vector/Vector3D.cpp MathLib/Vector/Vector4D.cpp MathLib/Matrix/Matrix2x2.cpp MathLib/Matrix/Matrix3x3.cpp MathLib/Matrix/Matrix4x4.cpp)

add_executable(my_lib_tests catch.hpp MathLib/Tests/MainTest.cpp MathLib/Tests/Vector/Vector2DTests.cpp MathLib/Tests/Vector/Vector3DTests.cpp MathLib/Tests/Vector/Vector4DTests.cpp MathLib/Tests/Matrix/Matrix3x3Tests.cpp MathLib/Tests/Matrix/Matrix2x2Tests.cpp MathLib/Tests/Matrix/Matrix4x4Tests.cpp)
target_link_libraries(my_lib_tests PRIVATE KaZeMathLib)
