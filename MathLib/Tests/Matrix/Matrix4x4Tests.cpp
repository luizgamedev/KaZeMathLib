//
// Created by Luiz on 31/12/2021.
//

#include "../../../catch.hpp"
#include "../../Matrix/Matrix4x4.cpp"

using namespace KMath;

TEST_CASE("4x4 Matrix Creation and Access", "[Matrix4x4]")
{
    float constant = 3.1415936;
    Matrix4x4<float> matrix_a;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a02 = rand() % 100 * constant;
    float a03 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;
    float a12 = rand() % 100 * constant;
    float a13 = rand() % 100 * constant;
    float a20 = rand() % 100 * constant;
    float a21 = rand() % 100 * constant;
    float a22 = rand() % 100 * constant;
    float a23 = rand() % 100 * constant;
    float a30 = rand() % 100 * constant;
    float a31 = rand() % 100 * constant;
    float a32 = rand() % 100 * constant;
    float a33 = rand() % 100 * constant;

    SECTION("Setting Values and Checking them")
    {
        matrix_a.SetValueAt(a00, 0,0);
        matrix_a.SetValueAt(a01, 0,1);
        matrix_a.SetValueAt(a02, 0,2);
        matrix_a.SetValueAt(a03, 0,3);
        matrix_a.SetValueAt(a10, 1,0);
        matrix_a.SetValueAt(a11, 1,1);
        matrix_a.SetValueAt(a12, 1,2);
        matrix_a.SetValueAt(a13, 1,3);
        matrix_a.SetValueAt(a20, 2,0);
        matrix_a.SetValueAt(a21, 2,1);
        matrix_a.SetValueAt(a22, 2,2);
        matrix_a.SetValueAt(a23, 2,3);
        matrix_a.SetValueAt(a30, 3,0);
        matrix_a.SetValueAt(a31, 3,1);
        matrix_a.SetValueAt(a32, 3,2);
        matrix_a.SetValueAt(a33, 3,3);


        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(0,3) == a03);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(1,3) == a13);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);
        REQUIRE (matrix_a.GetValueAt(2,3) == a23);
        REQUIRE (matrix_a.GetValueAt(3,0) == a30);
        REQUIRE (matrix_a.GetValueAt(3,1) == a31);
        REQUIRE (matrix_a.GetValueAt(3,2) == a32);
        REQUIRE (matrix_a.GetValueAt(3,3) == a33);
    }
}

