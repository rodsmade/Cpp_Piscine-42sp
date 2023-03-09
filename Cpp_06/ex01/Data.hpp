#pragma once

#include <iostream>

class Data {
   public:
    std::string _importantTidbit;
    std::string _relevantTidbit;
    std::string _interestingTidbit;
    Data();
    Data(std::string importantTidbit, std::string relevantTidbit, std::string interestingTidbit);
    Data(const Data &other);
    Data &operator=(const Data &other);
    ~Data();
};
