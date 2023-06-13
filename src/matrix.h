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

    // invrese
    matrix<T> join(const matrix<T> &rhs);
    bool inverse();

    // Operation
    template <typename U>
    friend matrix<U> operator+(const matrix<U> &lhs, const matrix<U> &rhs);
    template <typename U>
    friend matrix<U> operator+(const matrix<U> &lhs, const U &rhs);
    template <typename U>
    friend matrix<U> operator+(const U &lhs, const matrix<U> &rhs);

    // subtraction
    template <typename U>
    friend matrix<U> operator-(const matrix<U> &lhs, const matrix<U> &rhs);
    template <typename U>
    friend matrix<U> operator-(const matrix<U> &lhs, const U &rhs);
    template <typename U>
    friend matrix<U> operator-(const U &lhs, const matrix<U> &rhs);

    // Multiplication
    template <typename U>
    friend matrix<U> operator*(const matrix<U> &lhs, const matrix<U> &rhs);
    template <typename U>
    friend matrix<U> operator*(const matrix<U> &lhs, const U &rhs);
    template <typename U>
    friend matrix<U> operator*(const U &lhs, const matrix<U> &rhs);
    template <typename U>
    friend bool operator==(const matrix<U> &lhs, const matrix<U> &rhs);

    ~matrix()
    {
        delete[] _data;
    }

    void setIdentity()
    {

        if (!isSquare())
        {
            throw std::invalid_argument("SET_IDENTITY:: Not an square matrix ");
        }

        for (size_t i = 0; i < _row; i++)
        {
            for (size_t j = 0; j < _col; j++)
            {
                if (i == j)
                {
                    _data[i * _col + j] = 1;
                }
                else
                {
                    _data[i * _col + j] = 0;
                }
            }
        }
    }

    void printMatrix()
    {
        // Find the maximum width of the matrix elements
        int max_width = 0;
        for (int i = 0; i < _row; i++)
        {
            for (int j = 0; j < _col; j++)
            {
                int element_width = std::to_string(_data[i * _col + j]).length();
                max_width = std::max(max_width, element_width);
            }
        }

        // Print the matrix elements with appropriate spacing
        for (int i = 0; i < _row; i++)
        {
            for (int j = 0; j < _col; j++)
            {
                std::cout << std::setw(max_width) << std::setprecision(2) << std::fixed << _data[i * _col + j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    bool isSquare()
    {
        return _row == _col;
    }
};

template <typename U>
bool operator==(const matrix<U> &lhs, const matrix<U> &rhs)
{
    if (lhs._row != rhs._row || lhs._col != rhs._col)
    {
        throw std::invalid_argument("Matrix dimensions must match .");
    }

    const double epsilon = 1e-9;
    for (size_t i = 0; i < lhs._row; i++)
    {
        for (size_t j = 0; j < lhs._col; j++)
        {
            if (abs(lhs(i, j) - rhs(i, j)) > epsilon)
            {
                return false;
            }
        }
    }
    return true;
};

/// ADDITION

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

template <typename U>
matrix<U> operator+(const matrix<U> &lhs, const U &rhs)
{
    if (lhs._totalSize == 0)
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

template <typename U>
matrix<U> operator+(const U &rhs, const matrix<U> &lhs)
{
    if (lhs._totalSize == 0)
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
        throw std::invalid_argument("Matrix dimensions must match for subtaction.");
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

template <typename U>
matrix<U> operator-(const matrix<U> &lhs, const U &rhs)
{
    if (lhs._totalSize == 0)
    {
        throw std::invalid_argument("Invalid matrix for scalar subtaction ");
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

template <typename U>
matrix<U> operator-(const U &rhs, const matrix<U> &lhs)
{
    if (lhs._totalSize == 0)
    {
        throw std::invalid_argument("Invalid matrix for scalar subtaction ");
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

//////////////////////////////////////////////////////////
//------------------MULITPLICATION------------------------
//////////////////////////////////////////////////////////

/// @brief MULTIPLICATION
/// @tparam U any number type
/// @param lhs matrix
/// @param rhs matrix
/// @return new matrix with same dimension

template <typename U>
matrix<U> operator*(const matrix<U> &lhs, const matrix<U> &rhs)
{
    if (lhs._col != rhs._row)
    {
        throw std::invalid_argument("Matrix dimensions are incompatible for multiplication.");
    }

    matrix<U> result(lhs._row, rhs._col);

    for (size_t i = 0; i < lhs._row; i++)
    {
        for (size_t j = 0; j < rhs._col; j++)
        {
            U sum = 0.0;
            for (size_t k = 0; k < lhs._col; k++)
            {
                sum += lhs(i, k) * rhs(k, j);
            }

            result(i, j) = sum;
        }
    }

    return result;
};

template <typename U>
matrix<U> operator*(const matrix<U> &lhs, const U &rhs)
{
    if (lhs._totalSize == 0)
    {
        throw std::invalid_argument("Invalid matrix for scalar addition ");
    }

    matrix<U> result(lhs._row, lhs._col);
    for (size_t i = 0; i < lhs._row; i++)
    {
        for (size_t j = 0; j < lhs._col; j++)
        {
            result(i, j) = lhs(i, j) * rhs;
        }
    }

    return result;
}

template <typename U>
matrix<U> operator*(const U &rhs, const matrix<U> &lhs)
{
    if (lhs._totalSize == 0)
    {
        throw std::invalid_argument("Invalid matrix for scalar addition ");
    }

    matrix<U> result(lhs._row, lhs._col);
    for (size_t i = 0; i < lhs._row; i++)
    {
        for (size_t j = 0; j < lhs._col; j++)
        {
            result(i, j) = lhs(i, j) * rhs;
        }
    }

    return result;
}

template <typename T>
matrix<T> matrix<T>::join(const matrix<T> &rhs)
{
    int newCol = _col + rhs._col;
    matrix<T> result(rhs._row, newCol);
    for (size_t i = 0; i < _row; i++)
    {
        for (size_t j = 0; j < newCol; j++)
        {
            if (j < _col)
            {
                result(i, j) = _data[i * _col + j];
            }
            else
            {
                result(i,j) = rhs(i,j-rhs.getCols());
            }
        }
    }
    return result;
};

template <typename T>
bool matrix<T>::inverse()
{
    if (!isSquare())
    {
        throw std::invalid_argument("Matrix must be an square matrix");
    }

    // create an identity matrix and join them
    int oldRow = _row;
    int oldColumn = _col;
    matrix<T> identity(_row, _col);
    matrix<T> joinedMatrix = join(identity);
}

#endif // MATRIX