TEST_CASE("4x4 Matrix Add and Subtraction", "[Matrix4x4]")
{
    float constant = 3.1415936;

    Matrix4x4<float> matrix_a;
    Matrix4x4<float> matrix_b;
    Matrix4x4<float> matrix_result;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a02 = rand() % 100 * constant;
    float a03 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;
    float a12 = rand() % 100 * constant;
    float a13 = rand() % 100 * constant;
    float a20 = rand() % 100 * constant;
    float a21 = rand() % 100 * constant;
    float a22 = rand() % 100 * constant;
    float a23 = rand() % 100 * constant;
    float a30 = rand() % 100 * constant;
    float a31 = rand() % 100 * constant;
    float a32 = rand() % 100 * constant;
    float a33 = rand() % 100 * constant;

    float b00 = rand() % 100 * constant;
    float b01 = rand() % 100 * constant;
    float b02 = rand() % 100 * constant;
    float b03 = rand() % 100 * constant;
    float b10 = rand() % 100 * constant;
    float b11 = rand() % 100 * constant;
    float b12 = rand() % 100 * constant;
    float b13 = rand() % 100 * constant;
    float b20 = rand() % 100 * constant;
    float b21 = rand() % 100 * constant;
    float b22 = rand() % 100 * constant;
    float b23 = rand() % 100 * constant;
    float b30 = rand() % 100 * constant;
    float b31 = rand() % 100 * constant;
    float b32 = rand() % 100 * constant;
    float b33 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a02, 0,2);
    matrix_a.SetValueAt(a03, 0,3);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);
    matrix_a.SetValueAt(a12, 1,2);
    matrix_a.SetValueAt(a13, 1,3);
    matrix_a.SetValueAt(a20, 2,0);
    matrix_a.SetValueAt(a21, 2,1);
    matrix_a.SetValueAt(a22, 2,2);
    matrix_a.SetValueAt(a23, 2,3);
    matrix_a.SetValueAt(a30, 3,0);
    matrix_a.SetValueAt(a31, 3,1);
    matrix_a.SetValueAt(a32, 3,2);
    matrix_a.SetValueAt(a33, 3,3);

    matrix_b.SetValueAt(b00, 0,0);
    matrix_b.SetValueAt(b01, 0,1);
    matrix_b.SetValueAt(b02, 0,2);
    matrix_b.SetValueAt(b03, 0,3);
    matrix_b.SetValueAt(b10, 1,0);
    matrix_b.SetValueAt(b11, 1,1);
    matrix_b.SetValueAt(b12, 1,2);
    matrix_b.SetValueAt(b13, 1,3);
    matrix_b.SetValueAt(b20, 2,0);
    matrix_b.SetValueAt(b21, 2,1);
    matrix_b.SetValueAt(b22, 2,2);
    matrix_b.SetValueAt(b23, 2,3);
    matrix_b.SetValueAt(b30, 3,0);
    matrix_b.SetValueAt(b31, 3,1);
    matrix_b.SetValueAt(b32, 3,2);
    matrix_b.SetValueAt(b33, 3,3);

    SECTION("4x4 Adding Matrix")
    {
        matrix_result = (matrix_a + matrix_b);

        REQUIRE( matrix_result.GetValueAt(0,0) == (a00 + b00) );
        REQUIRE( matrix_result.GetValueAt(0,1) == (a01 + b01) );
        REQUIRE( matrix_result.GetValueAt(0,2) == (a02 + b02) );
        REQUIRE( matrix_result.GetValueAt(0,3) == (a03 + b03) );
        REQUIRE( matrix_result.GetValueAt(1,0) == (a10 + b10) );
        REQUIRE( matrix_result.GetValueAt(1,1) == (a11 + b11) );
        REQUIRE( matrix_result.GetValueAt(1,2) == (a12 + b12) );
        REQUIRE( matrix_result.GetValueAt(1,3) == (a13 + b13) );
        REQUIRE( matrix_result.GetValueAt(2,0) == (a20 + b20) );
        REQUIRE( matrix_result.GetValueAt(2,1) == (a21 + b21) );
        REQUIRE( matrix_result.GetValueAt(2,2) == (a22 + b22) );
        REQUIRE( matrix_result.GetValueAt(2,3) == (a23 + b23) );
        REQUIRE( matrix_result.GetValueAt(3,0) == (a30 + b30) );
        REQUIRE( matrix_result.GetValueAt(3,1) == (a31 + b31) );
        REQUIRE( matrix_result.GetValueAt(3,2) == (a32 + b32) );
        REQUIRE( matrix_result.GetValueAt(3,3) == (a33 + b33) );

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(0,3) == a03);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(1,3) == a13);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);
        REQUIRE (matrix_a.GetValueAt(2,3) == a23);
        REQUIRE (matrix_a.GetValueAt(3,0) == a30);
        REQUIRE (matrix_a.GetValueAt(3,1) == a31);
        REQUIRE (matrix_a.GetValueAt(3,2) == a32);
        REQUIRE (matrix_a.GetValueAt(3,3) == a33);

        REQUIRE (matrix_b.GetValueAt(0,0) == b00);
        REQUIRE (matrix_b.GetValueAt(0,1) == b01);
        REQUIRE (matrix_b.GetValueAt(0,2) == b02);
        REQUIRE (matrix_b.GetValueAt(0,3) == b03);
        REQUIRE (matrix_b.GetValueAt(1,0) == b10);
        REQUIRE (matrix_b.GetValueAt(1,1) == b11);
        REQUIRE (matrix_b.GetValueAt(1,2) == b12);
        REQUIRE (matrix_b.GetValueAt(1,3) == b13);
        REQUIRE (matrix_b.GetValueAt(2,0) == b20);
        REQUIRE (matrix_b.GetValueAt(2,1) == b21);
        REQUIRE (matrix_b.GetValueAt(2,2) == b22);
        REQUIRE (matrix_b.GetValueAt(2,3) == b23);
        REQUIRE (matrix_b.GetValueAt(3,0) == b30);
        REQUIRE (matrix_b.GetValueAt(3,1) == b31);
        REQUIRE (matrix_b.GetValueAt(3,2) == b32);
        REQUIRE (matrix_b.GetValueAt(3,3) == b33);
    }

    SECTION("2x2 Subtracting Matrix")
    {
        matrix_result = (matrix_a - matrix_b);

        REQUIRE( matrix_result.GetValueAt(0,0) == (a00 - b00) );
        REQUIRE( matrix_result.GetValueAt(0,1) == (a01 - b01) );
        REQUIRE( matrix_result.GetValueAt(0,2) == (a02 - b02) );
        REQUIRE( matrix_result.GetValueAt(0,3) == (a03 - b03) );
        REQUIRE( matrix_result.GetValueAt(1,0) == (a10 - b10) );
        REQUIRE( matrix_result.GetValueAt(1,1) == (a11 - b11) );
        REQUIRE( matrix_result.GetValueAt(1,2) == (a12 - b12) );
        REQUIRE( matrix_result.GetValueAt(1,3) == (a13 - b13) );
        REQUIRE( matrix_result.GetValueAt(2,0) == (a20 - b20) );
        REQUIRE( matrix_result.GetValueAt(2,1) == (a21 - b21) );
        REQUIRE( matrix_result.GetValueAt(2,2) == (a22 - b22) );
        REQUIRE( matrix_result.GetValueAt(2,3) == (a23 - b23) );
        REQUIRE( matrix_result.GetValueAt(3,0) == (a30 - b30) );
        REQUIRE( matrix_result.GetValueAt(3,1) == (a31 - b31) );
        REQUIRE( matrix_result.GetValueAt(3,2) == (a32 - b32) );
        REQUIRE( matrix_result.GetValueAt(3,3) == (a33 - b33) );

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(0,3) == a03);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(1,3) == a13);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);
        REQUIRE (matrix_a.GetValueAt(2,3) == a23);
        REQUIRE (matrix_a.GetValueAt(3,0) == a30);
        REQUIRE (matrix_a.GetValueAt(3,1) == a31);
        REQUIRE (matrix_a.GetValueAt(3,2) == a32);
        REQUIRE (matrix_a.GetValueAt(3,3) == a33);

        REQUIRE (matrix_b.GetValueAt(0,0) == b00);
        REQUIRE (matrix_b.GetValueAt(0,1) == b01);
        REQUIRE (matrix_b.GetValueAt(0,2) == b02);
        REQUIRE (matrix_b.GetValueAt(0,3) == b03);
        REQUIRE (matrix_b.GetValueAt(1,0) == b10);
        REQUIRE (matrix_b.GetValueAt(1,1) == b11);
        REQUIRE (matrix_b.GetValueAt(1,2) == b12);
        REQUIRE (matrix_b.GetValueAt(1,3) == b13);
        REQUIRE (matrix_b.GetValueAt(2,0) == b20);
        REQUIRE (matrix_b.GetValueAt(2,1) == b21);
        REQUIRE (matrix_b.GetValueAt(2,2) == b22);
        REQUIRE (matrix_b.GetValueAt(2,3) == b23);
        REQUIRE (matrix_b.GetValueAt(3,0) == b30);
        REQUIRE (matrix_b.GetValueAt(3,1) == b31);
        REQUIRE (matrix_b.GetValueAt(3,2) == b32);
        REQUIRE (matrix_b.GetValueAt(3,3) == b33);
    }

}

