#include "rationals.hpp"

#include <iostream>

#include "util.hpp"

void Rational::print() {
  std::cout << numer << "/" << denom << '\n';
}

Rational& Rational::reduce() {
  if (numer == denom) {
    numer = 1; denom = 1;
    return *this;
  }

  if (denom < 3) return *this;

  // find gcd of numerator and denominator and divide
  int div = gcd(numer, denom);

  numer /= div;
  denom /= div;

  return *this;
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
  Rational sum;

  sum.set_numer(lhs.get_numer() * rhs.get_denom() +
                rhs.get_numer() * lhs.get_denom());
  sum.set_denom(lhs.get_denom() * rhs.get_denom());

  return sum;
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
  Rational diff;

  diff.set_numer(lhs.get_numer() * rhs.get_denom() -
                 rhs.get_numer() * lhs.get_denom());
  diff.set_denom(lhs.get_denom() * rhs.get_denom());

  return diff;
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
  Rational prod;

  prod.set_numer(lhs.get_numer() * rhs.get_numer());
  prod.set_denom(lhs.get_denom() * rhs.get_denom());

  return prod;
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
  Rational quot;

  quot.set_numer(lhs.get_numer() * rhs.get_denom());
  quot.set_denom(lhs.get_denom() * rhs.get_numer());

  return quot;
}

bool operator==(const Rational &lhs, const Rational &rhs) {
  return lhs.get_numer() == rhs.get_numer() &&
         lhs.get_denom() == rhs.get_denom();
}

bool operator!=(const Rational &lhs, const Rational &rhs) {
  return !(lhs == rhs);
}

