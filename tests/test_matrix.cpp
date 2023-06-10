#include "gtest/gtest.h"
#include "matrix.h"

TEST(MatrixTest, MatrixCanInitiateWithRowAndCol)
{
    matrix<int> m(2, 3);
    ASSERT_EQ(m.getRows(), 2);
    ASSERT_EQ(m.getCols(), 3);
    ASSERT_EQ(m.getTotalSize(), 6);
    ASSERT_EQ(m(0, 0), 0);
    ASSERT_EQ(m(1, 0), 0);
    ASSERT_EQ(m(1, 1), 0);

};

TEST(MatrixTest, ConstructorWithArray)
{
    // Define the input array
    const int inputArray[] = {1, 2, 3, 4, 5, 6};

    // Create a matrix using the constructor
    matrix<int> m(2, 3, inputArray);

    // Assert the values of the matrix elements
    ASSERT_EQ(m(0, 0), 1);
    ASSERT_EQ(m(0, 1), 2);
    ASSERT_EQ(m(0, 2), 3);
    ASSERT_EQ(m(1, 0), 4);
    ASSERT_EQ(m(1, 1), 5);
    ASSERT_EQ(m(1, 2), 6);

};

TEST(MatrixTest, AdditionInvalidArgument)
{
    matrix<int> matrix1(2, 2);
    matrix<int> matrix2(3, 2);
    ASSERT_THROW({
        matrix<int> result = matrix1 + matrix2;
    }, std::invalid_argument);
   
};

TEST(MatrixTest, AdditionOperator) {
    // Create two matrices for addition
    matrix<int> matrix1(2, 2, new int[4]{1, 2, 3, 4});
    matrix<int> matrix2(2, 2, new int[4]{5, 6, 7, 8});

    // Perform addition using the operator
    matrix<int> result = matrix1 + matrix2;

    // Assert the dimensions of the result
    ASSERT_EQ(result.getRows(), 2);
    ASSERT_EQ(result.getCols(), 2);

    // Assert the values of the result matrix elements
    ASSERT_EQ(result(0, 0), 6);
    ASSERT_EQ(result(0, 1), 8);
    ASSERT_EQ(result(1, 0), 10);
    ASSERT_EQ(result(1, 1), 12);

};

TEST(MatrixTest, ScalarAdditionOperator) {
    // Create a matrix for scalar addition
    matrix<int> m(2, 2, new int[4]{1, 2, 3, 4});

    // Perform scalar addition using the operator
    matrix<int> result = m + 5;

    // Assert the dimensions of the result
    ASSERT_EQ(result.getRows(), 2);
    ASSERT_EQ(result.getCols(), 2);

    // Assert the values of the result matrix elements
    ASSERT_EQ(result(0, 0), 6);
    ASSERT_EQ(result(0, 1), 7);
    ASSERT_EQ(result(1, 0), 8);
    ASSERT_EQ(result(1, 1), 9);

};

TEST(MatrixTest, ScalarAdditionOperatorLeft) {
    // Create a matrix for scalar addition
    matrix<int> m(2, 2, new int[4]{1, 2, 3, 4});

    // Perform scalar addition using the operator
    matrix<int> result = 5+m;

    // Assert the dimensions of the result
    ASSERT_EQ(result.getRows(), 2);
    ASSERT_EQ(result.getCols(), 2);

    // Assert the values of the result matrix elements
    ASSERT_EQ(result(0, 0), 6);
    ASSERT_EQ(result(0, 1), 7);
    ASSERT_EQ(result(1, 0), 8);
    ASSERT_EQ(result(1, 1), 9);

};


/// Test for subtractions

TEST(MatrixTest, SubractionOperator) {
    // Create two matrices for addition
    matrix<int> matrix1(2, 2, new int[4]{1, 2, 3, 4});
    matrix<int> matrix2(2, 2, new int[4]{5, 6, 7, 8});

    // Perform addition using the operator
    matrix<int> result = matrix2 - matrix1;

    // Assert the dimensions of the result
    ASSERT_EQ(result.getRows(), 2);
    ASSERT_EQ(result.getCols(), 2);

    // Assert the values of the result matrix elements
    ASSERT_EQ(result(0, 0), 4);
    ASSERT_EQ(result(0, 1), 4);
    ASSERT_EQ(result(1, 0), 4);
    ASSERT_EQ(result(1, 1), 4);

}