#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0){};

Fixed::Fixed(const Fixed &other) {
    *this = other;
};

Fixed::Fixed(int const integer) {
    this->_rawBits = integer << this->_precisionBits;
};

Fixed::Fixed(float const bobber) {
    int roundNumber = (int)bobber;
    this->_rawBits = roundNumber << this->_precisionBits;

    float sum = 0.0;
    int fractPartToBin = 0;

    double fractPart, intPart;
    fractPart = std::modf(bobber, &intPart);
    if (fractPart < 0)
        fractPart *= (-1);

    while (sum < fractPart) {
        sum += 0.00390625;
        fractPartToBin++;
    }

    if (bobber < 0)
        this->_rawBits -= fractPartToBin;
    else
        this->_rawBits += fractPartToBin;
};

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _rawBits = other.getRawBits();
    }
    return (*this);
};

Fixed::~Fixed(void){};

int Fixed::getRawBits(void) const {
    return (_rawBits);
};

void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
};

float Fixed::toFloat(void) const {
    int integerPart = this->getRawBits() >> 8;
    int rawBitsTemp = this->getRawBits();
    float fractionalPart = 0.0;

    for (int i = this->_precisionBits; i > 0; i--) {
        fractionalPart += 1 / pow(2, i) * (rawBitsTemp & 0x0001);
        rawBitsTemp = rawBitsTemp >> 1;
    }

    return (integerPart + fractionalPart);
};

int Fixed::toInt(void) const {
    return (this->getRawBits() >> 8);
};

std::ostream &operator<<(std::ostream &o, Fixed const &rightHandSide) {
    o << rightHandSide.toFloat();
    return (o);
};

bool Fixed::operator>(const Fixed &other) {
    return (this->getRawBits() > other.getRawBits());
};

bool Fixed::operator<(const Fixed &other) {
    return (this->getRawBits() < other.getRawBits());
};

bool Fixed::operator>=(const Fixed &other) {
    return (this->getRawBits() >= other.getRawBits());
};

bool Fixed::operator<=(const Fixed &other) {
    return (this->getRawBits() <= other.getRawBits());
};

bool Fixed::operator==(const Fixed &other) {
    return (this->getRawBits() == other.getRawBits());
};

bool Fixed::operator!=(const Fixed &other) {
    return (this->getRawBits() != other.getRawBits());
};

Fixed Fixed::operator+(const Fixed &other) {
    Fixed result;

    result.setRawBits(this->getRawBits() + other.getRawBits());
    return (result);
};

Fixed Fixed::operator-(const Fixed &other) {
    Fixed result;

    result.setRawBits(this->getRawBits() - other.getRawBits());
    return (result);
};

Fixed Fixed::operator*(const Fixed &other) {
    Fixed result;

    // faço um shift right no final da multiplicação porque fica com 8 bits a mais o final da multiplicação do raw pelo raw.
    result.setRawBits((this->getRawBits() * other.getRawBits()) >> 8);
    return (result);
};

Fixed Fixed::operator/(const Fixed &other) {
    Fixed result;

    long int a = this->getRawBits() << this->_precisionBits;
    int b = other.getRawBits();

    result.setRawBits((int)a / b);

    return (result);
};

Fixed &Fixed::operator++() {  // Prefix increment
    this->setRawBits(this->getRawBits() + 0x0001);
    return *(this);
};

Fixed Fixed::operator++(int) {  // Postfix increment
    Fixed temp(*this);
    this->setRawBits(this->getRawBits() + 0x0001);
    return (temp);
};

Fixed &Fixed::operator--() {
    this->setRawBits(this->getRawBits() - 0x0001);
    return *(this);
};

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->setRawBits(this->getRawBits() - 0x0001);
    return (temp);
};

Fixed const &Fixed::min(Fixed &a, Fixed &b) {
    if (a > b) {
        return (b);
    } else {
        return (a);
    }
};

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
    Fixed copyA(a);
    Fixed copyB(b);

    if (copyA > copyB) {
        return (b);
    } else {
        return (a);
    }
};

Fixed const &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b) {
        return (a);
    } else {
        return (b);
    }
};

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
    Fixed copyA(a);
    Fixed copyB(b);

    if (copyA > copyB) {
        return (a);
    } else {
        return (b);
    }
};
