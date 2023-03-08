#include "ConvertedNumber.hpp"

ConvertedNumber::ConvertedNumber(std::string originalType, std::string arg) : _originalType(originalType) {
    if (originalType == "float") {
        // pode ser nanf !
        // float f = std::stof(arg);
        // std::cout << "The float value is: " << f << std::endl;
    }
    if (originalType == "double") {
        // pode ser nan !
    }
    if (originalType == "char")
        this->_toChar = arg[0];
};

ConvertedNumber::ConvertedNumber(const ConvertedNumber &other) {};

ConvertedNumber::~ConvertedNumber() {};

ConvertedNumber &ConvertedNumber::operator=(const ConvertedNumber &other) {};


void convertToFloat();
void convertToDouble();
void convertToChar();