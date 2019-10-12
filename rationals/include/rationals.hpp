#pragma once

#include <iostream>

namespace mmath {

/**
 * Implementation of a rational class for mathematics
 * 
 * This class implements a base class to perform mathematics with exact percision using rational numbers.
 */
class Rational {
  private:
    int numer;
    int denom;

  public:
    /**
     * General Constructor
     * 
     * Creates an arbitary rational number x/y.
     * 
     * @param x the numerator of the fraction
     * @param y the denominator of the fraction
     */
    Rational(const int &x, const int &y) : numer(x), denom(y) { }

    /**
     * Default Constructor
     * 
     * Creates the rational number 0.
     */
    Rational() : Rational(0, 1) { }

    /**
     * Whole Number Constructor
     * 
     * Creates any whole number x/1
     */
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

    bool irreducible();
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
