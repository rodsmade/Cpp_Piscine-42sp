#pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat {
   private:
    std::string _name;
    int _grade;

   public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high.";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low.";
        }
    };

    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &other);

    std::string getName() const;
    int getGrade() const;
};
