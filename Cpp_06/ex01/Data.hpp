#pragma once

#include <iostream>

class Data {
   public:
    std::string _importantTidbit;
    std::string _relevantTidbit;
    std::string _interestingTidbit;
    Data();
    Data(const Data &other);
    Data &operator=(const Data &other);
    ~Data();
};
