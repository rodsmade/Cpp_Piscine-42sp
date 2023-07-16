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

    return;
}

void parse_input_line_and_print_result(std::string line) {
    std::cout << "input line: " << line << std::endl;
}

int main(int argc, char **argv) {
    std::cout << "HELLO HELLO, HE, HELLO, HELLO" << std::endl;
    validate_args(argc, argv);

    std::ifstream input_file(argv[1]);

    try {
        BitcoinExchange database;
        std::string line;

        std::getline(input_file, line);
        while (std::getline(input_file, line)) {
            parse_input_line_and_print_result(line);
        }
    } catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }

    input_file.close();

    return 0;
}

