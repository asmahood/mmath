#ifndef GUARD_RATIONALS_H
#define GUARD_RATIONALS_H

#include <iostream>

namespace mmath {

class Rational {
  private:
    int numer;
    int denom;

  public:
    // Constructors
    Rational(const int &x, const int &y) : numer(x), denom(y) { }
    Rational() : Rational(0, 1) { }
    Rational(const int &x) : Rational(x, 1) { }

    int get_numer() const { return numer; }
    int get_denom() const { return denom; }
    void set_numer(const int &x) { numer = x; }
    void set_denom(const int &x) { denom = x; }

    // Static functions
    static Rational reduce(const Rational& rat);
    static Rational reciprocal(const Rational& rat);

    // Class methods
    Rational& scale(const unsigned int &c);
    Rational& power(const int &n);
};

} // namespace mmath

std::ostream& operator<<(std::ostream &os, const mmath::Rational &rat);
std::istream& operator>>(std::istream &is, mmath::Rational &rat);

bool operator==(const mmath::Rational &lhs, const mmath::Rational &rhs);
bool operator!=(const mmath::Rational &lhs, const mmath::Rational &rhs);

///////////////////////////////////////////////////////////
// ADDITION OPERATORS
///////////////////////////////////////////////////////////

// Rational + Rational
mmath::Rational operator+(const mmath::Rational &lhs, const mmath::Rational &rhs);

// Rational + Int
mmath::Rational operator+(const mmath::Rational &lhs, const int &rhs);

// Int + Rational
mmath::Rational operator+(const int &lhs, const mmath::Rational &rhs);

///////////////////////////////////////////////////////////
// SUBTRACTION OPERATORS
///////////////////////////////////////////////////////////

// Rational - Rational
mmath::Rational operator-(const mmath::Rational &lhs, const mmath::Rational &rhs);

// Rational - Int
mmath::Rational operator-(const mmath::Rational &lhs, const int &rhs);

// Int - Rational
mmath::Rational operator-(const int &lhs, const mmath::Rational &rhs);

///////////////////////////////////////////////////////////
// MULTIPLCATION OPERATORS
///////////////////////////////////////////////////////////

// Rational * Rational
mmath::Rational operator*(const mmath::Rational &lhs, const mmath::Rational &rhs);

// Rational * Int
mmath::Rational operator*(const mmath::Rational &lhs, const int &rhs);

// Int * Rational
mmath::Rational operator*(const int &lhs, const mmath::Rational &rhs);

///////////////////////////////////////////////////////////
// DIVISION OPERATORS
///////////////////////////////////////////////////////////

// Rational / Rational
mmath::Rational operator/(const mmath::Rational &lhs, const mmath::Rational &rhs);

// Rational / Int
mmath::Rational operator/(const mmath::Rational &lhs, const int &rhs);

// Int / Rational
mmath::Rational operator/(const int &lhs, const mmath::Rational &rhs);

#endif
