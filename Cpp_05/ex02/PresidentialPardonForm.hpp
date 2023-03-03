#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   private:
    std::string _target;

   public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const &other);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

    void execute(Bureaucrat &bureaucrat);
};
