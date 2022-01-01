//
// Created by Luiz on 31/12/2021.
//

#ifndef KAZEMATHLIB_MATRIX2X2_CPP
#define KAZEMATHLIB_MATRIX2X2_CPP

#include <iostream>
#include <math.h>

using namespace std;

namespace KMath
{

template <typename T, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
class Matrix2x2
{

//Members
public:
    //Constructor
    Matrix2x2()
    {
        AllocateMatrix();
    }

    //Destructor
    ~Matrix2x2()
    {
        DeleteMatrix();
    }

    //Size Property
    const ushort Size = 2;

//    Matrix2x2<T>& operator=(const Matrix2x2<T>& other)
//    {
//
//    }
//
//    Matrix2x2<T>& operator+(const Matrix2x2<T>& other)
//    {
//
//    }
//
//    Matrix2x2<T>& operator-(const Matrix2x2<T>& other)
//    {
//
//    }
//
//    Matrix2x2<T>& operator*(T scalar)
//    {
//
//    }
//
//    Matrix2x2<T>& operator/(T scalar)
//    {
//
//    }

    //Comparison Operators
    inline bool operator==(const Matrix2x2<T>& other) const
    {

    }

    inline bool operator!=(const Matrix2x2<T>& other) const
    {

    }


private:
    T** m_matrix = nullptr;

    inline void AllocateMatrix()
    {
        m_matrix = new T[Size][Size](); //Allocate and set to zero
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
