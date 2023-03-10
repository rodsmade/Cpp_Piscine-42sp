#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat(){};

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade){};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->_grade = other.getGrade();
    }
    return (*this);
};

Bureaucrat &Bureaucrat::operator++() {
    if (this->_grade == 1) {
        throw GradeTooHighException();
    };
    this->_grade = this->_grade - 1;
    return *(this);
};

Bureaucrat Bureaucrat::operator++(int) {
    if (this->_grade == 1) {
        throw GradeTooHighException();
    };
    Bureaucrat temp(*this);
    this->_grade = this->_grade - 1;
    return (temp);
};

Bureaucrat &Bureaucrat::operator--() {
    if (this->_grade == 150) {
        throw GradeTooLowException();
    };
    this->_grade = this->_grade + 1;
    return *(this);
};

Bureaucrat Bureaucrat::operator--(int) {
    if (this->_grade == 150) {
        throw GradeTooLowException();
    };
    Bureaucrat temp(*this);
    this->_grade = this->_grade + 1;
    return (temp);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rightHandSide) {
    std::ostringstream oss;
    oss << rightHandSide.getGrade();
    std::string grade = oss.str();
    o << rightHandSide.getName() << ", bureaucrat grade " << grade << ".";
    return (o);
};

std::string Bureaucrat::getName(void) const { return this->_name; };

int Bureaucrat::getGrade() const { return this->_grade; };
