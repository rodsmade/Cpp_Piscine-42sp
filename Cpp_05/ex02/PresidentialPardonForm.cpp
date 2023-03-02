#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target) {};

PresidentialPardonForm::~PresidentialPardonForm() {};

void PresidentialPardonForm::beExecuted(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > 0) {
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::cout;
    }
};