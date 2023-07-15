#include <cstdlib>

#include "BitcoinExchange.hpp"

void    validate_args(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        std::exit(-1);
    }
    (void) argv;
}

int main(int argc, char **argv) {
    std::cout << "HELLO HELLO, HE, HELLO, HELLO" << std::endl;
    validate_args(argc, argv);
    
    return 0;
}

