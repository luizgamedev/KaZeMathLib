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
    Matrix2x2() { AllocateMatrix(); }

    //Destructor
    ~Matrix2x2() { DeleteMatrix(); }

    //Size Property
    const ushort Size = 2;

    //Access
    T GetValueAt(int _x, int _y) const
    {
        return m_matrix[_x][_y];
    }

    void SetValueAt(T _value, int _x, int _y)
    {
        m_matrix[_x][_y] = _value;
    }

    Matrix2x2<T>& operator=(const Matrix2x2<T>& other)
    {
        //Self Copy Guard
        if(this == &other)
        {
            return *this;
        }

        for(int i = 0 ; i < this->Size ; ++i)
        {
            for(int j = 0 ; j < this->Size ; ++j)
            {
                SetValueAt(other.GetValueAt(i,j),  i,j);
            }
        }

        return *this;
    }

    friend Matrix2x2<T> operator+(const Matrix2x2<T>& lhs,  const Matrix2x2<T>& rhs)
    {
        Matrix2x2<T> result;

        for(int i = 0 ; i < result.Size ; ++i)
        {
            for(int j = 0 ; j < result.Size ; ++j)
            {
                result.SetValueAt(lhs.GetValueAt(i,j) + rhs.GetValueAt(i,j),  i,j);
            }
        }

        return result;
    }

    friend Matrix2x2<T> operator-(const Matrix2x2<T>& lhs, const Matrix2x2<T>& rhs)
    {
        Matrix2x2<T> result;

        for(int i = 0 ; i < result.Size ; ++i)
        {
            for(int j = 0 ; j < result.Size ; ++j)
            {
                result.SetValueAt(lhs.GetValueAt(i,j) - rhs.GetValueAt(i,j),  i,j);
            }
        }

        return result;
    }

    friend Matrix2x2<T> operator*(const Matrix2x2<T>& lhs, const Matrix2x2<T>& rhs)
    {
        Matrix2x2<T> result;

        return result;
    }


    //Comparison Operators
    inline bool operator==(const Matrix2x2<T>& other) const
    {
        return false;
    }

    inline bool operator!=(const Matrix2x2<T>& other) const
    {
        return false;
    }


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
