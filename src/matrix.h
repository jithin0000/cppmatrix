#if !defined(MATRIX)
#define MATRIX

#include <iostream>
#include <stdexcept>

template <class T>
class matrix
{
private:
    int _row;
    int _col;
    int _totalSize;
    T *_data;

public:
    // general constructors
    matrix(int row, int col)
    {
        if (row == 0 || col == 0)
        {
            throw std::invalid_argument("Number of rows and columns must be greater than zero.");
        }

        _row = row;
        _col = col;
        _totalSize = row * col;
        _data = new T[_totalSize];
        for (size_t i = 0; i < _row; i++)
        {
            for (size_t j = 0; j < _col; j++)
            {
                _data[i * _col + j] = 0.0;
            }
        }
    }

    // Recieves Flattened array
    matrix(int row, int col, const T *arr)
    {
        if (row <= 0 || col <= 0)
        {
            throw std::invalid_argument("Invalid dimensions: row and col must be greater than zero.");
        }

        if (!arr)
        {
            throw std::invalid_argument("Invalid input array: arr cannot be a null pointer.");
        }

        _row = row;
        _col = col;
        _totalSize = row * col;
        _data = new T[_totalSize];
        for (size_t i = 0; i < _row; i++)
        {
            for (size_t j = 0; j < _col; j++)
            {
                _data[i * _col + j] = arr[i * _col + j];
            }
        }
    }

    // Return row and columns
    size_t getRows() const { return _row; }
    size_t getCols() const { return _col; }
    size_t getTotalSize() const { return _totalSize; }

    // public accessors
    T &operator()(int row, int col)
    {
        return _data[row * _col + col];
    }
    const T &operator()(int row, int col) const
    {
        return _data[row * _col + col];
    }

    // Operation
    template <typename U>
    friend matrix<U> operator+(const matrix<U> &lhs, const matrix<U> &rhs);
    template <typename U>
    friend matrix<U> operator+(const matrix<U> &lhs, const U& rhs);
    template <typename U>
    friend matrix<U> operator+(const U& lhs, const matrix<U> &rhs);
    //subtraction
    template <typename U>
    friend matrix<U> operator-(const matrix<U> &lhs, const matrix<U> &rhs);
    template <typename U>
    friend matrix<U> operator-(const matrix<U> &lhs, const U& rhs);
    template <typename U>
    friend matrix<U> operator-(const U& lhs, const matrix<U> &rhs);



    ~matrix()
    {
        delete[] _data;
    }

    
};

template <typename U>
matrix<U> operator+(const matrix<U> &lhs, const matrix<U> &rhs)
{
    if (lhs._row != rhs._row || lhs._col != rhs._col)
    {
        throw std::invalid_argument("Matrix dimensions must match for addition.");
    }

    matrix<U> result(lhs._row, lhs._col);

    for (size_t i = 0; i < lhs._row; i++)
    {
        for (size_t j = 0; j < lhs._col; j++)
        {
            result(i, j) = lhs(i, j) + rhs(i, j);
        }
    }

    return result;

};

template<typename U>
matrix<U> operator+(const matrix<U> &lhs, const U& rhs){
    if (lhs._totalSize == 0 )
    {
        throw std::invalid_argument("Invalid matrix for scalar addition ");
    }


    matrix<U> result(lhs._row, lhs._col);
    for (size_t i = 0; i < lhs._row; i++)
    {
        for (size_t j = 0; j < lhs._col; j++)
        {
            result(i, j) = lhs(i, j) + rhs;
        }
    }

    return result;
}

template<typename U>
matrix<U> operator+(const U& rhs, const matrix<U> &lhs){
    if (lhs._totalSize == 0 )
    {
        throw std::invalid_argument("Invalid matrix for scalar addition ");
    }


    matrix<U> result(lhs._row, lhs._col);
    for (size_t i = 0; i < lhs._row; i++)
    {
        for (size_t j = 0; j < lhs._col; j++)
        {
            result(i, j) = lhs(i, j) + rhs;
        }
    }

    return result;
}



/// @brief Substraction
/// @tparam U any number type
/// @param lhs matrix
/// @param rhs matrix
/// @return new matrix with same dimension

template <typename U>
matrix<U> operator-(const matrix<U> &lhs, const matrix<U> &rhs)
{
    if (lhs._row != rhs._row || lhs._col != rhs._col)
    {
        throw std::invalid_argument("Matrix dimensions must match for addition.");
    }

    matrix<U> result(lhs._row, lhs._col);

    for (size_t i = 0; i < lhs._row; i++)
    {
        for (size_t j = 0; j < lhs._col; j++)
        {
            result(i, j) = lhs(i, j) - rhs(i, j);
        }
    }

    return result;

};

template<typename U>
matrix<U> operator-(const matrix<U> &lhs, const U& rhs){
    if (lhs._totalSize == 0 )
    {
        throw std::invalid_argument("Invalid matrix for scalar addition ");
    }


    matrix<U> result(lhs._row, lhs._col);
    for (size_t i = 0; i < lhs._row; i++)
    {
        for (size_t j = 0; j < lhs._col; j++)
        {
            result(i, j) = lhs(i, j) - rhs;
        }
    }

    return result;
}

template<typename U>
matrix<U> operator-(const U& rhs, const matrix<U> &lhs){
    if (lhs._totalSize == 0 )
    {
        throw std::invalid_argument("Invalid matrix for scalar addition ");
    }


    matrix<U> result(lhs._row, lhs._col);
    for (size_t i = 0; i < lhs._row; i++)
    {
        for (size_t j = 0; j < lhs._col; j++)
        {
            result(i, j) = lhs(i, j) - rhs;
        }
    }

    return result;
}

#endif // MATRIX
