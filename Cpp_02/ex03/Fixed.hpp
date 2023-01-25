#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <cmath>
#include <iostream>

class Fixed {
   private:
    int _rawBits;
    static const int _binaryPointPosition = 8;

   public:
    // Constructors/Destructor
    Fixed(void);
    Fixed(const Fixed &other);
    Fixed(int const integer);
    Fixed(float const bobber);
    ~Fixed(void);

    // Accessors
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Operator Overloads
    //  Assignment operator
    Fixed &operator=(const Fixed &other);

    // Logical operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &other);
    Fixed operator-(const Fixed &other);
    Fixed operator*(const Fixed &other);
    Fixed operator/(const Fixed &other);

    // Increment/Decrement operators
    Fixed &operator++();    // Prefix increment operator.
    Fixed operator++(int);  // Postfix increment operator.
    Fixed &operator--();    // Prefix decrement operator.
    Fixed operator--(int);  // Postfix decrement operator.


	// Member functions
	// Object level
    float toFloat(void) const;
    int toInt(void) const;
	
	// Class level
    static Fixed const &min(Fixed &a, Fixed &b);
    static Fixed const &min(Fixed const &a, Fixed const &b);
    static Fixed const &max(Fixed &a, Fixed &b);
    static Fixed const &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &o, Fixed const &rightHandSide);

#endif
