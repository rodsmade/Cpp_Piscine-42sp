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

   private:
    int _rawBits;
    static const int _binaryPointPosition = 8;
};

#endif