TEST_CASE("4x4 Matrix Multiplication", "[Matrix4x4]")
{
    float constant = 3.1415936;

    Matrix4x4<float> matrix_a;
    Matrix4x4<float> matrix_b;
    Matrix4x4<float> matrix_result;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a02 = rand() % 100 * constant;
    float a03 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;
    float a12 = rand() % 100 * constant;
    float a13 = rand() % 100 * constant;
    float a20 = rand() % 100 * constant;
    float a21 = rand() % 100 * constant;
    float a22 = rand() % 100 * constant;
    float a23 = rand() % 100 * constant;
    float a30 = rand() % 100 * constant;
    float a31 = rand() % 100 * constant;
    float a32 = rand() % 100 * constant;
    float a33 = rand() % 100 * constant;

    float b00 = rand() % 100 * constant;
    float b01 = rand() % 100 * constant;
    float b02 = rand() % 100 * constant;
    float b03 = rand() % 100 * constant;
    float b10 = rand() % 100 * constant;
    float b11 = rand() % 100 * constant;
    float b12 = rand() % 100 * constant;
    float b13 = rand() % 100 * constant;
    float b20 = rand() % 100 * constant;
    float b21 = rand() % 100 * constant;
    float b22 = rand() % 100 * constant;
    float b23 = rand() % 100 * constant;
    float b30 = rand() % 100 * constant;
    float b31 = rand() % 100 * constant;
    float b32 = rand() % 100 * constant;
    float b33 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a02, 0,2);
    matrix_a.SetValueAt(a03, 0,3);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);
    matrix_a.SetValueAt(a12, 1,2);
    matrix_a.SetValueAt(a13, 1,3);
    matrix_a.SetValueAt(a20, 2,0);
    matrix_a.SetValueAt(a21, 2,1);
    matrix_a.SetValueAt(a22, 2,2);
    matrix_a.SetValueAt(a23, 2,3);
    matrix_a.SetValueAt(a30, 3,0);
    matrix_a.SetValueAt(a31, 3,1);
    matrix_a.SetValueAt(a32, 3,2);
    matrix_a.SetValueAt(a33, 3,3);

    matrix_b.SetValueAt(b00, 0,0);
    matrix_b.SetValueAt(b01, 0,1);
    matrix_b.SetValueAt(b02, 0,2);
    matrix_b.SetValueAt(b03, 0,3);
    matrix_b.SetValueAt(b10, 1,0);
    matrix_b.SetValueAt(b11, 1,1);
    matrix_b.SetValueAt(b12, 1,2);
    matrix_b.SetValueAt(b13, 1,3);
    matrix_b.SetValueAt(b20, 2,0);
    matrix_b.SetValueAt(b21, 2,1);
    matrix_b.SetValueAt(b22, 2,2);
    matrix_b.SetValueAt(b23, 2,3);
    matrix_b.SetValueAt(b30, 3,0);
    matrix_b.SetValueAt(b31, 3,1);
    matrix_b.SetValueAt(b32, 3,2);
    matrix_b.SetValueAt(b33, 3,3);

    SECTION("Multiplication 4x4")
    {
        matrix_result = matrix_a * matrix_b;

        REQUIRE( matrix_result.GetValueAt(0,0) == ( a00 * b00 ) + ( a01 * b10 ) + ( a02 * b20 ) + ( a03 * b30 ) );
        REQUIRE( matrix_result.GetValueAt(0,1) == ( a00 * b01 ) + ( a01 * b11 ) + ( a02 * b21 ) + ( a03 * b31 ) );
        REQUIRE( matrix_result.GetValueAt(0,2) == ( a00 * b02 ) + ( a01 * b12 ) + ( a02 * b22 ) + ( a03 * b32 ) );
        REQUIRE( matrix_result.GetValueAt(0,3) == ( a00 * b03 ) + ( a01 * b13 ) + ( a02 * b23 ) + ( a03 * b33 ) );
        REQUIRE( matrix_result.GetValueAt(1,0) == ( a10 * b00 ) + ( a11 * b10 ) + ( a12 * b20 ) + ( a13 * b30 ) );
        REQUIRE( matrix_result.GetValueAt(1,1) == ( a10 * b01 ) + ( a11 * b11 ) + ( a12 * b21 ) + ( a13 * b31 ) );
        REQUIRE( matrix_result.GetValueAt(1,2) == ( a10 * b02 ) + ( a11 * b12 ) + ( a12 * b22 ) + ( a13 * b32 ) );
        REQUIRE( matrix_result.GetValueAt(1,3) == ( a10 * b03 ) + ( a11 * b13 ) + ( a12 * b23 ) + ( a13 * b33 ) );
        REQUIRE( matrix_result.GetValueAt(2,0) == ( a20 * b00 ) + ( a21 * b10 ) + ( a22 * b20 ) + ( a23 * b30 ) );
        REQUIRE( matrix_result.GetValueAt(2,1) == ( a20 * b01 ) + ( a21 * b11 ) + ( a22 * b21 ) + ( a23 * b31 ) );
        REQUIRE( matrix_result.GetValueAt(2,2) == ( a20 * b02 ) + ( a21 * b12 ) + ( a22 * b22 ) + ( a23 * b32 ) );
        REQUIRE( matrix_result.GetValueAt(2,3) == ( a20 * b03 ) + ( a21 * b13 ) + ( a22 * b23 ) + ( a23 * b33 ) );
        REQUIRE( matrix_result.GetValueAt(3,0) == ( a30 * b00 ) + ( a31 * b10 ) + ( a32 * b20 ) + ( a33 * b30 ) );
        REQUIRE( matrix_result.GetValueAt(3,1) == ( a30 * b01 ) + ( a31 * b11 ) + ( a32 * b21 ) + ( a33 * b31 ) );
        REQUIRE( matrix_result.GetValueAt(3,2) == ( a30 * b02 ) + ( a31 * b12 ) + ( a32 * b22 ) + ( a33 * b32 ) );
        REQUIRE( matrix_result.GetValueAt(3,3) == ( a30 * b03 ) + ( a31 * b13 ) + ( a32 * b23 ) + ( a33 * b33 ) );

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(0,3) == a03);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(1,3) == a13);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);
        REQUIRE (matrix_a.GetValueAt(2,3) == a23);
        REQUIRE (matrix_a.GetValueAt(3,0) == a30);
        REQUIRE (matrix_a.GetValueAt(3,1) == a31);
        REQUIRE (matrix_a.GetValueAt(3,2) == a32);
        REQUIRE (matrix_a.GetValueAt(3,3) == a33);

        REQUIRE (matrix_b.GetValueAt(0,0) == b00);
        REQUIRE (matrix_b.GetValueAt(0,1) == b01);
        REQUIRE (matrix_b.GetValueAt(0,2) == b02);
        REQUIRE (matrix_b.GetValueAt(0,3) == b03);
        REQUIRE (matrix_b.GetValueAt(1,0) == b10);
        REQUIRE (matrix_b.GetValueAt(1,1) == b11);
        REQUIRE (matrix_b.GetValueAt(1,2) == b12);
        REQUIRE (matrix_b.GetValueAt(1,3) == b13);
        REQUIRE (matrix_b.GetValueAt(2,0) == b20);
        REQUIRE (matrix_b.GetValueAt(2,1) == b21);
        REQUIRE (matrix_b.GetValueAt(2,2) == b22);
        REQUIRE (matrix_b.GetValueAt(2,3) == b23);
        REQUIRE (matrix_b.GetValueAt(3,0) == b30);
        REQUIRE (matrix_b.GetValueAt(3,1) == b31);
        REQUIRE (matrix_b.GetValueAt(3,2) == b32);
        REQUIRE (matrix_b.GetValueAt(3,3) == b33);

    }

}

