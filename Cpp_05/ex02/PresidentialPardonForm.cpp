#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), _target(target) {};

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), _target(other._target) {};

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
    if (this != &other) {
        this->_target = other._target;
    }
    return (*this);
};
    
void PresidentialPardonForm::execute(Bureaucrat &bureaucrat) {
    if (!this->getIsSigned()) {
        throw AForm::UnsignedFormException();
    }
    if (bureaucrat.getGrade() > this->getGradeRequiredToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
};
