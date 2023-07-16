#include "BitcoinExchange.hpp"

Date::Date(std::string dateString) {
    if (dateString.length() != 10 || dateString[4] != '-' || dateString[7] != '-')
        throw InvalidDateException("Invalid date format. Expected YYYY-MM-DD.");

    _year = std::atoi(dateString.substr(0, 4).c_str());
    _month = std::atoi(dateString.substr(5, 2).c_str());
    _day = std::atoi(dateString.substr(8, 2).c_str());

    if (_year < 0 || _year > 2023)
        throw InvalidDateException("Invalid year. Pick between [0, 2023].");
    if (_month < 1 || _month > 12)
        throw InvalidDateException("Invalid month. Pick between [1, 12].");
    if (_day < 1 || _day > 31)
        throw InvalidDateException("Invalid day. Pick between [1, 31].");
    if  (
            ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && _day == 31) ||
            (_month == 2 && _day > 28) ||
            ((_year % 4 == 0) && _month == 2 && _day > 29)
        )
        throw InvalidDateException("You sneaky shmuck! Quit the shenanigans!");
};

Date::~Date(){};

bool Date::operator<(const Date& rhs) const {
    return  (
                _year < rhs._year ||
                (_year == rhs._year && _month < rhs._month) ||
                (_year == rhs._year && _month == rhs._month && _day < rhs._day)
            );
};

////////////////////////////////////////////////////////////

BitcoinExchange::BitcoinExchange(void) {
    std::ifstream database_file("cpp_09/data.csv");
    if (!database_file.is_open())
        throw std::runtime_error("Failed to open the database file");

    try {
        std::string line;
        std::getline(database_file, line);
        while (std::getline(database_file, line)) {
            std::string key = line.substr(0, 10);
            std::string value = line.substr(10 + 1);
            _database[Date(key)] = std::atof(value.c_str());
        }
        std::cout << "map size: " << _database.size() << std::endl;
    } catch (const std::exception& e) {
        database_file.close();
        throw;
    }

    database_file.close();
}

BitcoinExchange::~BitcoinExchange(){};