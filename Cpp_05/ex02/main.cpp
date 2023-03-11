#include "AForm.hpp"
#include "Bureaucrat.hpp"
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

    return 0;
}
