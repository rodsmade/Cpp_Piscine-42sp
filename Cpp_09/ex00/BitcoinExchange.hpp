#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

class BitcoinExchange {
   public:
    class Date {
       private:
        int _day;
        int _month;
        int _year;

       public:
        class InvalidDateException : public std::exception {
           public:
            InvalidDateException(const std::string &message) : _errorMessage(message) {}
            ~InvalidDateException() throw(){};
            virtual const char *what() const throw() {
                return _errorMessage.c_str();
            }

           private:
            std::string _errorMessage;
        };

        Date();
        Date(std::string dateString);
        ~Date();
        // Date(const Date &other);
        Date &operator=(const Date &other);

        // logical operator overload
        bool operator==(const Date &rhs) const;
        bool operator!=(const Date &rhs) const;
        bool operator<(const Date &rhs) const;
        bool operator<=(const Date &rhs) const;
    };

    BitcoinExchange();  // loads .csv into map for faster lookup
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    float &operator[](Date &key);
    void loadDatabase();
    Date floor(const Date &date);  // returns the date inside `database` equal to or immediately smaller than `date`

   private:
    std::map<Date, float> _database;
};

#endif