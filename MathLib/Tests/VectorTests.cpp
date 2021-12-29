//
// Created by Luiz on 29/12/2021.
//

#include "../../catch.hpp"
#include "../Vector.cpp"

using namespace KMath;

TEST_CASE("Creating Vector2")
{
    Vec2<int> myIntVec;
    myIntVec.x = 10;
    myIntVec.y = 15;

    REQUIRE(myIntVec.x == 10);
    REQUIRE(myIntVec.y == 15);
}