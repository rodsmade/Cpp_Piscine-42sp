#include <cstdlib>  // for rand() and srand()
#include <iostream>

#include "Array.hpp"

#define BOLD "\033[1m"
#define LIGHT_BLUE "\033[94m"
#define LIGHT_RED "\033[91m"
#define ORANGE "\033[38;2;255;165;0m"
#define VIOLET "\033[38;2;75;0;130m"
#define RESET "\033[0m"

#define MAX_VAL 750  // SUBJECT TESTS

int main(int, char**) {
    {  // SUBJECT TESTS
        std::cout << std::endl
                  << "============= Subject Tests =============" << std::endl;
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++) {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        // SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++) {
            if (mirror[i] != numbers[i]) {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try {
            numbers[-2] = 0;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        try {
            numbers[MAX_VAL] = 0;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++) {
            numbers[i] = rand();
        }
        delete[] mirror;  //
    }
    {  // MY TESTS
        std::cout << std::endl
        << "=============== My Tests  ===============" << std::endl;

        // TEST 1
        std::cout << BOLD VIOLET "TEST 1 - DEFAULT CONSTRUCTOR" RESET << std::endl;
        Array<int> myArr(5);

        std::cout << BOLD VIOLET "| `myArr' is " << myArr.size() << " elements long." RESET << std::endl;
        std::cout << BOLD VIOLET "| " RESET;
        myArr.printAllElements();
        std::cout << std::endl;

        // TEST 2
        std::cout << BOLD ORANGE "TEST 2 - COPY CONSTRUCTOR" RESET << std::endl;
        Array<int> copy(myArr);

        for (unsigned int i = 0; i < copy.size(); i++)
            copy[i] = 42;

        std::cout << BOLD ORANGE "| `copy' is " << copy.size() << " elements long." RESET << std::endl;
        std::cout << BOLD ORANGE "| " RESET;
        copy.printAllElements();
        std::cout << BOLD ORANGE "| " RESET;
        std::cout << BOLD VIOLET "`myArr' is " << myArr.size() << " elements long." RESET << std::endl;
        std::cout << BOLD ORANGE "| " RESET;
        myArr.printAllElements();
        std::cout << std::endl;

        // TEST 3
        std::cout << BOLD LIGHT_BLUE "TEST 3 - ASSIGNMENT OPERATOR" RESET << std::endl;
        Array<int> assign;
        assign = Array<int>(copy);
        for (unsigned int i = 0; i < assign.size(); i++)
            assign[i] = -42;
        std::cout << BOLD LIGHT_BLUE "| `assign' is " << assign.size() << " elements long." RESET << std::endl;
        std::cout << BOLD LIGHT_BLUE "| " RESET;
        assign.printAllElements();
        std::cout << BOLD LIGHT_BLUE "| ";
        std::cout << BOLD ORANGE "`copy' is " << copy.size() << " elements long." RESET << std::endl;
        std::cout << BOLD LIGHT_BLUE "| " RESET;
        copy.printAllElements();
        std::cout << BOLD LIGHT_BLUE "| ";
        std::cout << BOLD VIOLET "`myArr' is " << myArr.size() << " elements long." RESET << std::endl;
        std::cout << BOLD LIGHT_BLUE "| " RESET;
        myArr.printAllElements();
        std::cout << std::endl;

        std::cout << BOLD LIGHT_RED "TEST 4 - ACCESSING WRONG INDEXES" RESET << std::endl;
        try {
            std::cout << "myArr[5]: " << myArr[5] << std::endl;
        } catch (const std::exception& e) {
            std::cout << LIGHT_RED BOLD << e.what() << RESET << std::endl;
        }
        try {
            std::cout << "myArr[-1]: " << myArr[-1] << std::endl;
        } catch (const std::exception& e) {
            std::cout << LIGHT_RED BOLD << e.what() << RESET << std::endl;
        }
        try {
            std::cout << "myArr[2147483647]: " << myArr[2147483647] << std::endl;
        } catch (const std::exception& e) {
            std::cout << LIGHT_RED BOLD << e.what() << RESET << std::endl;
        }
    }

    return 0;
}
