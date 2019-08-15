#include <iostream>

#include "rationals.hpp"

using mmath::Rational;

int main() {
  Rational a = {1, 2};
  Rational b = {3, 4};

  std::cout << "Print tests\n";
  std::cout << a << " " << b << "\n";

  // Addition tests
  Rational c = a + b;
  Rational d = a + 1;
  Rational e = 1 + b;

  std::cout << "Addition tests\n";
  std::cout << c << " " << d << " " << e << "\n";

  // Subtraction tests
  Rational f = a - b;
  Rational g = a - 1;
  Rational h = 1 - b;

  std::cout << "Subtraction tests\n";
  std::cout << f << " " << g << " " << h << "\n";

  // Multiplication tests
  Rational i = a * b;
  Rational j = a * 2;
  Rational k = 2 * b;

  std::cout << "Multiplication tests\n";
  std::cout << i << " " << j << " " << k << "\n";

  // Division Tests
  Rational l = a / b;
  Rational m = a / 2;
  Rational n = 2 / b;

  std::cout << "Division tests\n";
  std::cout << l << " " << m << " " << n << "\n";

  // Equality
  std::cout << "Two rationals are equal: " << (a == b ? "TRUE" : "FALSE") << '\n';
  std::cout << "Two rationals are not equal: " << (a != b ? "TRUE" : "FALSE") << '\n';

  return 0;
}
