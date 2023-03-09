#include <cstdlib>
#include <iostream>
#include <string>

class ConvertedNumber {
   private:
    std::string _originalType;
    float _toFloat;
    double _toDouble;
    char _toChar;

   public:
    ConvertedNumber(std::string originalType, std::string arg);
    // ConvertedNumber(const ConvertedNumber &other);
    ~ConvertedNumber();
    // ConvertedNumber &operator=(const ConvertedNumber &other);

    static float convertToFloat();
    static double convertToDouble();
    static char convertToChar();
    std::string floatToString();
    std::string doubleToString();

	void printNumberInAllFormats(void);
};
