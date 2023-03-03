#pragma once

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    public:
    Intern();
    Intern(const Intern &other);
    ~Intern();
    Intern &operator=(const Intern &other);

    AForm *makeForm(std::string formName, std::string target);
};
