#pragma once

#include <iostream>

#include "AForm.hpp"
// forward declaration of AForm class
class AForm;

class Bureaucrat {
   private:
    int _grade;
    std::string _name;

   public:
    int getGrade() const;
    void signForm(AForm &form);
};
