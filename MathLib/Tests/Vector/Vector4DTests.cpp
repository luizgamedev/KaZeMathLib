//
// Created by Luiz on 29/12/2021.
//

#include "../../../catch.hpp"
#include "../../Vector/Vector4D.cpp"

using namespace KMath;

TEST_CASE("Creating Vector 4 float",  "[Vec4]")
{
    SECTION("Assigning Values")
    {

        Vec4<float> myFloatVec(0.5f, 1.5f, 2.5f, 9.9f);

        REQUIRE(myFloatVec.x == 0.5f);
        REQUIRE(myFloatVec.y == 1.5f);
        REQUIRE(myFloatVec.z == 2.5f);
        REQUIRE(myFloatVec.w == 9.9f);

        myFloatVec.x = -200000.0f;
        myFloatVec.y = 20.0f;
        myFloatVec.z = -9999.0f;
        myFloatVec.w = 666.0f;


        REQUIRE(myFloatVec.x == -200000.0f);
        REQUIRE(myFloatVec.y == 20.0f);
        REQUIRE(myFloatVec.z == -9999.0f);
        REQUIRE(myFloatVec.w == 666.0f);
    }

    SECTION("Doing some operations")
    {
        Vec4<float> myFloatVec(0.5f, 1.5f, 2.5f, 9.9f);
        Vec4<float> anotherVector;
        anotherVector = myFloatVec;

        REQUIRE(myFloatVec.x == 0.5f);
        REQUIRE(myFloatVec.y == 1.5f);
        REQUIRE(myFloatVec.z == 2.5f);
        REQUIRE(myFloatVec.w == 9.9f);

        REQUIRE(anotherVector.x == 0.5f);
        REQUIRE(anotherVector.y == 1.5f);
        REQUIRE(anotherVector.z == 2.5f);
        REQUIRE(anotherVector.w == 9.9f);

        anotherVector = anotherVector + Vec4<float>(2,3, 4, 0);

        REQUIRE(anotherVector.x == 2.5f);
        REQUIRE(anotherVector.y == 4.5f);
        REQUIRE(anotherVector.z == 6.5f);
        REQUIRE(anotherVector.w == 9.9f);

        anotherVector = anotherVector - Vec4<float>(5.4f,9.3f, 2.2f, 0.2f);

        REQUIRE(anotherVector.x == -2.9f);
        REQUIRE(anotherVector.y == -4.8f);
        REQUIRE(anotherVector.z == 4.3f);
        REQUIRE(anotherVector.w == 9.7f);

        anotherVector = anotherVector * 2;

        REQUIRE(anotherVector.x == -5.8f);
        REQUIRE(anotherVector.y == -9.6f);
        REQUIRE(anotherVector.z == 8.6f);
        REQUIRE(anotherVector.w == 19.4f);
    }

    SECTION("Vector Consistency")
    {
        Vec4<float> vec_result;
        Vec4<float> vec_a(10.0f, 10.0f, 10.0f, 10.0f);
        Vec4<float> vec_b(5.0f,5.0f, 5.0f, 5.0f);

        vec_result = vec_a + vec_b;

        REQUIRE(vec_a.x == 10.0f);
        REQUIRE(vec_a.y == 10.0f);
        REQUIRE(vec_a.z == 10.0f);
        REQUIRE(vec_a.w == 10.0f);

        REQUIRE(vec_b.x == 5.0f);
        REQUIRE(vec_b.y == 5.0f);
        REQUIRE(vec_b.z == 5.0f);
        REQUIRE(vec_b.w == 5.0f);

        REQUIRE(vec_result.x == 15.0f);
        REQUIRE(vec_result.y == 15.0f);
        REQUIRE(vec_result.z == 15.0f);
        REQUIRE(vec_result.w == 15.0f);

        vec_result = vec_a - vec_b;

        REQUIRE(vec_a.x == 10.0f);
        REQUIRE(vec_a.y == 10.0f);
        REQUIRE(vec_a.z == 10.0f);
        REQUIRE(vec_a.w == 10.0f);

        REQUIRE(vec_b.x == 5.0f);
        REQUIRE(vec_b.y == 5.0f);
        REQUIRE(vec_b.z == 5.0f);
        REQUIRE(vec_b.w == 5.0f);

        REQUIRE(vec_result.x == 5.0f);
        REQUIRE(vec_result.y == 5.0f);
        REQUIRE(vec_result.z == 5.0f);
        REQUIRE(vec_result.w == 5.0f);

        vec_result = vec_b * 2;

        REQUIRE(vec_b.x == 5.0f);
        REQUIRE(vec_b.y == 5.0f);
        REQUIRE(vec_b.z == 5.0f);
        REQUIRE(vec_b.w == 5.0f);

        REQUIRE(vec_result.x == 10.0f);
        REQUIRE(vec_result.y == 10.0f);
        REQUIRE(vec_result.z == 10.0f);
        REQUIRE(vec_result.w == 10.0f);

        vec_result = vec_a / 2;

        REQUIRE(vec_a.x == 10.0f);
        REQUIRE(vec_a.y == 10.0f);
        REQUIRE(vec_a.z == 10.0f);
        REQUIRE(vec_a.w == 10.0f);

        REQUIRE(vec_result.x == 5.0f);
        REQUIRE(vec_result.y == 5.0f);
        REQUIRE(vec_result.z == 5.0f);
        REQUIRE(vec_result.w == 5.0f);
    }
}

