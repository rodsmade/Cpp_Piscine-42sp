#include "Form.hpp"

// CONSTRUCTORS AND DESTRUCTOR
Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false) {
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw Form::GradeTooLowException();
    }
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw Form::GradeTooHighException();
    }
    this->_gradeRequiredToSign = gradeToSign;
    this->_gradeRequiredToExecute = gradeToExecute;
};

Form::Form(const Form &other) : _name(other._name), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute){};

Form::~Form(){};

// OPERATOR OVERLOADS
// ASSIGNMENT OPERATOR
Form &Form::operator=(const Form &other) {
    if (this != &other) {  // check for self-assignment
        _name = other._name;
        _gradeRequiredToSign = other._gradeRequiredToSign;
        _gradeRequiredToExecute = other._gradeRequiredToExecute;
    }
    return *this;
};

// INSERTION OPERATOR
std::ostream &operator<<(std::ostream &o, Form const &form) {
    o << "Form " << form.getName() << " is";
    if (!form.getIsSigned())
        o << " not";
    o << " signed and needs grade " << form.getGradeRequiredToSign() << " to be signed and grade " << form.getGradeRequiredToExecute() << " to be executed.";
    return (o);
};

// GETTERS
std::string Form::getName(void) const { return this->_name; };

bool Form::getIsSigned(void) const { return this->_isSigned; };

int Form::getGradeRequiredToSign(void) const { return this->_gradeRequiredToSign; };

int Form::getGradeRequiredToExecute(void) const { return this->_gradeRequiredToExecute; };

// MEMBER FUNCTIONS
void Form::beSigned(Bureaucrat bureaucrat) {
    if (bureaucrat.getGrade() > this->getGradeRequiredToSign())
        throw Form::GradeTooLowException();
    this->_isSigned = true;
};
