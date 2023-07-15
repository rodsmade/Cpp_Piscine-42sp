#include "BitcoinExchange.hpp"

Date::Date(std::string dateStr) {
    (void) dateStr;
};
Date::~Date() {};

BitcoinExchange::BitcoinExchange(void) {
    std::ifstream database_file("cpp_09/data.csv");
    if (!database_file.is_open())
        throw std::runtime_error("Failed to open the database file");

    try {
        std::string line;
        while (std::getline(database_file, line)) {
            std::string key = line.substr(0, 10);
            std::string value = line.substr(10 + 1);
            _database[key] = value;
        }
        std::cout << "map size: " << _database.size() << std::endl;
    }
    catch(const std::exception& e) {
        database_file.close();
        throw;
    }

    database_file.close();
}

BitcoinExchange::~BitcoinExchange() {};