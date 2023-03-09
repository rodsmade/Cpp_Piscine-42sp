#include "ConvertedNumber.hpp"

ConvertedNumber::ConvertedNumber(std::string originalType, std::string arg) : _originalType(originalType) {
    if (originalType == "float") {
        // pode ser nanf !
        this->_toFloat = std::atof(arg.c_str());
        this->_toDouble = static_cast<double>(this->_toFloat);
        this->_toChar = static_cast<char>(this->_toFloat);
    }
    if (originalType == "double") {
        // pode ser nan !
        this->_toDouble = std::strtod(arg.c_str(), NULL);
        this->_toFloat = static_cast<float>(this->_toDouble);
        this->_toChar = static_cast<char>(this->_toDouble);
    }
    if (originalType == "char") {
        this->_toChar = arg[0];
        this->_toDouble = static_cast<double>(this->_toChar);
        this->_toFloat = static_cast<float>(this->_toChar);
    }
};

// ConvertedNumber::ConvertedNumber(const ConvertedNumber &other){};

ConvertedNumber::~ConvertedNumber(){};

// ConvertedNumber &ConvertedNumber::operator=(const ConvertedNumber &other){};

void convertToFloat();
void convertToDouble();
void convertToChar();

void ConvertedNumber::printNumberInAllFormats(void){
    // float f = std::atof(argv[1]);
    // // Set the number of decimal places to 1 and enable fixed-point notation
    // std::cout << std::fixed << std::setprecision(1);
    // // Print the float with a decimal point and trailing zeros
    // std::cout << "The float value is: " << f << "f" << std::endl;
    // CHAR
    std::cout << "char: " << this->_toChar << std::endl;
    // INT
    std::cout << "int: " << "TBA" << std::endl;
    // FLOAT
    std::cout << "float: " << this->_toFloat << std::endl;
    // DOUBLE
    std::cout << "double: " << this->_toDouble << std::endl;
};