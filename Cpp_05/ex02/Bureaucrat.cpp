#include "Bureaucrat.hpp"

int Bureaucrat::getGrade() const { return this->_grade; };

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (AForm::GradeTooLowException &ex) {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << ex.what() << std::endl;
    }
}