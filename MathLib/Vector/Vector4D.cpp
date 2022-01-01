//
// Created by Luiz on 30/12/2021.
//

#ifndef KAZEMATHLIB_VECTOR4D_CPP
#define KAZEMATHLIB_VECTOR4D_CPP

#include <iostream>
#include "Vector2D.cpp"
#include "Vector3D.cpp"

using namespace std;

namespace KMath
{

template <typename T, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
class Vec4
{
public:
    T x;
    T y;
    T z;
    T w;

    //Constructors
    Vec4() : x(0), y(0), z(0), w(0) {}
    Vec4(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}
    Vec4(const Vec4& _vec) : x(_vec.x), y(_vec.y), z(_vec.z), w(_vec.w) {}
    Vec4(const KMath::Vec3<T>& _vec, T _w = 0) : x(_vec.x), y(_vec.y), z(_vec.z), w(_w) {}

    //Print Overload
    friend ostream& operator<<(ostream& os, const Vec4& _vec)
    {
        os << '{' << _vec.x << ',' << _vec.y  << ',' << _vec.z << ',' << _vec.w << '}';
        return os;
    }

    //Operators Overloading
    Vec4<T>& operator=(const Vec4<T>& other)
    {
        //Self Copy Guard
        if(this == &other)
        {
            return *this;
        }

        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        this->w = other.w;

        return *this;
    }

    friend Vec4<T> operator+(const Vec4<T>& lhs, const Vec4<T>& rhs)
    {
        Vec4<T> result(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
        return result;
    }

    friend Vec4<T> operator-(const Vec4<T>& lhs, const Vec4<T>& rhs)
    {
        Vec4<T> result(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
        return result;
    }

    friend Vec4<T> operator*(const Vec4<T>& lhs, T scalar)
    {
        Vec4<T> result(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar, lhs.w * scalar);
        return result;
    }

    friend Vec4<T> operator/(const Vec4<T>& lhs, T scalar)
    {
        Vec4<T> result(lhs.x / scalar, lhs.y / scalar, lhs.z / scalar, lhs.w / scalar);
        return result;
    }

    //Comparison Operators
    bool operator==(const Vec4<T>& other) const
    {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    bool operator!=(const Vec4<T>& other) const
    {
        return x != other.x || y != other.y || z != other.z || w != other.w;
    }

    //Properties of Vectors

    T Magnitude()
    {
        return (T) (x*x) + (y*y) + (z*z) + (w*w);
    }

    T SQRMagnitude()
    {
        return (T) sqrt(Magnitude());
    }

    Vec4<T> Normalize()
    {
        Vec4<T> result;

        T denominator = SQRMagnitude();

        //Avoiding Division by 0
        if(denominator != 0)
        {
            result = (*this) / denominator;
        }
        return result;
    }

    T Dot(const Vec4<T>& other)
    {
        return (T) ((x * (other.x)) + (y * (other.y)) + (z * (other.z)) + (w * (other.w)));
    }

    T Angle(const Vec4<T>& other)
    {
        return cos( (Dot(other)) / (SQRMagnitude() * other.SQRMagnitude()) );
    }
};

}

#endif