#include <cstdlib>  // exit()

#include "BitcoinExchange.hpp"

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

    std::string exchangeRateDateStr, principalAmountStr;

    splitString(line, exchangeRateDateStr, principalAmountStr);
    // Remove trailing ' ' from string
    while (*(--exchangeRateDateStr.end()) == ' ')
        exchangeRateDateStr.pop_back();

    if (principalAmountStr == "") {
        std::cout << "Error: bad input => " << line << std::endl;
        return ;
    }

    float principalAmount = std::atof(principalAmountStr.c_str());
    if (principalAmount < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return ;
    }

    if (principalAmount > 1000.0) {
        std::cout << "Error: too large a number." << std::endl;
        return ;
    }

    BitcoinExchange::Date exchange_rate_date;
    try {
        exchange_rate_date = BitcoinExchange::Date(exchangeRateDateStr);
    } catch(const std::exception& e) {
        std::cerr << "Error: bad input => " << exchangeRateDateStr << ". " << e.what() << std::endl;
        return ;
    }

    BitcoinExchange::Date correctedDate = database.floor(exchange_rate_date);
    float convertedAmount = database[correctedDate] * principalAmount;
    std::cout << exchangeRateDateStr << " =>" << principalAmountStr << " = " << convertedAmount << "\n";
}

int main(int argc, char **argv) {
   if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    BitcoinExchange bitcoinExchange;
    try {
        bitcoinExchange.load_database();
    } catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
    };

    std::string line;
    std::getline(input_file, line); // pops first line (header)
    while (std::getline(input_file, line)) {
        parse_input_line_and_print_result(line, bitcoinExchange);
    }

    input_file.close();

    return (EXIT_SUCCESS);
}
