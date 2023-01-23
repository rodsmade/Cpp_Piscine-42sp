#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0) { std::cout << "Default constructor called" << std::endl; };

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
};

Fixed::Fixed(int const integer) {
    std::cout << "Integer constructor called" << std::endl;
    this->_rawBits = integer << this->_binaryPointPosition;
};

Fixed::Fixed(float const bobber) {
    std::cout << "Float constructor called" << std::endl;
    int roundNumber = (int) bobber;
    this->_rawBits = roundNumber << this->_binaryPointPosition;

    float sum = 0.0;
    int fractPartToBin = 0;

    double fractPart, intPart;
    fractPart = std::modf(bobber, &intPart);
    
    while (sum < fractPart) {
        sum += 0.00390625;
        fractPartToBin++;
    }

    this->_rawBits += fractPartToBin;
};

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _rawBits = other.getRawBits();
    }
    return (*this);
};

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; };

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
};

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
};

float Fixed::toFloat( void ) const {
    int integerPart = this->getRawBits() >> 8;
    int rawBitsTemp = this->getRawBits();
    float fractionalPart = 0.0;

    for (int i = this->_binaryPointPosition; i > 0; i--) {
        fractionalPart += 1 / pow(2, i) * (rawBitsTemp & 0x0001);
        rawBitsTemp = rawBitsTemp >> 1;
    }

    return (integerPart + fractionalPart);
};

int Fixed::toInt( void ) const {
    return (this->getRawBits() >> 8);
};
