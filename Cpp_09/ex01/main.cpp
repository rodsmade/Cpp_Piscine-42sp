#include <cstdlib>  // exit()
#include <iostream>

#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Error\n";
        return (EXIT_FAILURE);
    }

    RPN polishReckoner;
    try {
        polishReckoner.reckon(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return (EXIT_FAILURE);
    }

    std::cout << polishReckoner.getResult() << std::endl;
    return (EXIT_SUCCESS);
};
