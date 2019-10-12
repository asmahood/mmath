#include "rationals.hpp"

#include <cmath>

#include "util.hpp"

mmath::Rational mmath::Rational::reduce(const mmath::Rational& rat) {
  int numer_ = rat.get_numer(), denom_ = rat.get_denom();

  // trivial case (a / a)
  if (numer_ == denom_) return mmath::Rational(1);

  // irreducible fraction
  if (numer_ % denom_ != 0 && denom_ <= 3) return rat;

  // find gcd of numerator and denominator and divide
  int div = util::gcd(numer_, denom_);
  numer_ /= div;
  denom_ /= div;

  return mmath::Rational(numer_, denom_);
}

mmath::Rational mmath::Rational::reciprocal(const mmath::Rational& rat) {
  return mmath::Rational(rat.get_denom(), rat.get_numer());
}

mmath::Rational& mmath::Rational::scale(const unsigned int &c) {
  if (c == 0) return *this;

  numer_ *= c;
  denom_ *= c;

  return *this;
}

mmath::Rational& mmath::Rational::power(const int &n) {
  if (n == 0) {
    numer_ = 1; denom_ = 1;
    return *this;
  } else if (n < 0) {
    return reciprocal(*this).power(-n);
  }

  numer_ = std::pow(numer_, n);
  denom_ = std::pow(denom_, n);

  return *this;
}

bool mmath::Rational::irreducible() {
  return numer_ % denom_ != 0 && denom_ <= 3;
}

std::ostream& operator<<(std::ostream &os, const mmath::Rational &rat) {
  os << rat.get_numer() << "/" << rat.get_denom();

  return os;
}

std::istream& operator>>(std::istream &is, mmath::Rational &rat) {
  int num, den;

  is >> num >> den;

  if (is) {
    rat.set_numer(num);
    rat.set_denom(den);
  } else {
    rat = mmath::Rational();
  }

  return is;
}

bool operator==(const mmath::Rational &lhs, const mmath::Rational &rhs) {
  return lhs.get_numer() == rhs.get_numer() &&
         lhs.get_denom() == rhs.get_denom();
}

bool operator!=(const mmath::Rational &lhs, const mmath::Rational &rhs) {
  return !(lhs == rhs);
}

///////////////////////////////////////////////////////////
// ADDITION OPERATORS
///////////////////////////////////////////////////////////

// Rational + Rational
// a/b + c/d = a*d + c*b / b*d
mmath::Rational operator+(const mmath::Rational &lhs, const mmath::Rational &rhs) {
  mmath::Rational sum;

  sum.set_numer(lhs.get_numer() * rhs.get_denom() +
                rhs.get_numer() * lhs.get_denom());
  sum.set_denom(lhs.get_denom() * rhs.get_denom());

  return sum;
}

// Rational + Int
// a/b + x/1 = a + bx / b
mmath::Rational operator+(const mmath::Rational &lhs, const int &rhs) {
  mmath::Rational sum;

  sum.set_numer(lhs.get_numer() + rhs * lhs.get_denom());
  sum.set_denom(lhs.get_denom());

  return sum;
}

// Int + Rational
// x/1 + a/b = x*b + a / b
mmath::Rational operator+(const int &lhs, const mmath::Rational &rhs) {
  return rhs + lhs;
}

///////////////////////////////////////////////////////////
// SUBTRACTION OPERATORS
///////////////////////////////////////////////////////////

// Rational - Rational
// a/b - c/d = a*d - c*b / b*d
mmath::Rational operator-(const mmath::Rational &lhs, const mmath::Rational &rhs) {
  mmath::Rational diff;

  diff.set_numer(lhs.get_numer() * rhs.get_denom() -
                 rhs.get_numer() * lhs.get_denom());
  diff.set_denom(lhs.get_denom() * rhs.get_denom());

  return diff;
}

// Rational - Int
// a/b - x/1 = a - x*b / b
mmath::Rational operator-(const mmath::Rational &lhs, const int &rhs) {
  mmath::Rational diff;

  diff.set_numer(lhs.get_numer() - rhs * lhs.get_denom());
  diff.set_denom(lhs.get_denom());

  return diff;
}

// Int - Rational
// x/1 - a/b = x*b - a / b
mmath::Rational operator-(const int &lhs, const mmath::Rational &rhs) {
  mmath::Rational diff;

  diff.set_numer(lhs * rhs.get_denom() - rhs.get_numer());
  diff.set_denom(rhs.get_denom());

  return diff;
}

///////////////////////////////////////////////////////////
// MULTIPLCATION OPERATORS
///////////////////////////////////////////////////////////

// Rational * Rational
// a/b * c/d = a*c / b*d
mmath::Rational operator*(const mmath::Rational &lhs, const mmath::Rational &rhs) {
  mmath::Rational prod;

  prod.set_numer(lhs.get_numer() * rhs.get_numer());
  prod.set_denom(lhs.get_denom() * rhs.get_denom());

  return prod;
}

// Rational * Int
// a/b * x/1 = a*x / b
mmath::Rational operator*(const mmath::Rational &lhs, const int &rhs) {
  mmath::Rational prod;

  prod.set_numer(lhs.get_numer() * rhs);
  prod.set_denom(lhs.get_denom());

  return prod;
}

// Int * Rational
// x/1 * a/b = x*a / b
mmath::Rational operator*(const int &lhs, const mmath::Rational &rhs) {
  return rhs * lhs;
}

///////////////////////////////////////////////////////////
// DIVISION OPERATORS
///////////////////////////////////////////////////////////

// Rational / Rational
// a/b / c/d = a*d / c*b
mmath::Rational operator/(const mmath::Rational &lhs, const mmath::Rational &rhs) {
  mmath::Rational quot;

  quot.set_numer(lhs.get_numer() * rhs.get_denom());
  quot.set_denom(lhs.get_denom() * rhs.get_numer());

  return quot;
}

// Rational * Int
// a/b / x/1 = a / b*x
mmath::Rational operator/(const mmath::Rational &lhs, const int &rhs) {
  mmath::Rational quot;

  quot.set_numer(lhs.get_numer());
  quot.set_denom(rhs * lhs.get_denom());

  return quot;
}

// Int * Rational
// x/1 / a/b = x*b / a
mmath::Rational operator/(const int &lhs, const mmath::Rational &rhs) {
  mmath::Rational quot;

  quot.set_numer(lhs * rhs.get_denom());
  quot.set_denom(rhs.get_numer());

  return quot;
}

