#include <iostream>

#include "Span.hpp"

#define BOLD "\033[1m"
#define LIGHT_RED "\033[91m"
#define RESET "\033[0m"

int main() {
    {  // MANDATORY TESTS
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    {  // MY TESTS
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
        std::cout << "Shortest span: " << caixinha.shortestSpan() << std::endl;
        std::cout << "Longest span: " << caixinha.longestSpan() << std::endl;

        Span caixa2(1);
        caixa2.addNumber(42);
        try {
            caixa2.shortestSpan();
        } catch (const std::exception &e) {
            std::cout << " ❌ " BOLD LIGHT_RED << e.what() << RESET << std::endl;
        }
        try {
            caixa2.longestSpan();
        } catch (const std::exception &e) {
            std::cout << " ❌ " BOLD LIGHT_RED << e.what() << RESET << std::endl;
        }
    }
    {
        std::cout << "\nTEST 1 - Adding 500 elements to 10.000-sized Span\n";
        Span caixinha(10000);

        for (int i = 0; i < 9500; i++) {
            caixinha.addNumber(i);
        }
        std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;


        std::vector<int> caixa2(0);

        for (int i = 0; i < 500; i++) {
            caixa2.push_back(9500 + i);
        }
        std::cout << "Size of caixa2: " << caixa2.size() << std::endl;

        caixinha.addNumber(caixa2.begin(), caixa2.end());
        std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;
    }
    {
        std::cout << "\nTESTE 2 - Adding 1.000 elements to 10.000-sized Span\n";
        Span caixinha(10000);

        for (int i = 0; i < 9500; i++) {
            caixinha.addNumber(i);
        }
        std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;


        std::vector<int> caixa2(0);
        for (int i = 0; i < 1000; i++) {
            caixa2.push_back(9500 + i);
        }
        std::cout << "Size of caixa2: " << caixa2.size() << std::endl;


        try {
            caixinha.addNumber(caixa2.begin(), caixa2.end());
            std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;
        } catch (const std::exception &e) {
            std::cout << " ❌ " BOLD LIGHT_RED << e.what() << RESET << std::endl;
            std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;
        }

    }
    {
        std::cout << "\nTESTE 3 - Finding Shortest/Longest in 0-sized Span\n";
        Span caixinha(0);

        std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;

        try {
            caixinha.addNumber(42);
            std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;
        } catch (const std::exception &e) {
            std::cout << " ❌ " BOLD LIGHT_RED << e.what() << RESET << std::endl;
            std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;
        }
        try {
            std::cout << "Shortest span: " << caixinha.shortestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cout << " ❌ " BOLD LIGHT_RED << e.what() << RESET << std::endl;
            std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;
        }
        try {
            std::cout << "Longest span: " << caixinha.longestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cout << " ❌ " BOLD LIGHT_RED << e.what() << RESET << std::endl;
            std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;
        }
    }
    {
        std::cout << "\nTESTE 4 - Finding Shortest/Longest in 1-sized Span\n";
        Span caixinha(1);

        std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;

        try {
            caixinha.addNumber(42);
            std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;
        } catch (const std::exception &e) {
            std::cout << " ❌ " BOLD LIGHT_RED << e.what() << RESET << std::endl;
            std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;
        }
        try {
            std::cout << "Shortest span: " << caixinha.shortestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cout << " ❌ " BOLD LIGHT_RED << e.what() << RESET << std::endl;
            std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;
        }
        try {
            std::cout << "Longest span: " << caixinha.longestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cout << " ❌ " BOLD LIGHT_RED << e.what() << RESET << std::endl;
            std::cout << "Size of caixinha: " << caixinha.getSize() << std::endl;
        }
    }
    return 0;
}
