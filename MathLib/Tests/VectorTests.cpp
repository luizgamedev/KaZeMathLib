//
// Created by Luiz on 29/12/2021.
//

#include "../../catch.hpp"
#include "../Vector2D.cpp"

using namespace KMath;

TEST_CASE("Creating Vector2 int",  "[Vec2]")
{
    Vec2<int> myIntVec;
    myIntVec.x = 10;
    myIntVec.y = 15;

    REQUIRE(myIntVec.x == 10);
    REQUIRE(myIntVec.y == 15);

    SECTION("Doing some operations")
    {
        Vec2<int> anotherVector;
        anotherVector = myIntVec;

        REQUIRE(myIntVec.x == 10);
        REQUIRE(myIntVec.y == 15);

        REQUIRE(anotherVector.x == 10);
        REQUIRE(anotherVector.y == 15);

        anotherVector = anotherVector + Vec2<int>(2,3);

        REQUIRE(anotherVector.x == 12);
        REQUIRE(anotherVector.y == 18);

        anotherVector = anotherVector - Vec2<int>(5,9);

        REQUIRE(anotherVector.x == 7);
        REQUIRE(anotherVector.y == 9);

        anotherVector = anotherVector * 2;

        REQUIRE(anotherVector.x == 14);
        REQUIRE(anotherVector.y == 18);
    }
}

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
}