TEST_CASE("4x4 Matrix Identity Cases", "[Matrix4x4]")
{
    float constant = 3.1415936;

    Matrix4x4<float> matrix_a;
    Matrix4x4<float> matrix_ID;
    Matrix4x4<float> matrix_result;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a02 = rand() % 100 * constant;
    float a03 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;
    float a12 = rand() % 100 * constant;
    float a13 = rand() % 100 * constant;
    float a20 = rand() % 100 * constant;
    float a21 = rand() % 100 * constant;
    float a22 = rand() % 100 * constant;
    float a23 = rand() % 100 * constant;
    float a30 = rand() % 100 * constant;
    float a31 = rand() % 100 * constant;
    float a32 = rand() % 100 * constant;
    float a33 = rand() % 100 * constant;

    float b00 = rand() % 100 * constant;
    float b01 = rand() % 100 * constant;
    float b02 = rand() % 100 * constant;
    float b03 = rand() % 100 * constant;
    float b10 = rand() % 100 * constant;
    float b11 = rand() % 100 * constant;
    float b12 = rand() % 100 * constant;
    float b13 = rand() % 100 * constant;
    float b20 = rand() % 100 * constant;
    float b21 = rand() % 100 * constant;
    float b22 = rand() % 100 * constant;
    float b23 = rand() % 100 * constant;
    float b30 = rand() % 100 * constant;
    float b31 = rand() % 100 * constant;
    float b32 = rand() % 100 * constant;
    float b33 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a02, 0,2);
    matrix_a.SetValueAt(a03, 0,3);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);
    matrix_a.SetValueAt(a12, 1,2);
    matrix_a.SetValueAt(a13, 1,3);
    matrix_a.SetValueAt(a20, 2,0);
    matrix_a.SetValueAt(a21, 2,1);
    matrix_a.SetValueAt(a22, 2,2);
    matrix_a.SetValueAt(a23, 2,3);
    matrix_a.SetValueAt(a30, 3,0);
    matrix_a.SetValueAt(a31, 3,1);
    matrix_a.SetValueAt(a32, 3,2);
    matrix_a.SetValueAt(a33, 3,3);

    matrix_ID = Matrix4x4<float>::Identity();

    SECTION("4x4 Identity Properties")
    {
        matrix_result = matrix_a * matrix_ID;

        REQUIRE (matrix_result.GetValueAt(0,0) == a00);
        REQUIRE (matrix_result.GetValueAt(0,1) == a01);
        REQUIRE (matrix_result.GetValueAt(0,2) == a02);
        REQUIRE (matrix_result.GetValueAt(0,3) == a03);
        REQUIRE (matrix_result.GetValueAt(1,0) == a10);
        REQUIRE (matrix_result.GetValueAt(1,1) == a11);
        REQUIRE (matrix_result.GetValueAt(1,2) == a12);
        REQUIRE (matrix_result.GetValueAt(1,3) == a13);
        REQUIRE (matrix_result.GetValueAt(2,0) == a20);
        REQUIRE (matrix_result.GetValueAt(2,1) == a21);
        REQUIRE (matrix_result.GetValueAt(2,2) == a22);
        REQUIRE (matrix_result.GetValueAt(2,3) == a23);
        REQUIRE (matrix_result.GetValueAt(3,0) == a30);
        REQUIRE (matrix_result.GetValueAt(3,1) == a31);
        REQUIRE (matrix_result.GetValueAt(3,2) == a32);
        REQUIRE (matrix_result.GetValueAt(3,3) == a33);

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(0,3) == a03);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(1,3) == a13);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);
        REQUIRE (matrix_a.GetValueAt(2,3) == a23);
        REQUIRE (matrix_a.GetValueAt(3,0) == a30);
        REQUIRE (matrix_a.GetValueAt(3,1) == a31);
        REQUIRE (matrix_a.GetValueAt(3,2) == a32);
        REQUIRE (matrix_a.GetValueAt(3,3) == a33);
    }

}

