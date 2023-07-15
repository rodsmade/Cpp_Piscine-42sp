#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

class Date {
   private:
    int day;
    int month;
    int year;

   public:
    Date(std::string dateStr);
    ~Date();
    Date(const Date &other);
    Date &operator=(const Date &other);

    // implement operators > and ==, probably 
};

class BitcoinExchange {
   private:
    // std::map<Date, float> _database;
    std::map<std::string, std::string> _database;

   public:
    BitcoinExchange(void); // loads .csv into map for faster lookup
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    Date floor(const Date &date); // returns the date inside `database` equal to or immediately smaller than `date`
};

#endif