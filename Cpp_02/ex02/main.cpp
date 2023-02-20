#include <cassert>
#include "Colours.hpp"
#include "Fixed.hpp"

int main(void) {
    // {
    // 	// Official tests
    // 	Fixed a;
    // 	Fixed const b(Fixed(5.6f));

    // 	std::cout << a << std::endl;
    // 	std::cout << ++a << std::endl;
    // 	std::cout << a << std::endl;
    // 	std::cout << a++ << std::endl;
    // 	std::cout << a << std::endl;
    // 	std::cout << b << std::endl;
    // 	std::cout << b.getRawBits() << std::endl;
    // 	std::cout << Fixed::max(a, b) << std::endl;
    // }
    {
        // Extra tests
        Fixed a(42.42f);
        Fixed b;

        // << operator (printing)
        std::cout << LIGHT_RED << "'<<' Operator:" << RESET << std::endl;
        std::cout << "  a : " << a << std::endl;
        std::cout << "  b : " << b << std::endl;
        std::cout << std::endl;

        // operator=
        std::cout << ORANGE << "'=' Operator:" << RESET << std::endl;
        b = a;
        std::cout << "  a : " << a << std::endl;
        std::cout << "  b : " << b << std::endl;
        std::cout << std::endl;

        // logical operators
        std::cout << LIGHT_YELLOW << "Logical Operators:" << RESET << std::endl;
        std::cout << "  a : " << a << std::endl;
        std::cout << "  b : " << b << std::endl;
        assert((a > b) == false);
        std::cout << "  a > b : " << ((a > b) ? "true" : "false") << std::endl;
        assert((a < b) == false);
        std::cout << "  a < b : " << ((a < b) ? "true" : "false") << std::endl;
        assert((a >= b) == true);
        std::cout << "  a >= b : " << ((a >= b) ? "true" : "false") << std::endl;
        assert((a <= b) == true);
        std::cout << "  a <= b : " << ((a <= b) ? "true" : "false") << std::endl;
        assert((a == b) == true);
        std::cout << "  a == b : " << ((a == b) ? "true" : "false") << std::endl;
        assert((a != b) == false);
        std::cout << "  a != b : " << ((a != b) ? "true" : "false") << std::endl;
        std::cout << std::endl;


        // arithmetic operators
        std::cout << LIGHT_GREEN << "Arithmetic Operators:" << RESET << std::endl;
     	Fixed c(4.2f);
    	Fixed d = Fixed(5.6f);
    	std::cout << "  c: " << c << "; d: " << d << std::endl;
        std::cout << "  c + d : " << (c + d) << std::endl;
        std::cout << "  c - d : " << (c - d) << std::endl;
        std::cout << "  c * d : " << (c * d) << std::endl;
        std::cout << "  c / d : " << (c / d) << std::endl;
     	std::cout << std::endl;

        c = Fixed(-4.2f);
    	d = Fixed(5.6f);
    	std::cout << "  c: " << c << "; d: " << d << std::endl;
        std::cout << "  c + d : " << (c + d) << std::endl;
        std::cout << "  c - d : " << (c - d) << std::endl;
        std::cout << "  c * d : " << (c * d) << std::endl;
        std::cout << "  c / d : " << (c / d) << std::endl;
     	std::cout << std::endl;

        c = Fixed(4.2f);
    	d = Fixed(-5.6f);
    	std::cout << "  c: " << c << "; d: " << d << std::endl;
        std::cout << "  c + d : " << (c + d) << std::endl;
        std::cout << "  c - d : " << (c - d) << std::endl;
        std::cout << "  c * d : " << (c * d) << std::endl;
        std::cout << "  c / d : " << (c / d) << std::endl;
     	std::cout << std::endl;

        c = Fixed(-4.2f);
    	d = Fixed(-5.6f);
    	std::cout << "  c: " << c << "; d: " << d << std::endl;
        std::cout << "  c + d : " << (c + d) << std::endl;
        std::cout << "  c - d : " << (c - d) << std::endl;
        std::cout << "  c * d : " << (c * d) << std::endl;
        std::cout << "  c / d : " << (c / d) << std::endl;
     	std::cout << std::endl;

        c = Fixed(0.0f);
    	d = Fixed(-5.6f);
    	std::cout << "  c: " << c << "; d: " << d << std::endl;
        std::cout << "  c + d : " << (c + d) << std::endl;
        std::cout << "  c - d : " << (c - d) << std::endl;
        std::cout << "  c * d : " << (c * d) << std::endl;
        std::cout << "  c / d : " << (c / d) << std::endl;
     	std::cout << std::endl;

        c = Fixed(4.2f);
    	d = Fixed(0.0f);
    	std::cout << "  c: " << c << "; d: " << d << std::endl;
        std::cout << "  c + d : " << (c + d) << std::endl;
        std::cout << "  c - d : " << (c - d) << std::endl;
        std::cout << "  c * d : " << (c * d) << std::endl;
        std::cout << "  c / d : floating point exception :P" << std::endl;
     	std::cout << std::endl;
        
        
        // increment and decrement operators
        std::cout << LIGHT_BLUE << "Increment Operators:" << RESET << std::endl;
        a = Fixed(0);
        std::cout << "  initial value: " << a << std::endl;
        std::cout << "  " << ++a << std::endl;
        std::cout << "  " << a << std::endl;
        std::cout << "  " << a++ << std::endl;
        std::cout << "  " << a << std::endl;
     	std::cout << std::endl;

        std::cout << VIOLET << "Decrement Operators:" << RESET << std::endl;
        std::cout << "  initial value: " << a << std::endl;
        std::cout << "  " << --a << std::endl;
        std::cout << "  " << a << std::endl;
        std::cout << "  " << a-- << std::endl;
        std::cout << "  " << a << std::endl;
        std::cout << "  " << --a << std::endl;
        std::cout << "  " << --a << std::endl;
        std::cout << "  " << ++a << std::endl;
        std::cout << "  " << ++a << std::endl;
        std::cout << "  " << ++a << std::endl;
        std::cout << "  " << a-- << std::endl;
        std::cout << "  " << a << std::endl;
     	std::cout << "  " << std::endl;

        // min and max operators
        std::cout << MAGENTA << "min and max Operators:" << RESET << std::endl;
    	std::cout << "  a: " << a << "; b: " << b << std::endl;
        std::cout << "  max: " << Fixed::max(a, b) << std::endl;
    	std::cout << "  min: " << Fixed::min(a, b) << std::endl;
     	std::cout << "  " << std::endl;
    }
    return (0);
}