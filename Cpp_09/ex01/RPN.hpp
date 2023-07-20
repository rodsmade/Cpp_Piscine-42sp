#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

#define VALID_CHARS "-+*/1234567890"

class RPN {
   private:
    std::stack<int> _stack;
    bool _isValidChar(int c);
    void _performOperation(char op);

   public:
    class ParsingErrorException : public std::exception {
       public:
        ParsingErrorException();
        ~ParsingErrorException() throw();
        virtual const char *what() const throw();
    };
    class CalculationErrorException : public std::exception {
       public:
        CalculationErrorException();
        ~CalculationErrorException() throw();
        virtual const char *what() const throw();
    };

    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

    void reckon(char *str);
    int getResult(void);
};

#endif
