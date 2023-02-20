#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <cmath>
#include <iostream>

class Fixed {
   public:
    Fixed(void);
    Fixed(const Fixed &other);
    Fixed(int const integer);
    Fixed(float const bobber);
    ~Fixed(void);
    Fixed &operator=(const Fixed &other);
    bool operator>(const Fixed &other);
    bool operator<(const Fixed &other);
    bool operator>=(const Fixed &other);
    bool operator<=(const Fixed &other);
    bool operator==(const Fixed &other);
    bool operator!=(const Fixed &other);
    Fixed operator+(const Fixed &other);
    Fixed operator-(const Fixed &other);
    Fixed operator*(const Fixed &other);
    Fixed operator/(const Fixed &other);
    Fixed &operator++();    // Prefix increment operator.
    Fixed operator++(int);  // Postfix increment operator.
    Fixed &operator--();    // Prefix decrement operator.
    Fixed operator--(int);  // Postfix decrement operator.

    static Fixed const &min(Fixed &a, Fixed &b);
    static Fixed const &min(Fixed const &a, Fixed const &b);
    static Fixed const &max(Fixed &a, Fixed &b);
    static Fixed const &max(Fixed const &a, Fixed const &b);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

   private:
    int _rawBits;
    static const int _precisionBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rightHandSide);

#endif
