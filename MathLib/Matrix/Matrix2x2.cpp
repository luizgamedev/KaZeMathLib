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

    //Static Methods
    static Matrix2x2<T> Identity()
    {
        Matrix2x2<T> identity;
        identity.SetValueAt(1, 0,0);
        identity.SetValueAt(1, 1,1);
        return identity;
    }

    //Methods
    T Determinant()
    {
        return (m_matrix[0][0]*m_matrix[1][1]) - (m_matrix[0][1]*m_matrix[1][0]);
    }

    Matrix2x2<T> Inverse()
    {
        Matrix2x2<T> inverse;
        T determinant = Determinant();

        if(determinant == 0)
        {
            //can't do inverse
            return inverse;
        }

        T inverse_determinant = 1/determinant;

        inverse.SetValueAt(m_matrix[0][0] * inverse_determinant, 0,0);
        inverse.SetValueAt(m_matrix[0][1] * inverse_determinant, 0,1);
        inverse.SetValueAt(m_matrix[1][0] * inverse_determinant, 1,0);
        inverse.SetValueAt(m_matrix[1][1] * inverse_determinant, 1,1);

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
    inline bool operator==(const Matrix2x2<T>& other) const
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

    inline bool operator!=(const Matrix2x2<T>& other) const
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
