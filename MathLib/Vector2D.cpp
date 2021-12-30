//
// Created by Luiz on 29/12/2021.
//

#ifndef KAZEMATHLIB_VECTOR2D_CPP
#define KAZEMATHLIB_VECTOR2D_CPP

#include <iostream>
#include <math.h>

using namespace std;

namespace KMath
{


template <typename T, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
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

    //Comparison Operators
    inline bool operator==(const Vec2<T>& other) const
    {
        return x == other.x && y == other.y;
    }

    inline bool operator!=(const Vec2<T>& other) const
    {
        return x != other.x || y != other.y;
    }

    //Properties of Vectors

    T Magnitude()
    {
        return (T) (x*x) + (y*y);
    }

    T SQRMagnitude()
    {
        return (T) sqrt(Magnitude());
    }

    Vec2<T>& Normalize()
    {
        T denominator = SQRMagnitude();

        //Avoiding Division by 0
        if(denominator != 0)
        {
            (*this) = (*this) / denominator;
        }
        return (*this);
    }

    T Dot(const Vec2<T>& other)
    {
        return (T) (x * (other.x)) + (y * (other.y));
    }

    T Angle(const Vec2<T>& other)
    {
        return cos( (Dot(other)) / (SQRMagnitude() * other.SQRMagnitude()) );
    }

};

}


#endif //KAZEMATHLIB_VECTOR2D_CPP
