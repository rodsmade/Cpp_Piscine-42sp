#pragma once

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
// forward declaration of Bureaucrat class
class Bureaucrat;

class Form {
   private:
    const std::string _name;
    bool _isSigned;
    const int _gradeRequiredToSign;
    const int _gradeRequiredToExecute;

   public:
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    std::string getName(void) const;
    bool getIsSigned(void) const;
    int getGradeRequiredToSign(void) const;
    int getGradeRequiredToExecute(void) const;

    void beSigned(Bureaucrat bureaucrat);

    class GradeTooHighException : public std::exception {
       public:
        GradeTooHighException(void) {}
        virtual const char* what() const throw() {
            return "Grade is too low. Provide value greater than or equal to 150";
        }
    };

    class GradeTooLowException : public std::exception {
       public:
        GradeTooLowException(void) {}
        virtual const char* what() const throw() {
            return "Grade is too high. Provide value lesser than or equal to 1";
        }
    };
};

std::ostream &operator<<(std::ostream &o, Form const &form);
