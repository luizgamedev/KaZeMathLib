//
// Created by Luiz on 29/12/2021.
//

#include "../../../catch.hpp"
#include "../../Vector/Vector3D.cpp"

using namespace KMath;

TEST_CASE("Creating Vector 3 float",  "[Vec3]")
{
    SECTION("Assigning Values")
    {

        Vec3<float> myFloatVec(0.5f, 1.5f, 2.5f);

        REQUIRE(myFloatVec.x == 0.5f);
        REQUIRE(myFloatVec.y == 1.5f);
        REQUIRE(myFloatVec.z == 2.5f);

        myFloatVec.x = -200000.0f;
        myFloatVec.y = 20.0f;
        myFloatVec.z = -9999.0f;


        REQUIRE(myFloatVec.x == -200000.0f);
        REQUIRE(myFloatVec.y == 20.0f);
        REQUIRE(myFloatVec.z == -9999.0f);
    }

    SECTION("Doing some operations")
    {
        Vec3<float> myFloatVec(0.5f, 1.5f, 2.5f);
        Vec3<float> anotherVector;
        anotherVector = myFloatVec;

        REQUIRE(myFloatVec.x == 0.5f);
        REQUIRE(myFloatVec.y == 1.5f);
        REQUIRE(myFloatVec.z == 2.5f);

        REQUIRE(anotherVector.x == 0.5f);
        REQUIRE(anotherVector.y == 1.5f);
        REQUIRE(anotherVector.z == 2.5f);

        anotherVector = anotherVector + Vec3<float>(2,3, 4);

        REQUIRE(anotherVector.x == 2.5f);
        REQUIRE(anotherVector.y == 4.5f);
        REQUIRE(anotherVector.z == 6.5f);

        anotherVector = anotherVector - Vec3<float>(5.4f,9.3f, 2.2f);

        REQUIRE(anotherVector.x == -2.9f);
        REQUIRE(anotherVector.y == -4.8f);
        REQUIRE(anotherVector.z == 4.3f);

        anotherVector = anotherVector * 2;

        REQUIRE(anotherVector.x == -5.8f);
        REQUIRE(anotherVector.y == -9.6f);
        REQUIRE(anotherVector.z == 8.6f);
    }
}

TEST_CASE("Vec 3 Magnitude",  "[Vec3]")
{
    float SimplePi = 3.1415976f;
    float x = (rand() % 100) * SimplePi;
    float y = (rand() % 100) * SimplePi;
    float z = (rand() % 100) * SimplePi;

    SECTION("Random operation")
    {

        Vec3<float> myVec(x, y, z);

        REQUIRE(myVec.Magnitude() == ((x * x) + (y * y) + (z * z)));
    }

    SECTION("Zero option")
    {
        Vec3<float> zeroVec;

        REQUIRE(zeroVec.Magnitude() == 0);
    }

}

TEST_CASE("Vec 3 SQRMagnitude",  "[Vec3]")
{
    float SimplePi = 3.1415976f;

    float x = (rand() % 100) * SimplePi;
    float y = (rand() % 100) * SimplePi;
    float z = (rand() % 100) * SimplePi;

    SECTION("Random operation")
    {

        Vec3<float> myVec(x, y, z);

        REQUIRE(myVec.SQRMagnitude() == sqrt(((x * x) + (y * y) + (z * z))));
    }

    SECTION("Zero option")
    {
        Vec3<float> zeroVec;

        REQUIRE(zeroVec.Magnitude() == 0);
    }
}

TEST_CASE("Vec 3 Normalize",  "[Vec3]")
{
    float SimplePi = 3.1415976f;
    float x = (rand() % 100) * SimplePi;
    float y = (rand() % 100) * SimplePi;
    float z = (rand() % 100) * SimplePi;

    SECTION("Random operation")
    {

        Vec3<float> myVec(x, y, z);

        REQUIRE(myVec.Normalize() == (myVec / sqrt((x*x) + (y*y) + (z*z))));
    }

    SECTION("Zero option")
    {
        Vec3<float> zeroVec;
        zeroVec.Normalize();

        REQUIRE(zeroVec.x == 0.0f);
        REQUIRE(zeroVec.y == 0.0f);
        REQUIRE(zeroVec.z == 0.0f);
    }
}

TEST_CASE("Vec 3 Dot",  "[Vec3]")
{
    float SimplePi = 3.1415976f;
    float ax = (rand() % 100) * SimplePi;
    float ay = (rand() % 100) * SimplePi;
    float az = (rand() % 100) * SimplePi;

    float bx = (rand() % 100) * SimplePi;
    float by = (rand() % 100) * SimplePi;
    float bz = (rand() % 100) * SimplePi;

    SECTION("Random operation")
    {

        Vec3<float> vec_1(ax, ay, az);
        Vec3<float> vec_2(bx, by, bz);

        REQUIRE(vec_1.Dot(vec_2) == ( ax*bx + ay*by + az*bz));
    }

    SECTION("Zero option")
    {
        Vec3<float> vec_zero_1(0.0f, 0.0f, 0.0f);
        Vec3<float> vec_zero_2;

        REQUIRE(vec_zero_1.Dot(vec_zero_2) == 0.0f);
    }
}

TEST_CASE("Vec 3 Cross",  "[Vec3]")
{
    float SimplePi = 3.1415976f;
    float ax = (rand() % 100) * SimplePi;
    float ay = (rand() % 100) * SimplePi;
    float az = (rand() % 100) * SimplePi;

    float bx = (rand() % 100) * SimplePi;
    float by = (rand() % 100) * SimplePi;
    float bz = (rand() % 100) * SimplePi;

    SECTION("Random operation")
    {

        Vec3<float> vec_1(ax, ay, az);
        Vec3<float> vec_2(bx, by, bz);

        Vec3<float> cross = vec_1.Cross(vec_2);

        REQUIRE(cross == Vec3<float>((ay*bz) - (az*by), (az*bx) - (ax*bz), (ax*by) - (ay*bx)));
    }

    SECTION("Zero option")
    {
        Vec3<float> vec_zero_1(0.0f, 0.0f, 0.0f);
        Vec3<float> vec_zero_2;

        REQUIRE(vec_zero_1.Cross(vec_zero_2) == Vec3<float>(0.0f,0.0f,0.0f));
    }
}