#pragma once

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
// forward declaration of Bureaucrat class
class Bureaucrat;

class AForm {
   private:
    const int _gradeRequiredToExecute;
    const int _gradeRequiredToSign;
    bool _isSigned;
    std::string _name;

   public:
    // Constructors/Destructor
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    ~AForm();

    // Accessors
    int getGradeRequiredToExecute(void) const;
    int getGradeRequiredToSign(void) const;
    bool getIsSigned(void) const;
    std::string getName(void) const;

    // Operator Overloads
    // -- Assignment operator
    AForm &operator=(const AForm &other);

    // Member functions
    void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat &bureaucrat) = 0;

    // Exceptions
    class GradeTooLowException : public std::exception {
       public:
        GradeTooLowException(void) {}
        std::string what() {
            return "Grade is too low. Provide value less than or equal to 150";
        }
    };

    class GradeTooHighException : public std::exception {
       public:
        GradeTooHighException(void) {}
        std::string what() {
            return "Grade is too high. Provide value greater than or equal to 1";
        }
    };

    class UnsignedFormException : public std::exception {
       public:
        UnsignedFormException(void) {}
        std::string what() {
            return "Form has not yet been signed!";
        }
    };

    class FailedToOpenFileException : public std::exception {
       public:
        FailedToOpenFileException(void) {}
        std::string what() {
            return "Error: failed to open file";
        }
    };
};

std::ostream &operator<<(std::ostream &o, AForm const &form);
