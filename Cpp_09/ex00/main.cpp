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

    std::string exchange_rate_date_str, principal_amount_str;
    splitString(line, exchange_rate_date_str, principal_amount_str);
    while (*(--exchange_rate_date_str.end()) == ' ')
        exchange_rate_date_str.pop_back();  // removes trailing '' from string

    if (principal_amount_str == "") {
        std::cout << "Error: bad input => " << exchange_rate_date_str << std::endl;
        return ;
    }

    float principal_amount = std::atof(principal_amount_str.c_str());
    if (principal_amount < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return ;
    }

    if (principal_amount > 2147483647.0) {
        std::cout << "Error: too large a number." << std::endl;
        return ;
    }

    Date exchange_rate_date;
    try {
        exchange_rate_date = Date(exchange_rate_date_str);
    } catch(const std::exception& e) {
        std::cerr << "Error: bad input => " << exchange_rate_date_str << ". " << e.what() << std::endl;
        return ;
    }

    Date correctedDate = database.floor(exchange_rate_date);
    float converted_amount = database[correctedDate] * principal_amount;

    std::cout << exchange_rate_date_str << " =>" << principal_amount_str << " = " << converted_amount << "\n";
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

