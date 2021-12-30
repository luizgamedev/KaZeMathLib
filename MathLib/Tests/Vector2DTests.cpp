//
// Created by Luiz on 29/12/2021.
//

#include "../../catch.hpp"
#include "../Vector2D.cpp"

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
}

TEST_CASE("Magnitude",  "[Vec2]")
{

}

TEST_CASE("Normalize",  "[Vec2]")
{

}

TEST_CASE("Normalize",  "[Vec2]")
{

}