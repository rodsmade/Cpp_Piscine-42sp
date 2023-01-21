#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0) {};

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits) {};

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _rawBits = other._rawBits;
    }
    return (*this);
};

Fixed::~Fixed(void) {};

int Fixed::getRawBits(void) const {
        return (_rawBits);
    };

void Fixed::setRawBits(int const raw) {
        _rawBits = raw;
    };