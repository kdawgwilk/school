#include "Rational.h"
#include <cstdlib>

Rational::Rational()
  : numerator(0), denominator(0)
{
  // empty
}

Rational::Rational(const int n_in, const int d_in)
  : numerator(n_in), denominator(d_in)
{
  simplify();
}

int Rational::getNumerator() const
{
  return numerator;
}

int Rational::getDenominator() const
{
  return denominator;
}

void Rational::addition(const int n_in, const int d_in)
{ // add numerator / denominator to this
  /*
   * Addition of fractions
   * a/b + c/d = (ad+cb)/(bd)
   */
  int n = numerator * d_in + denominator * n_in;
  int d = denominator * d_in;
  numerator = n;
  denominator = d;
  simplify();
}

void Rational::multiplication(const int n_in, const int d_in)
{ // multiply numerator / denominator into this
  /*
   * Multiplication of fractions
   * a/b * c/d = (ac)/(bd)
   */
  int n = numerator * n_in;
  int d = denominator * d_in;
  numerator = n;
  denominator = d;
  simplify();
}

void Rational::simplify()
{
  int u = std::abs(numerator), v = std::abs(denominator);
  int t;
  while(v)
    {
      t = u;
      u = v;
      v = t % v;
    }
  numerator /= u;
  denominator /= u;
}

Rational Rational::operator+(const Rational &rhs) const
{
    int n = numerator * rhs.denominator + denominator * rhs.numerator;
    int d = denominator * rhs.denominator;
    Rational new_rational(n, d);
    new_rational.simplify();
    return new_rational;
}

Rational Rational::operator*(const Rational &rhs) const
{
    int n = numerator * rhs.numerator;
    int d = denominator * rhs.denominator;
    Rational new_rational(n, d);
    new_rational.simplify();
    return new_rational;
}

Rational Rational::operator-(const Rational &rhs) const
{
    int n = numerator * rhs.denominator + denominator * -rhs.numerator;
    int d = denominator * rhs.denominator;
    Rational new_rational(n, d);
    new_rational.simplify();
    return new_rational;
}

Rational Rational::operator/(const Rational &rhs) const
{
    int n = numerator * rhs.denominator;
    int d = denominator * rhs.numerator;
    Rational new_rational(n, d);
    new_rational.simplify();
    return new_rational;
}
