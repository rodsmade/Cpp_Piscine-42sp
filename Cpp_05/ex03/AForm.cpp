#include "AForm.hpp"

// CONSTRUCTORS AND DESTRUCTOR
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _gradeRequiredToExecute(gradeToExecute), _gradeRequiredToSign(gradeToSign) {
    this->_name = name;
    this->_isSigned = false;
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw AForm::GradeTooLowException();
    }
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw AForm::GradeTooHighException();
    }
};

AForm::AForm(const AForm &other) : _gradeRequiredToExecute(other._gradeRequiredToExecute), _gradeRequiredToSign(other._gradeRequiredToSign), _isSigned(other._isSigned), _name(other._name){};

AForm::~AForm(){};

// OPERATOR OVERLOADS
// ASSIGNMENT OPERATOR
AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {  // check for self-assignment
        _name = other._name;
        _isSigned = other._isSigned;
    }
    return *this;
};

// INSERTION OPERATOR
std::ostream &operator<<(std::ostream &o, AForm const &form) {
    o << form.getName() << " form is";
    if (!form.getIsSigned())
        o << " not";
    o << " signed and needs grade " << form.getGradeRequiredToSign() << " to be signed and grade " << form.getGradeRequiredToExecute() << " to be executed.";
    return (o);
};

// GETTERS
std::string AForm::getName(void) const { return this->_name; };

bool AForm::getIsSigned(void) const { return this->_isSigned; };

int AForm::getGradeRequiredToSign(void) const { return this->_gradeRequiredToSign; };

int AForm::getGradeRequiredToExecute(void) const { return this->_gradeRequiredToExecute; };

// MEMBER FUNCTIONS
void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
        throw AForm::UnauthorisedException();
    this->_isSigned = true;
};
