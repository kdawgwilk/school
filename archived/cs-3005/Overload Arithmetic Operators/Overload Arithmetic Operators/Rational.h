#ifndef _RATIONAL_H_
#define _RATIONAL_H_

class Rational
{
public:
    Rational();
    Rational(const int n_in, const int d_in);
    int getNumerator() const;
    int getDenominator() const;

    Rational operator+(const Rational &rhs) const;
    Rational operator*(const Rational &rhs) const;
    Rational operator-(const Rational &rhs) const;
    Rational operator/(const Rational &rhs) const;

    // Rational &operator=(const Rational &rhs);
    // Rational &operator+=(const Rational &rhs);
    // bool operator==(const Rational &rhs) const;
    // bool operator<(const Rational &rhs) const;
    // operator bool() const;

protected:
    void addition(const int n_in, const int d_in);
    void multiplication(const int n_in, const int d_in);
    void simplify();

    int numerator;
    int denominator;
};



#endif /* _RATIONAL_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
