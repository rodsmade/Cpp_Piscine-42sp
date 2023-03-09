#include <cctype>
#include <iostream>

#include "iter.hpp"

char toUpper(char element) {
    return (std::toupper(element));
}

int main() {
    char *teste;
    unsigned int size = 11;

    std::string henlo = "hello world";

    teste = (char *)henlo.c_str();

    iter(teste, size, toUpper);

    std::cout << "Result: " << teste << std::endl;

}