//
// Created by Luiz on 31/12/2021.
//

#include "../../../catch.hpp"
#include "../../Matrix/Matrix3x3.cpp"

using namespace KMath;

TEST_CASE("3x3 Matrix Creation and Access", "[Matrix3x3]")
{
    float constant = 3.1415936;
    Matrix3x3<float> matrix_a;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a02 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;
    float a12 = rand() % 100 * constant;
    float a20 = rand() % 100 * constant;
    float a21 = rand() % 100 * constant;
    float a22 = rand() % 100 * constant;

    SECTION("Setting Values and Checking them")
    {
        matrix_a.SetValueAt(a00, 0,0);
        matrix_a.SetValueAt(a01, 0,1);
        matrix_a.SetValueAt(a02, 0,2);
        matrix_a.SetValueAt(a10, 1,0);
        matrix_a.SetValueAt(a11, 1,1);
        matrix_a.SetValueAt(a12, 1,2);
        matrix_a.SetValueAt(a20, 2,0);
        matrix_a.SetValueAt(a21, 2,1);
        matrix_a.SetValueAt(a22, 2,2);

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);
    }
}

TEST_CASE("3x3 Matrix Add and Subtraction", "[Matrix3x3]")
{
    float constant = 3.1415936;

    Matrix3x3<float> matrix_a;
    Matrix3x3<float> matrix_b;
    Matrix3x3<float> matrix_result;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a02 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;
    float a12 = rand() % 100 * constant;
    float a20 = rand() % 100 * constant;
    float a21 = rand() % 100 * constant;
    float a22 = rand() % 100 * constant;

    float b00 = rand() % 100 * constant;
    float b01 = rand() % 100 * constant;
    float b02 = rand() % 100 * constant;
    float b10 = rand() % 100 * constant;
    float b11 = rand() % 100 * constant;
    float b12 = rand() % 100 * constant;
    float b20 = rand() % 100 * constant;
    float b21 = rand() % 100 * constant;
    float b22 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a02, 0,2);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);
    matrix_a.SetValueAt(a12, 1,2);
    matrix_a.SetValueAt(a20, 2,0);
    matrix_a.SetValueAt(a21, 2,1);
    matrix_a.SetValueAt(a22, 2,2);

    matrix_b.SetValueAt(b00, 0,0);
    matrix_b.SetValueAt(b01, 0,1);
    matrix_b.SetValueAt(b02, 0,2);
    matrix_b.SetValueAt(b10, 1,0);
    matrix_b.SetValueAt(b11, 1,1);
    matrix_b.SetValueAt(b12, 1,2);
    matrix_b.SetValueAt(b20, 2,0);
    matrix_b.SetValueAt(b21, 2,1);
    matrix_b.SetValueAt(b22, 2,2);

    SECTION("3x3 Adding Matrix")
    {
        matrix_result = (matrix_a + matrix_b);

        REQUIRE( matrix_result.GetValueAt(0,0) == (a00 + b00) );
        REQUIRE( matrix_result.GetValueAt(0,1) == (a01 + b01) );
        REQUIRE( matrix_result.GetValueAt(0,2) == (a02 + b02) );
        REQUIRE( matrix_result.GetValueAt(1,0) == (a10 + b10) );
        REQUIRE( matrix_result.GetValueAt(1,1) == (a11 + b11) );
        REQUIRE( matrix_result.GetValueAt(1,2) == (a12 + b12) );
        REQUIRE( matrix_result.GetValueAt(2,0) == (a20 + b20) );
        REQUIRE( matrix_result.GetValueAt(2,1) == (a21 + b21) );
        REQUIRE( matrix_result.GetValueAt(2,2) == (a22 + b22) );

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);

        REQUIRE (matrix_b.GetValueAt(0,0) == b00);
        REQUIRE (matrix_b.GetValueAt(0,1) == b01);
        REQUIRE (matrix_b.GetValueAt(0,2) == b02);
        REQUIRE (matrix_b.GetValueAt(1,0) == b10);
        REQUIRE (matrix_b.GetValueAt(1,1) == b11);
        REQUIRE (matrix_b.GetValueAt(1,2) == b12);
        REQUIRE (matrix_b.GetValueAt(2,0) == b20);
        REQUIRE (matrix_b.GetValueAt(2,1) == b21);
        REQUIRE (matrix_b.GetValueAt(2,2) == b22);
    }

    SECTION("2x2 Subtracting Matrix")
    {
        matrix_result = (matrix_a - matrix_b);

        REQUIRE( matrix_result.GetValueAt(0,0) == (a00 - b00) );
        REQUIRE( matrix_result.GetValueAt(0,1) == (a01 - b01) );
        REQUIRE( matrix_result.GetValueAt(0,2) == (a02 - b02) );
        REQUIRE( matrix_result.GetValueAt(1,0) == (a10 - b10) );
        REQUIRE( matrix_result.GetValueAt(1,1) == (a11 - b11) );
        REQUIRE( matrix_result.GetValueAt(1,2) == (a12 - b12) );
        REQUIRE( matrix_result.GetValueAt(2,0) == (a20 - b20) );
        REQUIRE( matrix_result.GetValueAt(2,1) == (a21 - b21) );
        REQUIRE( matrix_result.GetValueAt(2,2) == (a22 - b22) );

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);

        REQUIRE (matrix_b.GetValueAt(0,0) == b00);
        REQUIRE (matrix_b.GetValueAt(0,1) == b01);
        REQUIRE (matrix_b.GetValueAt(0,2) == b02);
        REQUIRE (matrix_b.GetValueAt(1,0) == b10);
        REQUIRE (matrix_b.GetValueAt(1,1) == b11);
        REQUIRE (matrix_b.GetValueAt(1,2) == b12);
        REQUIRE (matrix_b.GetValueAt(2,0) == b20);
        REQUIRE (matrix_b.GetValueAt(2,1) == b21);
        REQUIRE (matrix_b.GetValueAt(2,2) == b22);
    }
}

