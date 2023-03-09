#include <cstdlib>
#include <exception>
#include <iostream>
#include <limits.h>
#include <cmath>
#include <string>

class ConvertedNumber {
   private:
    std::string _originalType;
    char _char;
    int _int;
    float _float;
    double _double;

   public:
    ConvertedNumber(std::string originalType, std::string arg);
    // ConvertedNumber(const ConvertedNumber &other);
    ~ConvertedNumber();
    // ConvertedNumber &operator=(const ConvertedNumber &other);

    // static float convertToFloat();
    // static double convertToDouble();
    // static char convertToChar();
    // std::string floatToString();
    // std::string doubleToString();

    bool charAndIntConversionIsImpossible(void);
    void printNumberInAllFormats(void);

    class IntOutOfBoundsException : public std::exception {
       public:
        virtual const char *what() const throw() {
            return "Number is greater than INT_MAX or smaller than INT_MIN.";
        }
    };
};
