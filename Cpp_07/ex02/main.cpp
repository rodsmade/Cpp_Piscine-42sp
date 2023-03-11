#include <iostream>

#include "Array.hpp"

#define BOLD "\033[1m"
#define ORANGE "\033[38;2;255;165;0m"
#define VIOLET "\033[38;2;75;0;130m"
#define DARK_GRAY "\033[90m"
#define BG_LIGHT_YELLOW "\033[103m"
#define LIGHT_GREEN "\033[92m"
#define LIGHT_YELLOW "\033[93m"
#define LIGHT_BLUE "\033[94m"
#define LIGHT_CYAN "\033[96m"
#define LIGHT_MAGENTA "\033[95m"
#define LIGHT_RED "\033[91m"
#define RESET "\033[0m"

int main() {
    // TEST 1
    std::cout << BOLD VIOLET "TEST 1 - DEFAULT CONSTRUCTOR" RESET << std::endl;
    Array<int> myArr(5);

    std::cout << BOLD VIOLET "| myArr is " << myArr.size() << " elements long." RESET << std::endl;
    std::cout << BOLD VIOLET "| " RESET;
    myArr.printAllElements();
    std::cout << std::endl;

    // TEST 2
    std::cout << BOLD ORANGE "TEST 2 - COPY CONSTRUCTOR" RESET << std::endl;
    Array<int> copy(myArr);

    for (unsigned int i = 0; i < copy.size(); i++)
        copy[i] = 42;

    std::cout << BOLD ORANGE "| copy is " << copy.size() << " elements long." RESET << std::endl;
    std::cout << BOLD ORANGE "| " RESET;
    copy.printAllElements();
    std::cout << BOLD ORANGE "| " RESET;
    std::cout << BOLD VIOLET "myArr is " << myArr.size() << " elements long." RESET << std::endl;
    std::cout << BOLD ORANGE "| " RESET;
    myArr.printAllElements();
    std::cout << std::endl;

    // TEST 3
    std::cout << BOLD LIGHT_BLUE "TEST 3 - ASSIGNMENT OPERATOR" RESET << std::endl;
    Array<int> assign;
    assign = Array<int>(copy);
    for (unsigned int i = 0; i < assign.size(); i++)
        assign[i] = -42;
    std::cout << BOLD LIGHT_BLUE "| assign is " << assign.size() << " elements long." RESET << std::endl;
    std::cout << BOLD LIGHT_BLUE "| " RESET;
    assign.printAllElements();
    std::cout << BOLD LIGHT_BLUE "| ";
    std::cout << BOLD ORANGE "copy is " << copy.size() << " elements long." RESET << std::endl;
    std::cout << BOLD LIGHT_BLUE "| " RESET;
    copy.printAllElements();
    std::cout << BOLD LIGHT_BLUE "| ";
    std::cout << BOLD VIOLET "myArr is " << myArr.size() << " elements long." RESET << std::endl;
    std::cout << BOLD LIGHT_BLUE "| " RESET;
    myArr.printAllElements();
    std::cout << std::endl;

    try {
        std::cout << "myArr[5]: " << myArr[5] << std::endl;
    } catch (const std::exception &e) {
        std::cout << LIGHT_RED BOLD << e.what() << RESET << std::endl;
    }

    return 0;
}
