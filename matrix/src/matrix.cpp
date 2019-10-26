#include "matrix.hpp"

#include "number_trait.hpp"

template<typename T>
mmath::Matrix<T>::Matrix() {
  static_assert(is_number<T>::value, "Cannot create a matrix of this type");

  data_();
}

template<typename T>
mmath::Matrix<T>::Matrix(const int &m, const int &n) {
  static_assert(is_number<T>::value, "Cannot create a matrix of this type");

  data_(m * n, T());
}

template<typename T>
mmath::Matrix<T>::Matrix(const int &m, const int &n,
  std::initializer_list<std::initializer_list<T>> lst) {
  static_assert(is_number<T>::value, "Cannot create a matrix of this type");

}

template<typename T>
mmath::Matrix<T>::Matrix(const int &n) {
  static_assert(is_number<T>::value, "Cannot create a matrix of this type");

  data_(n * n, T());
}

template<typename T>
mmath::Matrix<T>::Matrix(const int &n, 
  std::initializer_list<std::initializer_list<T>> lst) {
  static_assert(is_number<T>::value, "Cannot create a matrix of this type");

}