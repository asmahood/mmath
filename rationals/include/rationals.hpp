#ifndef GUARD_RATIONALS_H
#define GUARD_RATIONALS_H

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

    // Getters
    int get_numer() const { return numer; }
    int get_denom() const { return denom; }

    // Setters
    void set_numer(const int &x) { numer = x; }
    void set_denom(const int &x) { denom = x; }

    // Methods
    void print();
    Rational& reduce();
    Rational& scale(const int &c);
    Rational& power(const int &n);

    Rational& add(const int &a);
    Rational& subtract(const int &a);
    Rational& multiply(const int &a);
    Rational& divide(const int &);
};

} // namespace mmath

mmath::Rational operator+(const mmath::Rational &lhs, const mmath::Rational &rhs);
mmath::Rational operator-(const mmath::Rational &lhs, const mmath::Rational &rhs);
mmath::Rational operator*(const mmath::Rational &lhs, const mmath::Rational &rhs);
mmath::Rational operator/(const mmath::Rational &lhs, const mmath::Rational &rhs);
bool operator==(const mmath::Rational &lhs, const mmath::Rational &rhs);
bool operator!=(const mmath::Rational &lhs, const mmath::Rational &rhs);

#endif
