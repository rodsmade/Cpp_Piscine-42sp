#include "Bureaucrat.hpp"

// CONSTRUCTORS AND DESTRUCTOR
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
    this->_name = other._name;
    this->_grade = other._grade;
}

Bureaucrat::~Bureaucrat(){};

// OPERATOR OVERLOADS
// ASSIGNMENT OPERATOR
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->_name = other.getName();
        this->_grade = other.getGrade();
    }
    return (*this);
};

// PRE-INCREMENT
Bureaucrat &Bureaucrat::operator++() {
    if (this->_grade == 1) {
        throw GradeTooHighException();
    };
    this->_grade = this->_grade - 1;
    return *(this);
};

// POST-INCREMENT
Bureaucrat Bureaucrat::operator++(int) {
    if (this->_grade == 1) {
        throw GradeTooHighException();
    };
    Bureaucrat temp(*this);
    this->_grade = this->_grade - 1;
    return (temp);
};

// PRE-DECREMENT
Bureaucrat &Bureaucrat::operator--() {
    if (this->_grade == 150) {
        throw GradeTooLowException();
    };
    this->_grade = this->_grade + 1;
    return *(this);
};

// POST-DECREMENT
Bureaucrat Bureaucrat::operator--(int) {
    if (this->_grade == 150) {
        throw GradeTooLowException();
    };
    Bureaucrat temp(*this);
    this->_grade = this->_grade + 1;
    return (temp);
};

// INSERTION OPERATOR
std::ostream &operator<<(std::ostream &o, Bureaucrat const &rightHandSide) {
    std::ostringstream oss;
    oss << rightHandSide.getGrade();
    std::string grade = oss.str();
    o << rightHandSide.getName() << ", bureaucrat grade " << grade << ".";
    return (o);
};

// GETTERS
std::string Bureaucrat::getName(void) const { return this->_name; };

int Bureaucrat::getGrade() const { return this->_grade; };

// MEMBER FUNCTIONS
void Bureaucrat::signForm(Form form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (Form::GradeTooLowException &ex) {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << ex.what() << std::endl;
    }
};