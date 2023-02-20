#include "Fixed.hpp"

// CONSTRUCTORS / DESTRUCTOR ===================================================
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

    while (sum < fractPart) {
        sum += 0.00390625;
        fractPartToBin++;
    }

    this->_rawBits += fractPartToBin;
};

Fixed::~Fixed(void){};

// ACCESSORS ===================================================================
int Fixed::getRawBits(void) const {
    return (_rawBits);
};

void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
};

// OPERATOR OVERLOADS ==========================================================
// ASSIGNMENT OPERATOR -------------------------------------------------
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _rawBits = other.getRawBits();
    }
    return (*this);
};

// LOGICAL OPERATORS ---------------------------------------------------
bool Fixed::operator>(const Fixed &other) const {
    return (this->getRawBits() > other.getRawBits());
};

bool Fixed::operator<(const Fixed &other) const {
    return (this->getRawBits() < other.getRawBits());
};

bool Fixed::operator>=(const Fixed &other) const {
    return (this->getRawBits() >= other.getRawBits());
};

bool Fixed::operator<=(const Fixed &other) const {
    return (this->getRawBits() <= other.getRawBits());
};

bool Fixed::operator==(const Fixed &other) const {
    return (this->getRawBits() == other.getRawBits());
};

bool Fixed::operator!=(const Fixed &other) const {
    return (this->getRawBits() != other.getRawBits());
};

// ARITHMETIC OPERATOR -------------------------------------------------
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;

    result.setRawBits(this->getRawBits() + other.getRawBits());
    return (result);
};

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;

    result.setRawBits(this->getRawBits() - other.getRawBits());
    return (result);
};

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;

    // faço um shift right no final da multiplicação porque fica com 8 bits a mais o final da multiplicação do raw pelo raw.
    result.setRawBits((this->getRawBits() * other.getRawBits()) >> 8);
    return (result);
};

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;

    long int a = this->getRawBits() << this->_precisionBits;
    int b = other.getRawBits();

    result.setRawBits((int)a / b);

    return (result);
};

// INCREMENT OPERATORS -------------------------------------------------
Fixed &Fixed::operator++() {
    this->setRawBits(this->getRawBits() + 0x0001);
    return *(this);
};

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    temp.setRawBits(temp.getRawBits() + 0x0001);
    return (temp);
};

Fixed &Fixed::operator--() {
    this->setRawBits(this->getRawBits() - 0x0001);
    return *(this);
};

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    temp.setRawBits(temp.getRawBits() - 0x0001);
    return (temp);
};

// OUTPUT STREAM OPERATOR ----------------------------------------------
std::ostream &operator<<(std::ostream &o, Fixed const &rightHandSide) {
    o << rightHandSide.toFloat();
    return (o);
};

// MEMBER FUNCTIONS ============================================================
// OBJECT LEVEL --------------------------------------------------------
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

// CLASS LEVEL ---------------------------------------------------------
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
