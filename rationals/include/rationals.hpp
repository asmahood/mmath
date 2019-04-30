#ifndef GUARD_RATIONALS_H
#define GUARD_RATIONALS_H

class Rational {
  private:
    int numer;
    int denom;

  public:
    // Constructors
    Rational() = default;
    Rational(const int &x) : numer(x), denom(1) { }
    Rational(const int &x, const int &y) : numer(x), denom(y) { }
    
    // Destructors
    virtural ~Rational() = default;

    // Getters
    int get_numer() const { return numer; }
    int get_denom() const { return denom; }

    // Setters
    void set_numer(const int &x) { numer = x; }
    void set_denom(const int &x) { denom = x; }

    // Methods
    Rational& reduce();
};

Rational operator+(const Rational &lhs, const Rational &rhs);
Rational operator-(const Rational &lhs, const Rational &rhs);
Rational operator*(const Rational &lhs, const Rational &rhs);
Rational operator/(const Rational &lhs, const Rational &rhs);
bool operator==(const Rational &lhs, const Rational &rhs);
bool operator!=(const Rational &lhs, const Rational &rhs);

#endif
