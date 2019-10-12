#pragma once

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
    /// The number of rows
    int rows_;

    /// The number of columns
    int cols_;

    /// The data of the matrix
    std::vector<T> data_;

  public:
    /**
     * Default Constructor
     * 
     * Creates an empty matrix with 0 rows and 0 columns.
     */
    Matrix(): rows_(0), cols_(0) { } = default

    /**
     * General Constructor
     * 
     * Creates an mxn matrix with m rows and n columns.
     */
    Matrix(const int &m, const int &n): rows_(m), cols_(n) { }

    /**
     * Square Constructor
     * 
     * Creates an nxn matrix with the same number of rows and columns
     */
    Matrix(const int &n): rows_(n), cols_(n) { }
};

} // namespace mmath
