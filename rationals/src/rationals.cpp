#include "rationals.hpp"

#include <cmath>
#include <iostream>

#include "util.hpp"

void mmath::Rational::print() {
  std::cout << numer << "/" << denom << '\n';
}

mmath::Rational& mmath::Rational::reduce() {
  // trivial case (a / a)
  if (numer == denom) {
    numer = 1; denom = 1;
    return *this;
  }

  // irreducible fraction
  if (denom < 3) return *this;

  // find gcd of numerator and denominator and divide
  int div = gcd(numer, denom);

  numer /= div;
  denom /= div;

  return *this;
}

mmath::Rational& mmath::Rational::scale(const unsigned int &c) {
  if (c == 0) return *this;

  numer *= c;
  denom *= c;

  return *this;
}

mmath::Rational& mmath::Rational::power(const unsigned int &n) {
  if (n == 0) {
    numer = 1; denom = 1;
    return *this;
  }

  numer = std::pow(numer, n);
  denom = std::pow(denom, n);

  return *this;
}

mmath::Rational& mmath::Rational::scalar(const int &c) {
  numer *= c;

  return *this;
}

mmath::Rational operator+(const mmath::Rational &lhs, const mmath::Rational &rhs) {
  mmath::Rational sum;

  sum.set_numer(lhs.get_numer() * rhs.get_denom() +
                rhs.get_numer() * lhs.get_denom());
  sum.set_denom(lhs.get_denom() * rhs.get_denom());

  return sum;
}

mmath::Rational operator-(const mmath::Rational &lhs, const mmath::Rational &rhs) {
  mmath::Rational diff;

  diff.set_numer(lhs.get_numer() * rhs.get_denom() -
                 rhs.get_numer() * lhs.get_denom());
  diff.set_denom(lhs.get_denom() * rhs.get_denom());

  return diff;
}

mmath::Rational operator*(const mmath::Rational &lhs, const mmath::Rational &rhs) {
  mmath::Rational prod;

  prod.set_numer(lhs.get_numer() * rhs.get_numer());
  prod.set_denom(lhs.get_denom() * rhs.get_denom());

  return prod;
}

mmath::Rational operator/(const mmath::Rational &lhs, const mmath::Rational &rhs) {
  mmath::Rational quot;

  quot.set_numer(lhs.get_numer() * rhs.get_denom());
  quot.set_denom(lhs.get_denom() * rhs.get_numer());

  return quot;
}

bool operator==(const mmath::Rational &lhs, const mmath::Rational &rhs) {
  return lhs.get_numer() == rhs.get_numer() &&
         lhs.get_denom() == rhs.get_denom();
}

bool operator!=(const mmath::Rational &lhs, const mmath::Rational &rhs) {
  return !(lhs == rhs);
}

