#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

class Date {
   private:
    int _day;
    int _month;
    int _year;

   public:
    class InvalidDateException : public std::exception {
       public:
        InvalidDateException(const std::string& message) : _errorMessage(message) {}
        ~InvalidDateException() throw() {};
        virtual const char* what() const throw() {
            return _errorMessage.c_str();
        }

       private:
        std::string _errorMessage;
    };

    Date(std::string dateString);
    ~Date();
    // Date(const Date &other);
    Date &operator=(const Date &other);

    // logical operator overload
    bool operator<(const Date &rhs) const;
};

class BitcoinExchange {
   private:
    std::map<Date, float> _database;

   public:
    BitcoinExchange(void); // loads .csv into map for faster lookup
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    float &operator[](Date &key);
    Date floor(const Date &date); // returns the date inside `database` equal to or immediately smaller than `date`
};

#endif