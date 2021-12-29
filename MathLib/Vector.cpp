//
// Created by Luiz on 29/12/2021.
//

#ifndef KAZEMATHLIB_VECTOR_CPP
#define KAZEMATHLIB_VECTOR_CPP

#include <iostream>
using namespace std;

namespace KMath
{


template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
class Vec2
{
public:
    //Members
    T x;
    T y;

    //Constructors
    Vec2() : x(0), y(0) {}
    Vec2(T _x, T _y) : x(_x), y(_y) {}
    Vec2(const Vec2& _vec) : x(_vec.x), y(_vec.y) {}

    //Print Overload
    friend ostream& operator<<(ostream& os, const Vec2& _vec)
    {
        os << '{' << _vec.x << ',' << _vec.y << '}';
        return os;
    }

    //Operators Overloading
    Vec2<T>& operator=(const Vec2<T>& other)
    {
        //Self Copy Guard
        if(this == &other)
        {
            return *this;
        }

        this->x = other.x;
        this->y = other.y;

        return *this;
    }

    Vec2<T>& operator+(const Vec2<T>& other)
    {
        this->x += other.x;
        this->y += other.y;

        return *this;
    }

    Vec2<T>& operator-(const Vec2<T>& other)
    {
        this->x -= other.x;
        this->y -= other.y;

        return *this;
    }

    Vec2<T>& operator*(T scalar)
    {
        this->x *= scalar;
        this->y *= scalar;

        return *this;
    }

    Vec2<T>& operator/(T scalar)
    {
        this->x /= scalar;
        this->y /= scalar;

        return *this;
    }
};



template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
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

    Vec3<T>& operator+(const Vec3<T>& other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;

        return *this;
    }

    Vec3<T>& operator-(const Vec3<T>& other)
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;

        return *this;
    }

    Vec3<T>& operator*(T scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;

        return *this;
    }

    Vec3<T>& operator/(T scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;

        return *this;
    }


};

template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
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
};

}


#endif //KAZEMATHLIB_VECTOR_CPP
