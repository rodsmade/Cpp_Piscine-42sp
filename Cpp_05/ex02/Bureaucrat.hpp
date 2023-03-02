#pragma once

#include <exception>
#include <iostream>

#include "AForm.hpp"
// forward declaration of AForm class
class AForm;

class Bureaucrat {
   private:
    int _grade;
    std::string _name;

   public:
    // Constructors/Destructor
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();

    // Accessors
    int getGrade() const;
    std::string getName() const;

    // Operator Overloads
    // -- Assignment operator
    Bureaucrat &operator=(const Bureaucrat &other);

    // -- Increment/Decrement operators
    Bureaucrat &operator++();    // Prefix increment operator.
    Bureaucrat operator++(int);  // Postfix increment operator.
    Bureaucrat &operator--();    // Prefix decrement operator.
    Bureaucrat operator--(int);  // Postfix decrement operator.

    // Member functions
    void signForm(AForm &form);

    // Exceptions
    class GradeTooHighException : public std::exception {
       public:
        virtual const char *what() const throw() {
            return "Grade is too high.";
        }
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char *what() const throw() {
            return "Grade is too low.";
        }
    };
};

// Output stream operator overload
