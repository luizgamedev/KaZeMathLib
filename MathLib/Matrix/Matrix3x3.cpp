//
// Created by Luiz on 31/12/2021.
//

#ifndef KAZEMATHLIB_MATRIX3X3_CPP
#define KAZEMATHLIB_MATRIX3X3_CPP

#include <iostream>
#include <math.h>

using namespace std;

namespace KMath
{

template <typename T, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
class Matrix3x3
{

//Members
public:
    //Constructor
    Matrix3x3()
    {

    }

    //Destructor
    ~Matrix3x3()
    {
        DeleteMatrix();
    }

    const ushort Size = 3;

private:
    T** m_matrix = nullptr;

    inline void AllocateMatrix()
    {
        m_matrix = new T* [Size](); //Allocate and set to zero
        for(int i = 0 ; i < Size ; ++i)
        {
            m_matrix[i] = new T[Size]();
        }
    }

    inline void DeleteMatrix()
    {
        for(int i  = 0 ; i < Size ; ++i)
        {
            delete m_matrix[i];
        }
        delete m_matrix;
        m_matrix = nullptr;
    }

};

}

#endif