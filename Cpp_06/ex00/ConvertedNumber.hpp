#include <iostream>

class ConvertedNumber {
   private:
    std::string _originalType;
    float _toFloat;
    double _toDouble;
    char _toChar;

   public:
    ConvertedNumber(std::string originalType, std::string arg);
    ConvertedNumber(const ConvertedNumber &other);
    ~ConvertedNumber();
    ConvertedNumber &operator=(const ConvertedNumber &other);

    void convertToFloat();
    void convertToDouble();
    void convertToChar();
    std::string floatToString();
    std::string doubleToString();
};
