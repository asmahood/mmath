#pragma once

#include <initializer_list>
#include <vector>

namespace mmath {

/**
 * Implementation of a matrix type to perform matrix math and operations.
 * 
 * Implements matrix operations such as row reducing, matrix-vector multiplication, 
 * matrix-matrix multiplication and others.
 */
template<typename T>
class Matrix {
  private:
    /// The number of rows in the matrix
    int rows_;

    /// The number of columns in the matrix
    int cols_;

    /// The data of the matrix
    std::vector<T> data_;

  public:
    /**
     * Default Constructor
     * 
     * Creates an empty matrix with 0 rows and 0 columns.
     */
    Matrix(): rows_(0), cols_(0) { }

    /**
     * Default Move Constructor
     */
    Matrix(const Matrix&) = default;

    /**
     * Default Destructor
     */
    ~Matrix() = default;

    /**
     * General Constructor
     * 
     * Creates an mxn matrix with m rows and n columns.
     */
    Matrix(const int &m, const int &n): rows_(m), cols_(n) { }

    Matrix(const int &m, const int &n, 
      std::initializer_list<std::initializer_list<T>> lst): rows_(m), cols_(n) { }

    /**
     * Square Constructor
     * 
     * Creates an nxn matrix with the same number of rows and columns.
     */
    Matrix(const int &n): rows_(n), cols_(n) { }

    Matrix(const int &n,
      std::initializer_list<std::initializer_list<T>> lst): rows_(n), cols_(n) { }
    /**
     * Resizes a matrix M from an mxn matrix to a pxq matrix.
     * 
     * Takes in two integers p, q and then resizes the matrix M to be a pxq matrix.
     * If the matrix becomes larger, new values will be initialized to 0.
     * 
     * @param p the new number of rows
     * @param q the new number of columns
     * 
     * @returns the same matrix, with p rows and q columns
     */
    Matrix& resize(const int &p, const int &q);

    /**
     * Resizes a matrix M from m rows to p rows.
     * 
     * Takes in an integer p and then resizes the matrix M to have p rows.
     * If the matrix becomes larger, new values will be initialized to 0.
     * 
     * @param p the new number of rows
     * 
     * @returns the same matrix with p rows
     */
    Matrix& resize_rows(const int &p);

    /**
     * Resizes a matrix M from n columns to q columns.
     * 
     * Takes in an integer q and then resizes the matrix M to have q columns.
     * If the matrix becomes larger, new values will be initialized to 0.
     * 
     * @param q the new number of rows
     * 
     * @returns the same matrix with p rows
     */
    Matrix& resize_cols(const int &q);

    /**
     * Default Copy-Assignment Operator
     */
    Matrix& operator=(const Matrix&);
};

} // namespace mmath