TEST_CASE("4x4 Matrix Determinant", "[Matrix4x4]")
{
    float constant = 3.1415936;

    Matrix4x4<float> matrix_a;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a02 = rand() % 100 * constant;
    float a03 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;
    float a12 = rand() % 100 * constant;
    float a13 = rand() % 100 * constant;
    float a20 = rand() % 100 * constant;
    float a21 = rand() % 100 * constant;
    float a22 = rand() % 100 * constant;
    float a23 = rand() % 100 * constant;
    float a30 = rand() % 100 * constant;
    float a31 = rand() % 100 * constant;
    float a32 = rand() % 100 * constant;
    float a33 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a02, 0,2);
    matrix_a.SetValueAt(a03, 0,3);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);
    matrix_a.SetValueAt(a12, 1,2);
    matrix_a.SetValueAt(a13, 1,3);
    matrix_a.SetValueAt(a20, 2,0);
    matrix_a.SetValueAt(a21, 2,1);
    matrix_a.SetValueAt(a22, 2,2);
    matrix_a.SetValueAt(a23, 2,3);
    matrix_a.SetValueAt(a30, 3,0);
    matrix_a.SetValueAt(a31, 3,1);
    matrix_a.SetValueAt(a32, 3,2);
    matrix_a.SetValueAt(a33, 3,3);

    SECTION("4x4 Matrix Determinant")
    {
        float determinant = matrix_a.Determinant();
        
        REQUIRE( determinant ==
                         a03 * a12 * a21 * a30 - a02 * a13 * a21 * a30 -
                         a03 * a11 * a22 * a30 + a01 * a13 * a22 * a30 +
                         a02 * a11 * a23 * a30 - a01 * a12 * a23 * a30 -
                         a03 * a12 * a20 * a31 + a02 * a13 * a20 * a31 +
                         a03 * a10 * a22 * a31 - a00 * a13 * a22 * a31 -
                         a02 * a10 * a23 * a31 + a00 * a12 * a23 * a31 +
                         a03 * a11 * a20 * a32 - a01 * a13 * a20 * a32 -
                         a03 * a10 * a21 * a32 + a00 * a13 * a21 * a32 +
                         a01 * a10 * a23 * a32 - a00 * a11 * a23 * a32 -
                         a02 * a11 * a20 * a33 + a01 * a12 * a20 * a33 +
                         a02 * a10 * a21 * a33 - a00 * a12 * a21 * a33 -
                         a01 * a10 * a22 * a33 + a00 * a11 * a22 * a33
        );

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(0,3) == a03);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(1,3) == a13);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);
        REQUIRE (matrix_a.GetValueAt(2,3) == a23);
        REQUIRE (matrix_a.GetValueAt(3,0) == a30);
        REQUIRE (matrix_a.GetValueAt(3,1) == a31);
        REQUIRE (matrix_a.GetValueAt(3,2) == a32);
        REQUIRE (matrix_a.GetValueAt(3,3) == a33);
    }
}

