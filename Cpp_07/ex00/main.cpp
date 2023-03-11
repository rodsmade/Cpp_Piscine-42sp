#include <iostream>

#include "whatever.hpp"

int main(void) {
    { // TESTING WITH INTS
        std::cout << "======= Testing with ints: =======" << std::endl;
        int a = 2;
        int b = 3;

        std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

        ::swap(a, b);

        std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
        std::cout << std::endl;
    }
    { // TESTING WITH STRINGS
        std::cout << "======= Testing with strings: =======" << std::endl;
        std::string a = "chaine1";
        std::string b = "chaine2";

        std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

        ::swap(a, b);

        std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
        std::cout << std::endl;
    }
    { // TESTING WITH FLOATS
        std::cout << "======= Testing with floats: =======" << std::endl;
        float a = 42.0f;
        float b = -42.0f;

        std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

        ::swap(a, b);

        std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
