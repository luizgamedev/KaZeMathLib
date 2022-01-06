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
        Quaternion(){};
        Quaternion(T _scalar, Vec3<T>& _vec): scalar(_scalar), vec(_vec)  {};
        Quaternion(const Quaternion &_q) : scalar(_q.scalar), vec(_q.vec) {};
};

}

#endif