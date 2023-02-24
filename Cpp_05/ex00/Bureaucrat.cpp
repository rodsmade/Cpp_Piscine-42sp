#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
    this->_name = other._name;
    this->_grade = other._grade;
}

std::string Bureaucrat::getName(void) const { return this->_name; };

int Bureaucrat::getGrade() const { return this->_grade; };
