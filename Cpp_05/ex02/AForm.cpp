#include "AForm.hpp"

std::string AForm::getName(void) const { return this->_name; };

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
};
