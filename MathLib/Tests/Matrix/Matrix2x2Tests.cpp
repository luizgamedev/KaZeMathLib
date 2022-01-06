//
// Created by Luiz on 31/12/2021.
//

#include "../../../catch.hpp"
#include "../../Matrix/Matrix2x2.cpp"

using namespace KMath;

TEST_CASE("2x2 Matrix Creation and Access", "[Matrix2x2]")
{
    float constant = 3.1415936;
    Matrix2x2<float> matrix_a;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;

    SECTION("Setting Values and Checking them")
    {
        matrix_a.SetValueAt(a00, 0,0);
        matrix_a.SetValueAt(a01, 0,1);
        matrix_a.SetValueAt(a10, 1,0);
        matrix_a.SetValueAt(a11, 1,1);

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
    }

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

    SECTION("2x2 Adding Matrix")
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

    SECTION("2x2 Subtracting Matrix")
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

    SECTION("Multiplication 2x2")
    {
        matrix_result = matrix_a * matrix_b;

        REQUIRE( matrix_result.GetValueAt(0,0) == (a00 * b00) + (a01 * b10) );
        REQUIRE( matrix_result.GetValueAt(0,1) == (a00 * b01) + (a01 * b11) );
        REQUIRE( matrix_result.GetValueAt(1,0) == (a10 * b00) + (a11 * b10) );
        REQUIRE( matrix_result.GetValueAt(1,1) == (a10 * b01) + (a11 * b11) );

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

TEST_CASE("2x2 Matrix Identity Cases", "[Matrix2x2]")
{
    float constant = 3.1415936;

    Matrix2x2<float> matrix_a;
    Matrix2x2<float> matrix_ID;
    Matrix2x2<float> matrix_result;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);

    matrix_ID = Matrix2x2<float>::Identity();

    SECTION("2x2 Identity Properties")
    {
        matrix_result = matrix_a * matrix_ID;

        REQUIRE (matrix_result.GetValueAt(0,0) == a00);
        REQUIRE (matrix_result.GetValueAt(0,1) == a01);
        REQUIRE (matrix_result.GetValueAt(1,0) == a10);
        REQUIRE (matrix_result.GetValueAt(1,1) == a11);

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);


    }
}

TEST_CASE("2x2 Matrix Determinant", "[Matrix2x2]")
{
    float constant = 3.1415936;

    Matrix2x2<float> matrix_a;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);

    SECTION("2x2 Matrix Determinant")
    {
        float determinant = matrix_a.Determinant();

        REQUIRE(determinant == ((a00 * a11) - (a01*a10)));

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
    }

}

TEST_CASE("2x2 Matrix Inverse", "[Matrix2x2]")
{
    float constant = 3.1415936;

    Matrix2x2<float> matrix_a;
    Matrix2x2<float> matrix_inverse;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);

    SECTION("2x2 Inverting a Matrix")
    {
        float determinant = matrix_a.Determinant();
        //Using Cramer's rule
        matrix_inverse = matrix_a.Inverse();

        if(determinant != 0)
        {

            float inverse_det = 1 / matrix_a.Determinant();

            REQUIRE (matrix_inverse.GetValueAt(0, 0) == a00 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(0, 1) == a01 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(1, 0) == a10 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(1, 1) == a11 * inverse_det);
        }

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);




    }
}

