#pragma once

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
// forward declaration of Bureaucrat class
class Bureaucrat;

class AForm {
   private:
    int _gradeRequiredToSign;
    bool _isSigned;
    std::string _name;

   public:
    std::string getName(void) const;

    void beSigned(Bureaucrat &bureaucrat);
    virtual void beExecuted(Bureaucrat &bureaucrat) = 0;

    class GradeTooLowException : public std::exception {
       public:
        GradeTooLowException(void) {}
        std::string what() {
            return "Grade is too high. Provide value lesser than or equal to 1";
        }
    };
};
