#include <cctype>
#include <iostream>

#include "iter.hpp"

char toUpper(char element) {
    return (std::toupper(element));
}

int timesItself(int element) {
    return (element * element);
}

int main() {
    {  // TEST 1 = STRING
        std::cout << "====== TEST 1 - STRING ======" << std::endl;
        char *ptr;
        unsigned int size = 11;

        std::string henlo = "Hello world!";
        ptr = (char *)henlo.c_str();

        std::cout << "Original string:\t" << ptr << std::endl;

        iter(ptr, size, toUpper);

        std::cout << "String after iter:\t" << ptr << std::endl;
        std::cout << std::endl;
    }
    {  // TEST 2 = INT
        std::cout << "====== TEST 2 - INT ======" << std::endl;
        unsigned int size = 10;
        int *arrayOfInts = new int[size];

        for (int i = 0; (unsigned int)i < size; i++)
            arrayOfInts[i] = i + 1;

        std::cout << "Original int array:\t";
        for (unsigned int i = 0; i < size; i++)
            std::cout << arrayOfInts[i] << " ";
        std::cout << std::endl;

        iter(arrayOfInts, size, timesItself);

        std::cout << "Int array after iter:\t";
        for (unsigned int i = 0; i < size; i++)
            std::cout << arrayOfInts[i] << " ";
        std::cout << std::endl;
        std::cout << std::endl;

        delete[] arrayOfInts;
    }
    {  // TEST 3 = INSTANTIATED TEMPLATE FUNCTION
        std::cout << "====== TEST 3 - INSTANTIATED TEMPLATE FUNCTION ======" << std::endl;
        unsigned int size = 10;
        int *arrayOfInts = new int[size];

        for (int i = 0; (unsigned int)i < size; i++)
            arrayOfInts[i] = i + 1;

        std::cout << "Original int array:\t";
        for (unsigned int i = 0; i < size; i++)
            std::cout << arrayOfInts[i] << " ";
        std::cout << std::endl;

        iter(arrayOfInts, size, sumItself<int>);

        std::cout << "Int array after iter:\t";
        for (unsigned int i = 0; i < size; i++)
            std::cout << arrayOfInts[i] << " ";
        std::cout << std::endl;
        std::cout << "(using instantiated template function)" << std::endl;

        delete[] arrayOfInts;
    }

    return (0);
}
