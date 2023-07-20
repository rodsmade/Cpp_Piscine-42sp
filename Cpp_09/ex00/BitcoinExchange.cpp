#include "BitcoinExchange.hpp"

BitcoinExchange::Date::InvalidDateException::InvalidDateException(const std::string &message) : _errorMessage(message){};

BitcoinExchange::Date::InvalidDateException::~InvalidDateException() throw(){};

const char *BitcoinExchange::Date::InvalidDateException::what() const throw() {
    return _errorMessage.c_str();
};

BitcoinExchange::Date::Date() : _day(0), _month(0), _year(0){};

BitcoinExchange::Date::Date(std::string dateString) {
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
    if (
        ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && _day == 31) ||
        (_year % 4 && _month == 2 && _day > 28) ||
        ((_year % 4 == 0) && _month == 2 && _day > 29))
        throw InvalidDateException("You silly goose! Quit the shenanigans!");
};

BitcoinExchange::Date::~Date(){};

BitcoinExchange::Date &BitcoinExchange::Date::operator=(const Date &other) {
    if (*this != other) {
        _year = other._year;
        _month = other._month;
        _day = other._day;
    }
    return *this;
};

bool BitcoinExchange::Date::operator==(const Date &rhs) const {
    return !(*this != rhs);
};

bool BitcoinExchange::Date::operator!=(const Date &rhs) const {
    return (_year != rhs._year || _month != rhs._month || _day != rhs._day);
};

bool BitcoinExchange::Date::operator<(const Date &rhs) const {
    return (
        _year < rhs._year ||
        (_year == rhs._year && _month < rhs._month) ||
        (_year == rhs._year && _month == rhs._month && _day < rhs._day));
};

bool BitcoinExchange::Date::operator<=(const Date &rhs) const {
    return (*this == rhs || *this < rhs);
};

////////////////////////////////////////////////////////////

BitcoinExchange::BitcoinExchange(void){};

BitcoinExchange::~BitcoinExchange(){};

float &BitcoinExchange::operator[](Date &key) {
    return _database[key];
};

void BitcoinExchange::loadDatabase() {
    std::ifstream databaseFile("cpp_09/data.csv");
    if (!databaseFile.is_open())
        throw std::runtime_error("Failed to open the database file");

    try {
        std::string line;
        std::getline(databaseFile, line);
        while (std::getline(databaseFile, line)) {
            std::string key = line.substr(0, 10);
            std::string value = line.substr(10 + 1);
            _database[Date(key)] = std::atof(value.c_str());
        }
    } catch (const std::exception &e) {
        databaseFile.close();
        throw;
    }

    databaseFile.close();
};

BitcoinExchange::Date BitcoinExchange::floor(const Date &date) {
    if (date <= Date(std::string("2009-01-01")))
        return _database.begin()->first;

    std::map<Date, float>::iterator datePosition = _database.find(date);
    if (datePosition != _database.end())
        return datePosition->first;

    std::map<Date, float>::iterator it = _database.begin();
    while (true) {
        if (it->first < date)
            it++;
        else
            return (--it)->first;
    }
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database){};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (_database != other._database) {
        _database = other._database;
    };
    return *this;
};
