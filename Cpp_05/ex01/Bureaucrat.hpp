#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class Bureaucrat {
   private:
    std::string _name;
    int _grade;

   public:
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

    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &other);
    Bureaucrat &operator++();    // Prefix increment operator.
    Bureaucrat operator++(int);  // Postfix increment operator.
    Bureaucrat &operator--();    // Prefix decrement operator.
    Bureaucrat operator--(int);  // Postfix decrement operator.

    std::string getName() const;
    int getGrade() const;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rightHandSide);
