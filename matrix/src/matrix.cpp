#include "matrix.hpp"

#include <vector>

#include "number_trait.hpp"

template<typename T>
mmath::Matrix<T>::Matrix() {
  static_assert(is_number<T>::value, "Cannot create a matrix of this type");
}

template<typename T>
mmath::Matrix<T>::Matrix(const int &m, const int &n) {
  static_assert(is_number<T>::value, "Cannot create a matrix of this type");
}

template<typename T>
mmath::Matrix<T>::Matrix(const int &n) {
  static_assert(is_number<T>::value, "Cannot create a matrix of this type");
}