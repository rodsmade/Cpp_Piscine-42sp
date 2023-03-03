#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), _target(target){};

ShrubberyCreationForm::~ShrubberyCreationForm(){};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target){};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
    if (this != &other) {
        this->_target = other._target;
    }
    return (*this);
};

void ShrubberyCreationForm::execute(Bureaucrat &bureaucrat) const {
    if (!this->getIsSigned()) {
        throw AForm::UnsignedFormException();
    }
    if (bureaucrat.getGrade() > this->getGradeRequiredToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::string fileName = this->_target + "_shrubbery";
    std::ofstream outfile(fileName.c_str());
    if (!outfile.is_open()) {
        throw AForm::FailedToOpenFileException();
    }

    // write some trees to the file
    outfile << "        /\\                                 /\\                         " << std::endl;
    outfile << "       //\\\\                               //\\\\                        " << std::endl;
    outfile << "      ///\\\\\\                             ///\\\\\\                       " << std::endl;
    outfile << "     ////\\\\\\\\                           ////\\\\\\\\                      " << std::endl;
    outfile << "    /////\\\\\\\\\\                         /////\\\\\\\\\\                     " << std::endl;
    outfile << "   //////\\\\\\\\\\\\                       //////\\\\\\\\\\\\                    " << std::endl;
    outfile << "  ///////\\\\\\\\\\\\\\                     ///////\\\\\\\\\\\\\\                   " << std::endl;
    outfile << " ////////\\\\\\\\\\\\\\\\          /\\       ////////\\\\\\\\\\\\\\\\          /\\      " << std::endl;
    outfile << "/////////\\\\\\\\\\\\\\\\\\        //\\\\     /////////\\\\\\\\\\\\\\\\\\        //\\\\     " << std::endl;
    outfile << "\\________________/       ///\\\\\\    \\________________/       ///\\\\\\    " << std::endl;
    outfile << "       ||||             ////\\\\\\\\           ||||            ////\\\\\\\\   " << std::endl;
    outfile << "       ||||      @         ||              ||||       @       ||      " << std::endl;
    outfile << "       ||||      |         ||          ;   ||||       |       ||      " << std::endl;

    // close the file
    outfile.close();
};
