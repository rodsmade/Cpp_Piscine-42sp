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
    ShrubberyCreationForm shrubs("groovy_grove");

    flaviano.signForm(pardon);
    soninha.executeForm(pardon);
    soninha.signForm(pardon);
    soninha.executeForm(pardon);
    soninha.signForm(robForm);
    soninha.executeForm(robForm);
    soninha.signForm(shrubs);
    soninha.executeForm(shrubs);

    Intern jmilson;

    AForm *form1 = jmilson.makeForm("Presidential Pardon", "Rods");
    AForm *form2 = jmilson.makeForm("Robotomy Request", "Moulinette");
    AForm *form3 = jmilson.makeForm("Shrubbery Creation", "groovy_grove");

    delete form1;
    delete form2;
    delete form3;

    jmilson.makeForm("Eject from Spaceship", "The Impostor");

    return 0;
}
