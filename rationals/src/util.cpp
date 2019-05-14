#include "util.hpp"

int util::gcd(const int &x, const int &y) {
  if (y == 0) return x;

  if (y > x) return gcd(y, x);

  gcd(y, x % y);
}

