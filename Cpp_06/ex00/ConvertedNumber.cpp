#include "ConvertedNumber.hpp"

ConvertedNumber::ConvertedNumber(std::string originalType, std::string arg) : _originalType(originalType) {
    if (originalType == "char") {
        this->_char = arg[0];

        this->_int = static_cast<int>(this->_char);
        this->_double = static_cast<double>(this->_char);
        this->_float = static_cast<float>(this->_char);
    }
    if (originalType == "int") {
        int temp = std::atoi(arg.c_str());

        this->_int = static_cast<int>(temp);
        this->_char = static_cast<char>(temp);
        this->_float = static_cast<float>(temp);
        this->_double = static_cast<double>(temp);
    }
    if (originalType == "float") {
        this->_float = std::atof(arg.c_str());

        this->_int = static_cast<int>(this->_float);
        this->_double = static_cast<double>(this->_float);
        this->_char = static_cast<char>(this->_float);
    }
    if (originalType == "double") {
        this->_double = std::strtod(arg.c_str(), NULL);

        this->_int = static_cast<int>(this->_double);
        this->_float = static_cast<float>(this->_double);
        this->_char = static_cast<char>(this->_double);
    }
};

ConvertedNumber::ConvertedNumber(const ConvertedNumber &other) : _char(other._char), _int(other._int), _float(other._float), _double(other._double){};

ConvertedNumber::~ConvertedNumber(){};

ConvertedNumber &ConvertedNumber::operator=(const ConvertedNumber &other){
    if (this != &other) {
        this->_char = other._char;
        this->_int = other._int;
        this->_float = other._float;
        this->_double = other._double;
    }
    return (*this);
};

bool ConvertedNumber::charAndIntConversionIsImpossible() {
    return (isnan(this->_double) || isinf(this->_double) || this->_double > INT_MAX || this->_double < INT_MIN || isnanf(this->_float) || isinff(this->_float || this->_float > INT_MAX || this->_float < INT_MIN));
};

void ConvertedNumber::printNumberInAllFormats(void) {
    // CHAR
    std::cout << "char: ";
    if (this->charAndIntConversionIsImpossible()) {
        std::cout << "impossible";
    } else if (!std::isprint(this->_char)) {
        std::cout << "Non displayable";
    } else {
        std::cout << this->_char;
    }
    std::cout << std::endl;

    // INT
    std::cout << "int: ";
    if (this->charAndIntConversionIsImpossible()) {
        std::cout << "impossible";
    } else {
        std::cout << this->_int;
    }
    std::cout << std::endl;

    // FLOAT
    // Set the number of decimal places to 1 and enable fixed-point notation
    int decimalPlaces = 0;
    float tempf = this->_float;
    while (std::abs(tempf - std::floor(tempf)) > 0.0001) {
        tempf *= 10.0;
        decimalPlaces++;
    }
    // Set the precision of the number that will be printed accordingly
    if (decimalPlaces == 0) {
        decimalPlaces++;
    }
    std::cout << std::fixed << std::setprecision(decimalPlaces);
    // Print the float with a decimal point and trailing zeros
    std::cout << "float: " << this->_float << "f" << std::endl;
    // DOUBLE
    decimalPlaces = 0;
    double temp = this->_double;
    while (std::abs(temp - std::floor(temp)) > 0.0001) {
        temp *= 10.0;
        decimalPlaces++;
    }
    if (decimalPlaces == 0) {
        decimalPlaces++;
    }
    std::cout << std::fixed << std::setprecision(decimalPlaces);
    std::cout << "double: " << this->_double << std::endl;
};