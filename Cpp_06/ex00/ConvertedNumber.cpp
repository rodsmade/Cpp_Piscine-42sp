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
    // if (originalType == "float") {
    //     // pode ser nanf !
    //     this->_float = std::atof(arg.c_str());
    //     this->_double = static_cast<double>(this->_float);
    //     this->_char = static_cast<char>(this->_float);
    // }
    // if (originalType == "double") {
    //     // pode ser nan !
    //     this->_double = std::strtod(arg.c_str(), NULL);
    //     this->_float = static_cast<float>(this->_double);
    //     this->_char = static_cast<char>(this->_double);
    // }
};

// ConvertedNumber::ConvertedNumber(const ConvertedNumber &other){};

ConvertedNumber::~ConvertedNumber(){};

// ConvertedNumber &ConvertedNumber::operator=(const ConvertedNumber &other){};

void convertToFloat();
void convertToDouble();
void convertToChar();

bool ConvertedNumber::charAndIntConversionIsImpossible() {
    return (isnan(this->_double) || isnanf(this->_float) || isinf(this->_double) || isinff(this->_float));
};

void ConvertedNumber::printNumberInAllFormats(void) {
    // float f = std::atof(argv[1]);
    // // Set the number of decimal places to 1 and enable fixed-point notation
    // std::cout << std::fixed << std::setprecision(1);
    // // Print the float with a decimal point and trailing zeros
    // std::cout << "The float value is: " << f << "f" << std::endl;
    // CHAR
    std::cout << "char: ";
    if (this->charAndIntConversionIsImpossible()) {
        std::cout << "impossible";
    }
    if (!std::isprint(this->_char)) {
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
    std::cout << "float: "
              << "TBA" << std::endl;
    // DOUBLE
    std::cout << "double: "
              << "TBA" << std::endl;
};