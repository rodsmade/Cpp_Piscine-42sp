#include "Form.hpp"

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

Form &Form::operator=(const Form &other) {
    if (this != &other) {  // check for self-assignment
        _name = other._name;
        _gradeRequiredToSign = other._gradeRequiredToSign;
        _gradeRequiredToExecute = other._gradeRequiredToExecute;
    }
    return *this;
};

Form::~Form(){};
