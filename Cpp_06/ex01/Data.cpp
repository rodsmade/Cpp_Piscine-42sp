#include "Data.hpp"

Data::Data() {
    this->_importantTidbit = "nothing";
    this->_relevantTidbit = "nil";
    this->_interestingTidbit = "nada";
};

Data::Data(const Data &other) : _importantTidbit(other._importantTidbit), _relevantTidbit(other._relevantTidbit), _interestingTidbit(other._interestingTidbit){};

Data &Data::operator=(const Data &other) {
    if (this != &other) {
        this->_importantTidbit = other._importantTidbit;
        this->_relevantTidbit = other._relevantTidbit;
        this->_interestingTidbit = other._interestingTidbit;
    }
    return (*this);
};

Data::~Data(){};