TEST_CASE("3x3 Matrix Multiplication", "[Matrix3x3]")
{
    float constant = 3.1415936;

    Matrix3x3<float> matrix_a;
    Matrix3x3<float> matrix_b;
    Matrix3x3<float> matrix_result;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a02 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;
    float a12 = rand() % 100 * constant;
    float a20 = rand() % 100 * constant;
    float a21 = rand() % 100 * constant;
    float a22 = rand() % 100 * constant;

    float b00 = rand() % 100 * constant;
    float b01 = rand() % 100 * constant;
    float b02 = rand() % 100 * constant;
    float b10 = rand() % 100 * constant;
    float b11 = rand() % 100 * constant;
    float b12 = rand() % 100 * constant;
    float b20 = rand() % 100 * constant;
    float b21 = rand() % 100 * constant;
    float b22 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a02, 0,2);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);
    matrix_a.SetValueAt(a12, 1,2);
    matrix_a.SetValueAt(a20, 2,0);
    matrix_a.SetValueAt(a21, 2,1);
    matrix_a.SetValueAt(a22, 2,2);

    matrix_b.SetValueAt(b00, 0,0);
    matrix_b.SetValueAt(b01, 0,1);
    matrix_b.SetValueAt(b02, 0,2);
    matrix_b.SetValueAt(b10, 1,0);
    matrix_b.SetValueAt(b11, 1,1);
    matrix_b.SetValueAt(b12, 1,2);
    matrix_b.SetValueAt(b20, 2,0);
    matrix_b.SetValueAt(b21, 2,1);
    matrix_b.SetValueAt(b22, 2,2);

    SECTION("Multiplication 3x3")
    {
        matrix_result = matrix_a * matrix_b;

        REQUIRE( matrix_result.GetValueAt(0,0) == ( a00 * b00 ) + ( a01 * b10 ) + ( a02 * b20 ) );
        REQUIRE( matrix_result.GetValueAt(0,1) == ( a00 * b01 ) + ( a01 * b11 ) + ( a02 * b21 ) );
        REQUIRE( matrix_result.GetValueAt(0,2) == ( a00 * b02 ) + ( a01 * b12 ) + ( a02 * b22 ) );
        REQUIRE( matrix_result.GetValueAt(1,0) == ( a10 * b00 ) + ( a11 * b10 ) + ( a12 * b20 ) );
        REQUIRE( matrix_result.GetValueAt(1,1) == ( a10 * b01 ) + ( a11 * b11 ) + ( a12 * b21 ) );
        REQUIRE( matrix_result.GetValueAt(1,2) == ( a10 * b02 ) + ( a11 * b12 ) + ( a12 * b22 ) );
        REQUIRE( matrix_result.GetValueAt(2,0) == ( a20 * b00 ) + ( a21 * b10 ) + ( a22 * b20 ) );
        REQUIRE( matrix_result.GetValueAt(2,1) == ( a20 * b01 ) + ( a21 * b11 ) + ( a22 * b21 ) );
        REQUIRE( matrix_result.GetValueAt(2,2) == ( a20 * b02 ) + ( a21 * b12 ) + ( a22 * b22 ) );

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);

        REQUIRE (matrix_b.GetValueAt(0,0) == b00);
        REQUIRE (matrix_b.GetValueAt(0,1) == b01);
        REQUIRE (matrix_b.GetValueAt(0,2) == b02);
        REQUIRE (matrix_b.GetValueAt(1,0) == b10);
        REQUIRE (matrix_b.GetValueAt(1,1) == b11);
        REQUIRE (matrix_b.GetValueAt(1,2) == b12);
        REQUIRE (matrix_b.GetValueAt(2,0) == b20);
        REQUIRE (matrix_b.GetValueAt(2,1) == b21);
        REQUIRE (matrix_b.GetValueAt(2,2) == b22);
    }
}

