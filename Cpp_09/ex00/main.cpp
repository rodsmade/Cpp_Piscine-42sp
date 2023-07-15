#include <cstdlib>  // exit()

#include "BitcoinExchange.hpp"

void    validate_args(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
    }
    std::FILE* file = std::fopen(argv[1], "r");
    if (file == NULL) {
        std::cout << "Error: could not open file." << std::endl;
        std::exit(-1);
    }

    std::fclose(file);
    std::cout << "File exists and has read permission. Now do sth with it." << std::endl;
}

// void    load_database() {
//     const char* filename = "cpp_09/data.csv";
//     std::FILE* file = std::fopen(filename, "r");

//     BitcoinExchange database(file);
// }

int main(int argc, char **argv) {
    std::cout << "HELLO HELLO, HE, HELLO, HELLO" << std::endl;
    validate_args(argc, argv);

    // load_database();
    return 0;
}

