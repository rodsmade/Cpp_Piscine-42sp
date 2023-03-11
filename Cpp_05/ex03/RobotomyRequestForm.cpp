#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target){};

RobotomyRequestForm::~RobotomyRequestForm(){};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), _target(other._target){};

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    if (this != &other) {
        this->_target = other._target;
    }
    return (*this);
};

void RobotomyRequestForm::execute(Bureaucrat &bureaucrat) const {
    if (!this->getIsSigned()) {
        throw AForm::UnsignedFormException();
    }
    if (bureaucrat.getGrade() > this->getGradeRequiredToExecute()) {
        throw AForm::UnauthorisedException();
    }
    std::cout << "* some drilling noises *" << std::endl;

    std::srand(std::time(0));
    int randNb = std::rand();

    if (randNb % 2) {
        std::cout << this->_target << " has been robotomized successfully! 🤖" << std::endl;
    } else {
        std::cout << "Oh dear! The robotomy failed. 🫠" << std::endl;
    }
};
