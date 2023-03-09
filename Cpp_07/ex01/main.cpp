#include <cctype>
#include <iostream>

#include "iter.hpp"

char toUpper(char element) {
    return (std::toupper(element));
}

int powerOfTwo(int element) {
    return(element * element);
}

int main() {
    // TEST 1 = STRING
    char *ptr;
    unsigned int size = 11;

    std::string henlo = "hello world";
    ptr = (char *)henlo.c_str();

    iter(ptr, size, toUpper);

    std::cout << "Result 1 (string): " << ptr << std::endl;

    // TEST 2 = INT
    size = 10;
    int* arrayOfInts = new int[size];
    for (int i = 0; (unsigned int) i < size; i++)
        arrayOfInts[i] = i + 1;

    iter(arrayOfInts, size, powerOfTwo);

    std::cout << "Result 2 (int): ";
    for (unsigned int i = 0; i < size; i++)
        std::cout << arrayOfInts[i] << " ";
    std::cout << std::endl;

    // TEST 3 = INSTANTIATED TEMPLATE FUNCTION
    iter(arrayOfInts, size, sumItself<int>);

    std::cout << "Result 3 (instantiated template function): ";
    for (unsigned int i = 0; i < size; i++)
        std::cout << arrayOfInts[i] << " ";
    std::cout << std::endl;

}