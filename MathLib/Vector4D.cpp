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
    Vec4(const Vec4& _vec) : x(_vec.x), y(_vec.y), z(_vec.z), w(_vec._w) {}
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

    Vec4<T>& operator+(const Vec4<T>& other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        this->w += other.w;

        return *this;
    }

    Vec4<T>& operator-(const Vec4<T>& other)
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        this->w -= other.w;

        return *this;
    }

    Vec4<T>& operator*(T scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        this->w *= scalar;

        return *this;
    }

    Vec4<T>& operator/(T scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        this->w /= scalar;

        return *this;
    }

    //Comparison Operators
    bool operator==(const Vec4<T>& other)
    {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    bool operator!=(const Vec4<T>& other)
    {
        return x != other.x || y != other.y || z != other.z || w != other.w;
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

    Vec4<T>& Normalize()
    {
        (*this) = (*this) / SQRMagnitude();
        return (*this);
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