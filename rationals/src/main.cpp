#include <iostream>

#include "rationals.hpp"

using mmath::Rational;

int main() {
  Rational x = {1, 2};
  Rational y = {3, 4};

  Rational sum = x + y;
  Rational diff = x - y;
  Rational prod = x * y;
  Rational quot = x / y;

  Rational recip = x.reciprocal();

  Rational pow = x.power(-2);

  // Equality
  std::cout << "Two rationals are equal: " << (x == y ? "TRUE" : "FALSE") << '\n';
  std::cout << "Two rationals are not equal: " << (x != y ? "TRUE" : "FALSE") << '\n';

  sum.print();
  diff.print();
  prod.print();
  quot.print();
  recip.print();
  pow.print();
  return 0;
}
