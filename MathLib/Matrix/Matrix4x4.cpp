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
class Matrix4x4
{

//Members
public:
    //Constructor
    Matrix4x4() { AllocateMatrix(); }

    //Destructor
    ~Matrix4x4() { DeleteMatrix(); }

    const ushort Size = 3;

    //Static Methods
    static Matrix4x4<T> Identity()
    {
        Matrix4x4<T> identity;
        identity.SetValueAt(1, 0,0);
        identity.SetValueAt(1, 1,1);
        identity.SetValueAt(1, 2,2);
        identity.SetValueAt(1, 3,3);
        return identity;
    }

    //Methods
    T Determinant()
    {
        return
                m_matrix[0,3] * m_matrix[1,2] * m_matrix[2,1] * m_matrix[3,0] - m_matrix[0,2] * m_matrix[1,3] * m_matrix[2,1] * m_matrix[3,0] -
                m_matrix[0,3] * m_matrix[1,1] * m_matrix[2,2] * m_matrix[3,0] + m_matrix[0,1] * m_matrix[1,3] * m_matrix[2,2] * m_matrix[3,0] +
                m_matrix[0,2] * m_matrix[1,1] * m_matrix[2,3] * m_matrix[3,0] - m_matrix[0,1] * m_matrix[1,2] * m_matrix[2,3] * m_matrix[3,0] -
                m_matrix[0,3] * m_matrix[1,2] * m_matrix[2,0] * m_matrix[3,1] + m_matrix[0,2] * m_matrix[1,3] * m_matrix[2,0] * m_matrix[3,1] +
                m_matrix[0,3] * m_matrix[1,0] * m_matrix[2,2] * m_matrix[3,1] - m_matrix[0,0] * m_matrix[1,3] * m_matrix[2,2] * m_matrix[3,1] -
                m_matrix[0,2] * m_matrix[1,0] * m_matrix[2,3] * m_matrix[3,1] + m_matrix[0,0] * m_matrix[1,2] * m_matrix[2,3] * m_matrix[3,1] +
                m_matrix[0,3] * m_matrix[1,1] * m_matrix[2,0] * m_matrix[3,2] - m_matrix[0,1] * m_matrix[1,3] * m_matrix[2,0] * m_matrix[3,2] -
                m_matrix[0,3] * m_matrix[1,0] * m_matrix[2,1] * m_matrix[3,2] + m_matrix[0,0] * m_matrix[1,3] * m_matrix[2,1] * m_matrix[3,2] +
                m_matrix[0,1] * m_matrix[1,0] * m_matrix[2,3] * m_matrix[3,2] - m_matrix[0,0] * m_matrix[1,1] * m_matrix[2,3] * m_matrix[3,2] -
                m_matrix[0,2] * m_matrix[1,1] * m_matrix[2,0] * m_matrix[3,3] + m_matrix[0,1] * m_matrix[1,2] * m_matrix[2,0] * m_matrix[3,3] +
                m_matrix[0,2] * m_matrix[1,0] * m_matrix[2,1] * m_matrix[3,3] - m_matrix[0,0] * m_matrix[1,2] * m_matrix[2,1] * m_matrix[3,3] -
                m_matrix[0,1] * m_matrix[1,0] * m_matrix[2,2] * m_matrix[3,3] + m_matrix[0,0] * m_matrix[1,1] * m_matrix[2,2] * m_matrix[3,3];
    }

    Matrix4x4<T> Inverse()
    {
        Matrix4x4<T> inverse;
        T determinant = Determinant();

        if(determinant == 0)
        {
            //can't do inverse
            return nullptr;
        }

        T inverse_determinant = 1/determinant;

        inverse.SetValueAt(m_matrix[0][0] * inverse_determinant, 0,0);
        inverse.SetValueAt(m_matrix[0][1] * inverse_determinant, 0,1);
        inverse.SetValueAt(m_matrix[0][1] * inverse_determinant, 0,2);
        inverse.SetValueAt(m_matrix[0][1] * inverse_determinant, 0,3);
        inverse.SetValueAt(m_matrix[1][0] * inverse_determinant, 1,0);
        inverse.SetValueAt(m_matrix[1][1] * inverse_determinant, 1,1);
        inverse.SetValueAt(m_matrix[1][1] * inverse_determinant, 1,2);
        inverse.SetValueAt(m_matrix[1][1] * inverse_determinant, 1,3);
        inverse.SetValueAt(m_matrix[1][0] * inverse_determinant, 2,0);
        inverse.SetValueAt(m_matrix[1][1] * inverse_determinant, 2,1);
        inverse.SetValueAt(m_matrix[1][1] * inverse_determinant, 2,2);
        inverse.SetValueAt(m_matrix[1][1] * inverse_determinant, 2,3);
        inverse.SetValueAt(m_matrix[1][0] * inverse_determinant, 3,0);
        inverse.SetValueAt(m_matrix[1][1] * inverse_determinant, 3,1);
        inverse.SetValueAt(m_matrix[1][1] * inverse_determinant, 3,2);
        inverse.SetValueAt(m_matrix[1][1] * inverse_determinant, 3,3);

        return inverse;
    }

    //Access
    T GetValueAt(int _x, int _y) const
    {
        return m_matrix[_x][_y];
    }

    void SetValueAt(T _value, int _x, int _y)
    {
        m_matrix[_x][_y] = _value;
    }

    Matrix4x4<T>& operator=(const Matrix4x4<T>& other)
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

    friend Matrix4x4<T> operator+(const Matrix4x4<T>& lhs,  const Matrix4x4<T>& rhs)
    {
        Matrix4x4<T> result;

        for(int i = 0 ; i < result.Size ; ++i)
        {
            for(int j = 0 ; j < result.Size ; ++j)
            {
                result.SetValueAt(lhs.GetValueAt(i,j) + rhs.GetValueAt(i,j),  i,j);
            }
        }

        return result;
    }

    friend Matrix4x4<T> operator-(const Matrix4x4<T>& lhs, const Matrix4x4<T>& rhs)
    {
        Matrix4x4<T> result;

        for(int i = 0 ; i < result.Size ; ++i)
        {
            for(int j = 0 ; j < result.Size ; ++j)
            {
                result.SetValueAt(lhs.GetValueAt(i,j) - rhs.GetValueAt(i,j),  i,j);
            }
        }

        return result;
    }

    friend Matrix4x4<T> operator*(const Matrix4x4<T>& lhs, const Matrix4x4<T>& rhs)
    {
        Matrix4x4<T> result;

        for(int i = 0 ; i < result.Size ; ++i)
        {
            for(int j = 0 ; j < result.Size ; ++j)
            {
                T sum = 0;
                for(int k = 0 ; k < result.Size ; ++k)
                {
                    sum += (lhs.GetValueAt(i,k) * rhs.GetValueAt(k,j));
                }
                result.SetValueAt(sum, i,j);
            }
        }

        return result;
    }


    //Comparison Operators
    inline bool operator==(const Matrix4x4<T>& other) const
    {
        for(int i = 0 ; i < Size ; ++i)
        {
            for(int j = 0 ; j < Size ; j++)
            {
                if(m_matrix[i][j] != other.GetValueAt(i,j))
                    return false;
            }
        }
        return true;
    }

    inline bool operator!=(const Matrix4x4<T>& other) const
    {
        for(int i = 0 ; i < Size ; ++i)
        {
            for(int j = 0 ; j < Size ; j++)
            {
                if(m_matrix[i][j] != other.GetValueAt(i,j))
                    return true;
            }
        }
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