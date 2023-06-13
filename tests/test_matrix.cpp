#include "gtest/gtest.h"
#include "matrix.h"
#include "math.h"
#include "iostream"

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
    },
                 std::invalid_argument);
};

TEST(MatrixTest, AdditionOperator)
{
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

TEST(MatrixTest, ScalarAdditionOperator)
{
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

TEST(MatrixTest, ScalarAdditionOperatorLeft)
{
    // Create a matrix for scalar addition
    matrix<int> m(2, 2, new int[4]{1, 2, 3, 4});

    // Perform scalar addition using the operator
    matrix<int> result = 5 + m;

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

TEST(MatrixTest, SubractionOperator)
{
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

TEST(MatrixTest, ScalarSubtractionitionOperator)
{
    // Create a matrix for scalar addition
    matrix<int> m(2, 2, new int[4]{1, 2, 3, 4});

    // Perform scalar addition using the operator
    matrix<int> result = m - 1;

    // Assert the dimensions of the result
    ASSERT_EQ(result.getRows(), 2);
    ASSERT_EQ(result.getCols(), 2);

    // Assert the values of the result matrix elements
    ASSERT_EQ(result(0, 0), 0);
    ASSERT_EQ(result(0, 1), 1);
    ASSERT_EQ(result(1, 0), 2);
    ASSERT_EQ(result(1, 1), 3);
};

TEST(MatrixTest, ScalarSubractionOperatorLeft)
{
    // Create a matrix for scalar addition
    matrix<int> m(2, 2, new int[4]{1, 2, 3, 4});

    // Perform scalar addition using the operator
    matrix<int> result = 1 - m;

    // Assert the dimensions of the result
    ASSERT_EQ(result.getRows(), 2);
    ASSERT_EQ(result.getCols(), 2);

    // Assert the values of the result matrix elements
    ASSERT_EQ(result(0, 0), 0);
    ASSERT_EQ(result(0, 1), 1);
    ASSERT_EQ(result(1, 0), 2);
    ASSERT_EQ(result(1, 1), 3);
};

TEST(MatrixTest, MultiplicationOperator)
{
    // Create matrices for multiplication
    matrix<int> matrix1(2, 3, new int[6]{1, 2, 3,
     4, 5, 6});
    matrix<int> matrix2(3, 2, new int[6]{7, 8,
     9, 10,
      11, 12});

    // Perform matrix multiplication using the operator
    matrix<int> result = matrix1 * matrix2;

    // Assert the dimensions of the result
    ASSERT_EQ(result.getRows(), 2);
    ASSERT_EQ(result.getCols(), 2);

    // Assert the values of the result matrix elements
    ASSERT_EQ(result(0, 0), 58);
    ASSERT_EQ(result(0, 1), 64);
    ASSERT_EQ(result(1, 0), 139);
    ASSERT_EQ(result(1, 1), 154);
}

TEST(MatrixTest, ScalarMultiplicationOperator)
{
    matrix<int> m(2, 2, new int[4]{1, 2, 3, 4});

    matrix<int> result = m * 1;

    // Assert the dimensions of the result
    ASSERT_EQ(result.getRows(), 2);
    ASSERT_EQ(result.getCols(), 2);

    // Assert the values of the result matrix elements
    ASSERT_EQ(result(0, 0), 1);
    ASSERT_EQ(result(0, 1), 2);
    ASSERT_EQ(result(1, 0), 3);
    ASSERT_EQ(result(1, 1), 4);
};

TEST(MatrixTest, ScalarMultiplicationOperatorLeft)
{
    matrix<int> m(2, 2, new int[4]{1, 2, 3, 4});

    matrix<int> result = 1 * m;

    // Assert the dimensions of the result
    ASSERT_EQ(result.getRows(), 2);
    ASSERT_EQ(result.getCols(), 2);

    // Assert the values of the result matrix elements
    ASSERT_EQ(result(0, 0), 1);
    ASSERT_EQ(result(0, 1), 2);
    ASSERT_EQ(result(1, 0), 3);
    ASSERT_EQ(result(1, 1), 4);
};
TEST(SetIdentityTest, SquareMatrix) {
    matrix<int> mat(3, 3);
    matrix<int> expected(3, 3);
    expected(0, 0) = 1;
    expected(1, 1) = 1;
    expected(2, 2) = 1;
    mat.setIdentity();
    ASSERT_TRUE(mat==expected);
}

TEST(SetIdentityTest, NonSquareMatrix) {
    matrix<int> mat(3, 2);

    EXPECT_THROW(mat.setIdentity(), std::invalid_argument);
}

// Google Test for join function
TEST(MatrixJoinTest, SameNumberOfRows) {
    matrix<int> m(2,2);
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            m(i,j)= i*m.getCols()+j;
        }
    }
    matrix<int>id(2,2);
    id.setIdentity();
    matrix<int> joinedMatrix = m.join(id);

    matrix<int> expected(2,4);
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if(j<2)
            {
                expected(i,j)=m(i,j);
            }else{
                int col = j-id.getCols();
                expected(i,j)=id(i,col);
            }
        }
    }

    ASSERT_TRUE(joinedMatrix==expected);

    

    

}
