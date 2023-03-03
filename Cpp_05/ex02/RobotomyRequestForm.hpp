#pragma once

#include <cstdlib>

#include "AForm.hpp"

class RobotomyRequestForm : AForm {
   private:
    std::string _target;

   public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

    void execute(Bureaucrat &bureaucrat) const;
};
