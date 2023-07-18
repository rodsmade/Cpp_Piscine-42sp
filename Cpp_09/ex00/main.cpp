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

void splitString(const std::string& str, std::string& beforePipe, std::string& afterPipe) {
    size_t pipePos = str.find('|');

    if (pipePos != std::string::npos) {
        beforePipe = str.substr(0, pipePos);
        afterPipe = str.substr(pipePos + 1);
    }
    else {
        beforePipe = str;
        afterPipe = "";
    }
}

void parse_input_line_and_print_result(std::string line, BitcoinExchange &database) {

    std::string beforePipe, afterPipe;
    splitString(line, beforePipe, afterPipe);
    beforePipe.pop_back();


    Date date = Date(beforePipe);
    Date correctedDate = database.floor(date);
    float converted = std::atof(afterPipe.c_str());
    float result = database[correctedDate] * converted;

    std::cout << beforePipe << " =>" << afterPipe << " = " << result << "\n";
}

int main(int argc, char **argv) {
    validate_args(argc, argv);

    std::ifstream input_file(argv[1]);

    try {
        BitcoinExchange database;
        std::string line;

        std::getline(input_file, line);
        while (std::getline(input_file, line)) {
            parse_input_line_and_print_result(line, database);
        }
    } catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }

    input_file.close();

    return 0;
}

