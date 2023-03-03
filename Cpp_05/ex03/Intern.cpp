#include "Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern &other) {
    (void) other;
};

Intern::~Intern() {};

Intern &Intern::operator=(const Intern &other) {
    (void) other;
    return *this;
};

AForm *createPresidentialPardonForm(std::string name, std::string target) {
    if (name == "Presidential Pardon") {
        std::cout << "Intern creates " << name << " Form." << std::endl;
        return new PresidentialPardonForm(target);
    }
    else
        return NULL;
};

AForm *createRobotomyRequestForm(std::string name, std::string target) {
    if (name == "Robotomy Request") {
        std::cout << "Intern creates " << name << " Form." << std::endl;
        return new RobotomyRequestForm(target);
    }
    else
        return NULL;
};

AForm *createShrubberyCreationForm(std::string name, std::string target) {
    if (name == "Shrubbery Creation") {
        std::cout << "Intern creates " << name << " Form." << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else
        return NULL;
};


AForm *Intern::makeForm(std::string formName, std::string target) {
    AForm *(*creationFunctions[3])(std::string name, std::string target) = {createPresidentialPardonForm, createRobotomyRequestForm, createShrubberyCreationForm};

    AForm *result;
    for (int i = 0; i < 3; i++) {
        result = creationFunctions[i](formName, target);
        if (result)
            return result;
    }
    std::cout << "NO FORM CREATED BECAUSE THIS TYPE OF FORM DOES NOT EXIST HELLO" << std::endl;
    return NULL;
};
