#pragma once

#include "rationals.hpp"

template<typename T>
struct is_number {
  static const bool value = false;
};

template<>
struct is_number<unsigned short> {
  static const bool value = true;
};

template<>
struct is_number<short> {
  static const bool value = true;
};

template<>
struct is_number<unsigned int> {
  static const bool value = true;
};

template<>
struct is_number<int> {
  static const bool value = true;
};

template<>
struct is_number<unsigned long> {
  static const bool value = true;
};

template<>
struct is_number<long> {
  static const bool value = true;
};

template<>
struct is_number<unsigned long long> {
  static const bool value = true;
};

template<>
struct is_number<float> {
  static const bool value = true;
};

template<>
struct is_number<double> {
  static const bool value = true;
};

template<>
struct is_number<long double> {
  static const bool value = true;
};

template<>
struct is_number<mmath::Rational> {
  static const bool value = true;
};