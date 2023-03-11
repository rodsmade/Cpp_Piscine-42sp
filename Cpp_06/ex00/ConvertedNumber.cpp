#include "ConvertedNumber.hpp"

ConvertedNumber::ConvertedNumber(std::string originalType, std::string arg) : _originalType(originalType) {
    if (originalType == "char") {
        _char = arg[0];

        _int = static_cast<int>(_char);
        _double = static_cast<double>(_char);
        _float = static_cast<float>(_char);
    }
    if (originalType == "int") {
        _int = std::atoi(arg.c_str());

        _char = static_cast<char>(_int);
        _float = static_cast<float>(_int);
        _double = static_cast<double>(_int);
    }
    if (originalType == "float") {
        _float = std::atof(arg.c_str());

        _int = static_cast<int>(_float);
        _double = static_cast<double>(_float);
        _char = static_cast<char>(_float);
    }
    if (originalType == "double") {
        _double = std::strtod(arg.c_str(), NULL);

        _int = static_cast<int>(_double);
        _float = static_cast<float>(_double);
        _char = static_cast<char>(_double);
    }
};

ConvertedNumber::ConvertedNumber(const ConvertedNumber &other) : _char(other._char), _int(other._int), _float(other._float), _double(other._double){};

ConvertedNumber::~ConvertedNumber(){};

ConvertedNumber &ConvertedNumber::operator=(const ConvertedNumber &other) {
    if (this != &other) {
        _char = other._char;
        _int = other._int;
        _float = other._float;
        _double = other._double;
    }
    return (*this);
};

bool ConvertedNumber::charAndIntConversionIsImpossible() {
    return (isnan(_double) || isinf(_double) || _double > double(INT_MAX) || _double < double(INT_MIN) || isnanf(_float) || isinff(_float) || _float > float(INT_MAX) || _float < float(INT_MIN));
};

void ConvertedNumber::printNumberInAllFormats(void) {
    // CHAR
    std::cout << "char: ";
    if (charAndIntConversionIsImpossible()) {
        std::cout << "impossible";
    } else if (!std::isprint(_char)) {
        std::cout << "Non displayable";
    } else {
        std::cout << "'" << _char << "'";
    }
    std::cout << std::endl;

    // INT
    std::cout << "int: ";
    if (charAndIntConversionIsImpossible()) {
        std::cout << "impossible";
    } else {
        std::cout << _int;
    }
    std::cout << std::endl;

    // FLOAT
    // Set the number of decimal places to 1 and enable fixed-point notation
    int decimalPlaces = 0;
    float tempf = _float;
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
    std::cout << "float: " << _float << "f" << std::endl;
    // DOUBLE
    decimalPlaces = 0;
    double temp = _double;
    while (std::abs(temp - std::floor(temp)) > 0.0001) {
        temp *= 10.0;
        decimalPlaces++;
    }
    if (decimalPlaces == 0) {
        decimalPlaces++;
    }
    std::cout << std::fixed << std::setprecision(decimalPlaces);
    std::cout << "double: " << _double << std::endl;
};