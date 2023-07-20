#include "RPN.hpp"

RPN::ParsingErrorException::ParsingErrorException() {};

RPN::ParsingErrorException::~ParsingErrorException() throw(){};

const char *RPN::ParsingErrorException::what() const throw() {
    return "Error";
}

RPN::CalculationErrorException::CalculationErrorException() {};

RPN::CalculationErrorException::~CalculationErrorException() throw(){};

const char *RPN::CalculationErrorException::what() const throw() {
    return "Error";
}

RPN::RPN(){};

RPN::~RPN(){};

RPN::RPN(const RPN &other) : _stack(other._stack){};

RPN &RPN::operator=(const RPN &other) {
    if (_stack != other._stack) {
        _stack = other._stack;
    }
    return (*this);
};

bool RPN::_isValidChar(int c) {
    return (isdigit(c) || c == '-' || c == '+' || c == '*' || c == '/');
};

void RPN::_performOperation(char op) {
    if (_stack.size() < 2)
        throw CalculationErrorException();

    int lhs, rhs;
    long result;

    rhs = _stack.top();
    _stack.pop();
    lhs = _stack.top();
    _stack.pop();

    switch (op) {
        case '*':
            result = lhs * rhs;
            break;
        case '/':
            if (rhs == 0)
                throw CalculationErrorException();
            result = lhs / rhs;
            break;
        case '+':
            result = lhs + rhs;
            break;
        default:
            result = lhs - rhs;
            break;
    }

    if (result > INT_MAX || result < INT_MIN)
        throw CalculationErrorException();

    _stack.push(static_cast<int>(result));
};

void RPN::reckon(char *str) {
    std::string validChars(VALID_CHARS);

    int i = -1;
    while (str[++i]) {
        if (isspace(str[i]))
            continue;
        if (!_isValidChar(str[i]))
            throw ParsingErrorException();
        if (str[i + 1] && !isspace(str[i + 1]))
            throw ParsingErrorException();
        if (isdigit(str[i]))
            _stack.push(str[i] - 48);
        else
            _performOperation(str[i]);
    }
    if (_stack.size() != 1)
        throw CalculationErrorException();
};

int RPN::getResult(void) {
    if (_stack.size() == 0)
        throw CalculationErrorException();
    return _stack.top();
};