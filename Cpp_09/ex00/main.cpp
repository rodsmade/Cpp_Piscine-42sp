#include <cstdlib>  // exit()

#include "BitcoinExchange.hpp"

void    validate_args(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        std::exit(-1);
    }
    std::FILE* file = std::fopen(argv[1], "r");
    if (file == NULL) {
        std::cout << "Error: could not open file." << std::endl;
        std::exit(-1);
    }

    std::fclose(file);
    std::cout << "File exists and has read permission. Now do sth with it." << std::endl;
}

int main(int argc, char **argv) {
    std::cout << "HELLO HELLO, HE, HELLO, HELLO" << std::endl;
    validate_args(argc, argv);

    try {
        BitcoinExchange database;
    } catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        // Perform any necessary cleanup or logging here
        // You may also choose to exit the program gracefully
    }

    return 0;
}

