#include <iostream>

#include "Span.hpp"

#define BOLD "\033[1m"
#define LIGHT_RED "\033[91m"
#define RESET "\033[0m"

int main() {
    Span caixinha(5);

    caixinha.addNumber(420);
    caixinha.addNumber(4300);
    caixinha.addNumber(440000);
    caixinha.addNumber(4);
    caixinha.addNumber(460);
    try {
        caixinha.addNumber(47);
    } catch (const std::exception &e) {
        std::cout << " ❌ " BOLD LIGHT_RED << e.what() << RESET << std::endl;
    }

    // std::cout << "shortest span: " << caixinha.shortestSpan() << std::endl;
    caixinha.shortestSpan();


    return 0;
}
