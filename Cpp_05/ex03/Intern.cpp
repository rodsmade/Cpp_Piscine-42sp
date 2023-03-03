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

AForm *Intern::makeForm(std::string formName, std::string target) {
    if (formName == "Presidential Pardon") {
        std::cout << "Intern creates " << formName << " form." << std::endl;
        return new PresidentialPardonForm(target);
    } else if (formName == "Robotomy Request") {
        std::cout << "Intern creates " << formName << " form." << std::endl;
        return new RobotomyRequestForm(target);
    } else if (formName == "Shrubbery Creation") {
        std::cout << "Intern creates " << formName << " form." << std::endl;
        return new ShrubberyCreationForm(target);
    }
    std::cout << "NO FORM CREATED BECAUSE THIS TYPE OF FORM DOES NOT EXIST HELLO" << std::endl;
    return NULL;
};