TEST_CASE("4x4 Matrix Inverse", "[Matrix4x4]")
{
    float constant = 3.1415936;

    Matrix4x4<float> matrix_a;
    Matrix4x4<float> matrix_inverse;

    float a00 = rand() % 100 * constant;
    float a01 = rand() % 100 * constant;
    float a02 = rand() % 100 * constant;
    float a03 = rand() % 100 * constant;
    float a10 = rand() % 100 * constant;
    float a11 = rand() % 100 * constant;
    float a12 = rand() % 100 * constant;
    float a13 = rand() % 100 * constant;
    float a20 = rand() % 100 * constant;
    float a21 = rand() % 100 * constant;
    float a22 = rand() % 100 * constant;
    float a23 = rand() % 100 * constant;
    float a30 = rand() % 100 * constant;
    float a31 = rand() % 100 * constant;
    float a32 = rand() % 100 * constant;
    float a33 = rand() % 100 * constant;

    matrix_a.SetValueAt(a00, 0,0);
    matrix_a.SetValueAt(a01, 0,1);
    matrix_a.SetValueAt(a02, 0,2);
    matrix_a.SetValueAt(a03, 0,3);
    matrix_a.SetValueAt(a10, 1,0);
    matrix_a.SetValueAt(a11, 1,1);
    matrix_a.SetValueAt(a12, 1,2);
    matrix_a.SetValueAt(a13, 1,3);
    matrix_a.SetValueAt(a20, 2,0);
    matrix_a.SetValueAt(a21, 2,1);
    matrix_a.SetValueAt(a22, 2,2);
    matrix_a.SetValueAt(a23, 2,3);
    matrix_a.SetValueAt(a30, 3,0);
    matrix_a.SetValueAt(a31, 3,1);
    matrix_a.SetValueAt(a32, 3,2);
    matrix_a.SetValueAt(a33, 3,3);

    SECTION("4x4 Inverting a Matrix")
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
            REQUIRE (matrix_inverse.GetValueAt(0, 3) == a03 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(1, 0) == a10 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(1, 1) == a11 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(1, 2) == a12 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(1, 3) == a13 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(2, 0) == a20 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(2, 1) == a21 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(2, 2) == a22 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(2, 3) == a23 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(3, 0) == a30 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(3, 1) == a31 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(3, 2) == a32 * inverse_det);
            REQUIRE (matrix_inverse.GetValueAt(3, 3) == a33 * inverse_det);

        }

        //Consistency checks
        REQUIRE (matrix_a.GetValueAt(0,0) == a00);
        REQUIRE (matrix_a.GetValueAt(0,1) == a01);
        REQUIRE (matrix_a.GetValueAt(0,2) == a02);
        REQUIRE (matrix_a.GetValueAt(0,3) == a03);
        REQUIRE (matrix_a.GetValueAt(1,0) == a10);
        REQUIRE (matrix_a.GetValueAt(1,1) == a11);
        REQUIRE (matrix_a.GetValueAt(1,2) == a12);
        REQUIRE (matrix_a.GetValueAt(1,3) == a13);
        REQUIRE (matrix_a.GetValueAt(2,0) == a20);
        REQUIRE (matrix_a.GetValueAt(2,1) == a21);
        REQUIRE (matrix_a.GetValueAt(2,2) == a22);
        REQUIRE (matrix_a.GetValueAt(2,3) == a23);
        REQUIRE (matrix_a.GetValueAt(3,0) == a30);
        REQUIRE (matrix_a.GetValueAt(3,1) == a31);
        REQUIRE (matrix_a.GetValueAt(3,2) == a32);
        REQUIRE (matrix_a.GetValueAt(3,3) == a33);
    }

}