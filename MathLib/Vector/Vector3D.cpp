//
// Created by Luiz on 30/12/2021.
//

#ifndef KAZEMATHLIB_VECTOR3D_CPP
#define KAZEMATHLIB_VECTOR3D_CPP

#include <iostream>
#include "Vector2D.cpp"

using namespace std;

namespace KMath
{

template <typename T, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
class Vec3
{
public:
    T x;
    T y;
    T z;

    //Constructors
    Vec3() : x(0), y(0), z(0) {}
    Vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
    Vec3(const Vec3& _vec) : x(_vec.x), y(_vec.y), z(_vec.z) {}
    Vec3(const KMath::Vec2<T>& _vec, T _z = 0) : x(_vec.x), y(_vec.y), z(_z) {}

    //Print Overload
    friend ostream& operator<<(ostream& os, const Vec3& _vec)
    {
        os << '{' << _vec.x << ',' << _vec.y  << ',' << _vec.z << '}';
        return os;
    }

    //Operators Overloading
    Vec3<T>& operator=(const Vec3<T>& other)
    {
        //Self Copy Guard
        if(this == &other)
        {
            return *this;
        }

        this->x = other.x;
        this->y = other.y;
        this->z = other.z;

        return *this;
    }

    friend Vec3<T> operator+(const Vec3<T>& lhs, const Vec3<T>& rhs)
    {
        Vec3<T> result(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
        return result;
    }

    friend Vec3<T> operator-(const Vec3<T>& lhs, const Vec3<T>& rhs)
    {
        Vec3<T> result(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
        return result;
    }

    friend Vec3<T> operator*(const Vec3<T>& lhs, T scalar)
    {
        Vec3<T> result(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar);
        return result;
    }

    friend Vec3<T> operator/(const Vec3<T>& lhs, T scalar)
    {
        Vec3<T> result(lhs.x / scalar, lhs.y / scalar, lhs.z / scalar);
        return result;
    }

    //Comparison Operators
    bool operator==(const Vec3<T>& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Vec3<T>& other) const
    {
        return x != other.x || y != other.y || z != other.z;
    }

    //Properties of Vectors

    T Magnitude()
    {
        return (T) (x*x) + (y*y) + (z*z);
    }

    T SQRMagnitude()
    {
        return (T) sqrt(Magnitude());
    }

    Vec3<T> Normalize()
    {
        Vec3<T> result;

        T denominator = SQRMagnitude();

        //Avoiding Division by 0
        if(denominator != 0)
        {
            result = (*this) / denominator;
        }
        return result;
    }

    T Dot(const Vec3<T>& other)
    {
        return (T) ((x * (other.x)) + (y * (other.y)) + (z * (other.z)));
    }

    T Angle(const Vec3<T>& other)
    {
        return cos( (Dot(other)) / (SQRMagnitude() * other.SQRMagnitude()) );
    }

    Vec3<T> Cross(const Vec3<T>& rhs)
    {
        return Vec3<T>( (y*rhs.z) - (z*rhs.y),
                        (z*rhs.x) - (x*rhs.z),
                        (x*rhs.y) - (y*rhs.x) );
    }
};

}

#endif
