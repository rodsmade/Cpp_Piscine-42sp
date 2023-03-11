#pragma once

#include <cstdlib> // rand, srand
#include <ctime> // time

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   private:
    std::string _target;

   public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

    void execute(Bureaucrat &bureaucrat) const;
};
