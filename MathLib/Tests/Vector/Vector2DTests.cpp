//
// Created by Luiz on 29/12/2021.
//

#include "../../../catch.hpp"
#include "../../Vector/Vector2D.cpp"

using namespace KMath;

TEST_CASE("Creating Vector2 float",  "[Vec2]")
{
    Vec2<float> myFloatVec;
    myFloatVec.x = 0.5f;
    myFloatVec.y = 1.5f;

    REQUIRE(myFloatVec.x == 0.5f);
    REQUIRE(myFloatVec.y == 1.5f);

    SECTION("Doing some operations")
    {
        Vec2<float> anotherVector;
        anotherVector = myFloatVec;

        REQUIRE(myFloatVec.x == 0.5f);
        REQUIRE(myFloatVec.y == 1.5f);

        REQUIRE(anotherVector.x == 0.5f);
        REQUIRE(anotherVector.y == 1.5f);

        anotherVector = anotherVector + Vec2<float>(2,3);

        REQUIRE(anotherVector.x == 2.5f);
        REQUIRE(anotherVector.y == 4.5f);

        anotherVector = anotherVector - Vec2<float>(5.4f,9.3f);

        REQUIRE(anotherVector.x == -2.9f);
        REQUIRE(anotherVector.y == -4.8f);

        anotherVector = anotherVector * 2;

        REQUIRE(anotherVector.x == -5.8f);
        REQUIRE(anotherVector.y == -9.6f);
    }

    SECTION("Vector Consistency")
    {
        Vec2<float> vec_result;
        Vec2<float> vec_a(10.0f, 10.0f);
        Vec2<float> vec_b(5.0f,5.0f);

        vec_result = vec_a + vec_b;

        REQUIRE(vec_a.x == 10.0f);
        REQUIRE(vec_a.y == 10.0f);

        REQUIRE(vec_b.x == 5.0f);
        REQUIRE(vec_b.y == 5.0f);

        REQUIRE(vec_result.x == 15.0f);
        REQUIRE(vec_result.y == 15.0f);

        vec_result = vec_a - vec_b;

        REQUIRE(vec_a.x == 10.0f);
        REQUIRE(vec_a.y == 10.0f);

        REQUIRE(vec_b.x == 5.0f);
        REQUIRE(vec_b.y == 5.0f);

        REQUIRE(vec_result.x == 5.0f);
        REQUIRE(vec_result.y == 5.0f);

        vec_result = vec_b * 2;

        REQUIRE(vec_b.x == 5.0f);
        REQUIRE(vec_b.y == 5.0f);

        REQUIRE(vec_result.x == 10.0f);
        REQUIRE(vec_result.y == 10.0f);

        vec_result = vec_a / 2;

        REQUIRE(vec_a.x == 10.0f);
        REQUIRE(vec_a.y == 10.0f);

        REQUIRE(vec_result.x == 5.0f);
        REQUIRE(vec_result.y == 5.0f);
    }
}

TEST_CASE("Vec 2 Magnitude",  "[Vec2]")
{
    float SimplePi = 3.1415976f;
    float x = (rand() % 100) * SimplePi;
    float y = (rand() % 100) * SimplePi;

    SECTION("Random operation")
    {

        Vec2<float> myVec(x, y);

        REQUIRE(myVec.Magnitude() == ((x * x) + (y * y)));
    }

    SECTION("Zero option")
    {
        Vec2<float> zeroVec;

        REQUIRE(zeroVec.Magnitude() == 0);
    }

}


TEST_CASE("Vec 2 SQRMagnitude",  "[Vec2]")
{
    float SimplePi = 3.1415976f;
    float x = (rand() % 100) * SimplePi;
    float y = (rand() % 100) * SimplePi;

    SECTION("Random operation")
    {

        Vec2<float> myVec(x, y);

        REQUIRE(myVec.SQRMagnitude() == sqrt((x * x) + (y * y)));
    }

    SECTION("Zero option")
    {
        Vec2<float> zeroVec;

        REQUIRE(zeroVec.SQRMagnitude() == 0);
    }
}

TEST_CASE("Vec 2 Normalize",  "[Vec2]")
{
    float SimplePi = 3.1415976f;
    float x = (rand() % 100) * SimplePi;
    float y = (rand() % 100) * SimplePi;

    SECTION("Random operation")
    {

        Vec2<float> myVec(x, y);

        REQUIRE(myVec.Normalize() == (myVec / sqrt((x*x) + (y*y))));
    }

    SECTION("Zero option")
    {
        Vec2<float> zeroVec;
        zeroVec.Normalize();

        REQUIRE(zeroVec.x == 0.0f);
        REQUIRE(zeroVec.y == 0.0f);
    }
}

TEST_CASE("Vec 2 Dot",  "[Vec2]")
{
    float SimplePi = 3.1415976f;
    float ax = (rand() % 100) * SimplePi;
    float ay = (rand() % 100) * SimplePi;

    float bx = (rand() % 100) * SimplePi;
    float by = (rand() % 100) * SimplePi;

    SECTION("Random operation")
    {

        Vec2<float> vec_1(ax, ay);
        Vec2<float> vec_2(bx, by);

        REQUIRE(vec_1.Dot(vec_2) == ( ax*bx + ay*by));
    }

    SECTION("Zero option")
    {
        Vec2<float> vec_zero_1(0.0f, 0.0f);
        Vec2<float> vec_zero_2;

        REQUIRE(vec_zero_1.Dot(vec_zero_2) == 0.0f);
    }
}