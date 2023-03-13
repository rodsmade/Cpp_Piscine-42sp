#include <iostream>

#include "Span.hpp"

#define BOLD "\033[1m"
#define LIGHT_RED "\033[91m"
#define RESET "\033[0m"

int main() {
    Span caixinha(5);

    caixinha.addNumber(42);
    caixinha.addNumber(43);
    caixinha.addNumber(44);
    caixinha.addNumber(45);
    caixinha.addNumber(46);
    try {
        caixinha.addNumber(47);
    } catch (const std::exception &e) {
        std::cout << " ❌ " BOLD LIGHT_RED << e.what() << RESET << std::endl;
    }
    return 0;
}
