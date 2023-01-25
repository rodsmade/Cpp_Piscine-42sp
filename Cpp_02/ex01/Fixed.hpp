#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <cmath>

class Fixed {
   public:
    Fixed(void);
    Fixed(const Fixed &other);
    Fixed(int const integer);
    Fixed(float const bobber);
    Fixed &operator=(const Fixed &other);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat( void ) const;
    int toInt( void ) const;

   private:
    int _rawBits;
    static const int _binaryPointPosition = 8;
};

std::ostream & operator<<(std::ostream &o, Fixed const &rightHandSide);

#endif
