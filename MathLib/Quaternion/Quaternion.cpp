//
// Created by Luiz on 06/01/2022.
//

#ifndef KAZEMATHLIB_QUATERNION_CPP
#define KAZEMATHLIB_QUATERNION_CPP

#include <iostream>
#include <math.h>
#include "../Vector/Vector3D.cpp"

using namespace std;

namespace KMath {

template<typename T, typename std::enable_if<std::is_floating_point<T>::value>::type * = nullptr>
class Quaternion
{
    public:

        //Members
        T scalar;
        Vec3<T> vec;

        //Constructors
        Quaternion() : scalar(0), vec(Vec3<T>(0,0,0)) {};
        Quaternion(T _scalar, Vec3<T>& _vec): scalar(_scalar), vec(_vec)  {};
        Quaternion(const Quaternion &_q) : scalar(_q.scalar), vec(_q.vec) {};

        //Operators
        Quaternion<T>& operator=(const Quaternion<T>& other)
        {
            //Self Copy Guard
            if(this == &other)
            {
                return *this;
            }

            this->scalar = other.scalar;
            this->vec = other.vec;

            return *this;
        }

        friend Quaternion<T> operator+(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
        {
        return Quaternion<T>( lhs.scalar + rhs.scalar , lhs.vec + rhs.vec ) ;
        }

        friend Quaternion<T> operator-(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
        {

            return Quaternion<T>( lhs.scalar - rhs.scalar , lhs.vec - rhs.vec ) ;
        }

        friend Quaternion<T> operator*(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
        {
            float scalar = lhs.scalar * rhs.scalar - lhs.vec.Dot(rhs.vec);
            Vec3<T> imaginary =  (lhs.scalar * rhs.vec) + (rhs.scalar * lhs.vec) + lhs.vec.Cross(rhs.vec);
            return Quaternion<T>(scalar, imaginary);
        }

        friend Quaternion<T> operator*(const Quaternion<T>& lhs, float constant)
        {
            return Quaternion<T>(lhs.scalar * constant, lhs.vec * constant);
        }

        //Methods
        T Norm()
        {
            return sqrt( (scalar*scalar) + (vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z) );
        }

        Quaternion<T> Normalise()
        {
            Quaternion<T> result;
            T norm = Norm();
            if(norm != 0)
            {
                T inverseNorm = 1 / norm;
                result.scalar = inverseNorm * scalar;
                result.vec = inverseNorm * Vec3<T>;
            }

            return result;

        }

        Quaternion<T> Conjugate()
        {
            return Quaternion<T>(scalar, vec * (-1));
        }

//        Quaternion<T> Inverse()
//        {
//            return
//        }


        //Comparison Operators
        bool operator==(const Quaternion<T>& other) const
        {
            return scalar == other.scalar && vec == other.vec;
        }

        bool operator!=(const Quaternion<T>& other) const
        {
            return scalar != other.scalar || vec != other.vec;
        }
};

}

#endif