#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat soninha("Soninha", 2);
    Bureaucrat flaviano("Flaviano", 120);

    PresidentialPardonForm pardon("Rods");
    RobotomyRequestForm robForm("Moulinette");
    ShrubberyCreationForm shrubs("Terraço");

    flaviano.signForm(pardon);
    soninha.executeForm(pardon);
    soninha.signForm(pardon);
    soninha.executeForm(pardon);
    soninha.signForm(robForm);
    soninha.executeForm(robForm);
    soninha.signForm(shrubs);
    soninha.executeForm(shrubs);

    Intern jmilson;
    jmilson.makeForm("Presidential Pardon", "Rods");
    jmilson.makeForm("Robotomy Request", "Moulinette");
    jmilson.makeForm("Shrubbery Creation", "groovy_grove");
    jmilson.makeForm("Eject from Spaceship", "The Impostor");

    return 0;
}
