//
// Created by Luiz on 31/12/2021.
//

#include "../../../catch.hpp"
#include "../../Matrix/Matrix2x2.cpp"

using namespace KMath;

TEST_CASE("2x2 Matrix Creation and Access", "[Matrix2x2]")
{
    Matrix2x2<float> myMatrix;


}

TEST_CASE("2x2 Matrix Add and Subtraction", "[Matrix2x2]")
{
    float constant = 3.1415936;

    Matrix2x2<float> matrix_a;
    Matrix2x2<float> matrix_b;
    Matrix2x2<float> matrix_result;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;

    float b00 = rand() % 100 * constant;
    float b01 = rand() % 100 * constant;
    float b10 = rand() % 100 * constant;
    float b11 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);

    matrix_b.SetValueAt(b00, 0,0);
    matrix_b.SetValueAt(b01, 0,1);
    matrix_b.SetValueAt(b10, 1,0);
    matrix_b.SetValueAt(b11, 1,1);

    SECTION("Adding Matrix")
    {
        matrix_result = (matrix_a + matrix_b);

        REQUIRE( matrix_result.GetValueAt(0,0) == (a00 + b00) );
        REQUIRE( matrix_result.GetValueAt(0,1) == (a01 + b01) );
        REQUIRE( matrix_result.GetValueAt(1,0) == (a10 + b10) );
        REQUIRE( matrix_result.GetValueAt(1,1) == (a11 + b11) );

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);

        REQUIRE (matrix_b.GetValueAt(0,0) == b00);
        REQUIRE (matrix_b.GetValueAt(0,1) == b01);
        REQUIRE (matrix_b.GetValueAt(1,0) == b10);
        REQUIRE (matrix_b.GetValueAt(1,1) == b11);
    }

    SECTION("Subtracting Matrix")
    {
        matrix_result = (matrix_a - matrix_b);

        REQUIRE( matrix_result.GetValueAt(0,0) == (a00 - b00) );
        REQUIRE( matrix_result.GetValueAt(0,1) == (a01 - b01) );
        REQUIRE( matrix_result.GetValueAt(1,0) == (a10 - b10) );
        REQUIRE( matrix_result.GetValueAt(1,1) == (a11 - b11) );

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);

        REQUIRE (matrix_b.GetValueAt(0,0) == b00);
        REQUIRE (matrix_b.GetValueAt(0,1) == b01);
        REQUIRE (matrix_b.GetValueAt(1,0) == b10);
        REQUIRE (matrix_b.GetValueAt(1,1) == b11);
    }




}

TEST_CASE("2x2 Matrix Multiplication", "[Matrix2x2]")
{

}

TEST_CASE("2x2 Matrix Identity Cases", "[Matrix2x2]")
{

}

TEST_CASE("2x2 Matrix Determinant", "[Matrix2x2]")
{

}

TEST_CASE("2x2 Matrix Inverse", "[Matrix2x2]")
{

}

