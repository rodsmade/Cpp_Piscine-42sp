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
    ShrubberyCreationForm shrubs("Terraço");

    flaviano.signForm(pardon);
    soninha.executeForm(pardon);
    soninha.signForm(pardon);
    soninha.executeForm(pardon);

    return 0;
}
