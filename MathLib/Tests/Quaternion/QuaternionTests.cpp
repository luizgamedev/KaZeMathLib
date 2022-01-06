//
// Created by Luiz on 06/01/2022.
//

#include "../../../catch.hpp"
#include "../../Quaternion/Quaternion.cpp"

using namespace KMath;

TEST_CASE("Creating Quaternion",  "[Quaternion]")
{
    float constant = 3.1415956;
    float scalar = (rand() % 100) * constant;
    Vec3<float> vector ( (rand() % 100) * constant, (rand() % 100) * constant, (rand() % 100) * constant );

    SECTION("Creating and assigning a Quaternion")
    {
        Quaternion<float> q;
        q.scalar = scalar;
        q.vec = vector;
    }

    SECTION("Creation with Constructor")
    {
        Quaternion<float> q(scalar, vector);
    }

    SECTION("Creating and Copying")
    {
        Quaternion<float> q1(scalar, vector);
        Quaternion<float> q2(q1);
    }

}