TEST_CASE("3x3 Matrix Identity Cases", "[Matrix3x3]")
{
    float constant = 3.1415936;

    Matrix3x3<float> matrix_a;
    Matrix3x3<float> matrix_ID;
    Matrix3x3<float> matrix_result;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a02 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;
    float a12 = rand() % 100 * constant;
    float a20 = rand() % 100 * constant;
    float a21 = rand() % 100 * constant;
    float a22 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a02, 0,2);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);
    matrix_a.SetValueAt(a12, 1,2);
    matrix_a.SetValueAt(a20, 2,0);
    matrix_a.SetValueAt(a21, 2,1);
    matrix_a.SetValueAt(a22, 2,2);

    matrix_ID = Matrix3x3<float>::Identity();

    SECTION("3x3 Identity Properties")
    {
        matrix_result = matrix_a * matrix_ID;

        REQUIRE (matrix_result.GetValueAt(0,0) == a00);
        REQUIRE (matrix_result.GetValueAt(0,1) == a01);
        REQUIRE (matrix_result.GetValueAt(0,2) == a02);
        REQUIRE (matrix_result.GetValueAt(1,0) == a10);
        REQUIRE (matrix_result.GetValueAt(1,1) == a11);
        REQUIRE (matrix_result.GetValueAt(1,2) == a12);
        REQUIRE (matrix_result.GetValueAt(2,0) == a20);
        REQUIRE (matrix_result.GetValueAt(2,1) == a21);
        REQUIRE (matrix_result.GetValueAt(2,2) == a22);

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);

    }
}

TEST_CASE("3x3 Matrix Determinant", "[Matrix3x3]")
{
    float constant = 3.1415936;

    Matrix3x3<float> matrix_a;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a02 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;
    float a12 = rand() % 100 * constant;
    float a20 = rand() % 100 * constant;
    float a21 = rand() % 100 * constant;
    float a22 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a02, 0,2);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);
    matrix_a.SetValueAt(a12, 1,2);
    matrix_a.SetValueAt(a20, 2,0);
    matrix_a.SetValueAt(a21, 2,1);
    matrix_a.SetValueAt(a22, 2,2);

    SECTION("3x3 Matrix Determinant")
    {
        float determinant = matrix_a.Determinant();

        REQUIRE( determinant ==  ( (a00 * a11 * a22) + (a01 * a12 * a20) + (a02 * a10 * a21) ) -
                                 ( (a00 * a12 * a21) + (a01 * a10 * a22) + (a02 * a11 * a20) ) );
        
        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);
    }
    
}

TEST_CASE("3x3 Matrix Inverse", "[Matrix3x3]")
{
    float constant = 3.1415936;

    Matrix3x3<float> matrix_a;
    Matrix3x3<float> matrix_inverse;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a02 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;
    float a12 = rand() % 100 * constant;
    float a20 = rand() % 100 * constant;
    float a21 = rand() % 100 * constant;
    float a22 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a02, 0,2);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);
    matrix_a.SetValueAt(a12, 1,2);
    matrix_a.SetValueAt(a20, 2,0);
    matrix_a.SetValueAt(a21, 2,1);
    matrix_a.SetValueAt(a22, 2,2);

    SECTION("3x3 Inverting a Matrix")
    {
        float determinant = matrix_a.Determinant();
        //Using Cramer's rule
        matrix_inverse = matrix_a.Inverse();

        if(determinant != 0)
        {

            float inverse_det = 1 / matrix_a.Determinant();

            REQUIRE (matrix_inverse.GetValueAt(0, 0) == a00 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(0, 1) == a01 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(0, 2) == a02 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(1, 0) == a10 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(1, 1) == a11 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(1, 2) == a12 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(2, 0) == a20 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(2, 1) == a21 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(2, 2) == a22 * inverse_det);
        }

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);
    }
}