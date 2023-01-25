#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.6f));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    Fixed c(4.2f);
    Fixed d;
    d = Fixed(5.6f);
    std::cout << "c: " << c << " e d: " << d << std::endl;
    std::cout << (c / d) << std::endl;
    return 0;
}