TEST_CASE("Vec 4 Magnitude",  "[Vec4]")
{
    float SimplePi = 3.1415976f;
    float x = (rand() % 100) * SimplePi;
    float y = (rand() % 100) * SimplePi;
    float z = (rand() % 100) * SimplePi;
    float w = (rand() % 100) * SimplePi;

    SECTION("Random operation")
    {

        Vec4<float> myVec(x, y, z, w);

        REQUIRE(myVec.Magnitude() == ((x * x) + (y * y) + (z * z) + (w * w)));
    }

    SECTION("Zero option")
    {
        Vec4<float> zeroVec;

        REQUIRE(zeroVec.Magnitude() == 0);
    }
}

TEST_CASE("Vec 4 SQRMagnitude",  "[Vec4]")
{
    float SimplePi = 3.1415976f;

    float x = (rand() % 100) * SimplePi;
    float y = (rand() % 100) * SimplePi;
    float z = (rand() % 100) * SimplePi;
    float w = (rand() % 100) * SimplePi;

    SECTION("Random operation")
    {

        Vec4<float> myVec(x, y, z, w);

        REQUIRE(myVec.SQRMagnitude() == sqrt(((x * x) + (y * y) + (z * z)+ (w * w))));
    }

    SECTION("Zero option")
    {
        Vec4<float> zeroVec;

        REQUIRE(zeroVec.Magnitude() == 0);
    }
}

TEST_CASE("Vec 4 Normalize",  "[Vec4]")
{
    float SimplePi = 3.1415976f;
    float x = (rand() % 100) * SimplePi;
    float y = (rand() % 100) * SimplePi;
    float z = (rand() % 100) * SimplePi;
    float w = (rand() % 100) * SimplePi;

    SECTION("Random operation")
    {

        Vec4<float> myVec(x, y, z, w);

        REQUIRE(myVec.Normalize() == (myVec / sqrt((x*x) + (y*y) + (z*z) + (w*w))));
    }

    SECTION("Zero option")
    {
        Vec4<float> zeroVec;
        zeroVec.Normalize();

        REQUIRE(zeroVec.x == 0.0f);
        REQUIRE(zeroVec.y == 0.0f);
        REQUIRE(zeroVec.z == 0.0f);
        REQUIRE(zeroVec.w == 0.0f);
    }
}

TEST_CASE("Vec 4 Dot",  "[Vec4]")
{
    float SimplePi = 3.1415976f;
    float ax = (rand() % 100) * SimplePi;
    float ay = (rand() % 100) * SimplePi;
    float az = (rand() % 100) * SimplePi;
    float aw = (rand() % 100) * SimplePi;

    float bx = (rand() % 100) * SimplePi;
    float by = (rand() % 100) * SimplePi;
    float bz = (rand() % 100) * SimplePi;
    float bw = (rand() % 100) * SimplePi;

    SECTION("Random operation")
    {

        Vec4<float> vec_1(ax, ay, az, aw);
        Vec4<float> vec_2(bx, by, bz, bw);

        REQUIRE(vec_1.Dot(vec_2) == ( ax*bx + ay*by + az*bz + aw*bw));
    }

    SECTION("Zero option")
    {
        Vec4<float> vec_zero_1(0.0f, 0.0f, 0.0f, 0.0f);
        Vec4<float> vec_zero_2;

        REQUIRE(vec_zero_1.Dot(vec_zero_2) == 0.0f);
    }
}