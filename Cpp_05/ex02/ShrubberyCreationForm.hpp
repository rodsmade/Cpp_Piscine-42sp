#pragma once

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : AForm {
   private:
    std::string _target;

   public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &other);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

    void execute(Bureaucrat &bureaucrat);
};
