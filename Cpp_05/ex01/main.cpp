#include "Bureaucrat.hpp"

int main() {
    std::cout << "Testing wrong construction scenarios:" << std::endl;
    try {
        Bureaucrat joanne("Joanne", 0);
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
    }
    try {
        Bureaucrat joanne("Joanne", 10000);
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Testing << operator:" << std::endl;
    try {
        Bureaucrat joanne("Joanne", 42);
        std::cout << "This is " << joanne << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Testing increment and decrement operations:" << std::endl;
    try {
        Bureaucrat joanne("Joanne", 42);
        std::cout << "This is " << joanne << std::endl;
        std::cout << "This is " << ++joanne << std::endl;
        std::cout << "This is " << ++joanne << std::endl;
        std::cout << "This is " << ++joanne << std::endl;
        std::cout << "This is " << ++joanne << std::endl;
        std::cout << "This is " << ++joanne << std::endl;
        Bureaucrat jolene("Jolene", 42);
        std::cout << "This is " << jolene << std::endl;
        std::cout << "This is " << --jolene << std::endl;
        std::cout << "This is " << --jolene << std::endl;
        std::cout << "This is " << --jolene << std::endl;
        std::cout << "This is " << --jolene << std::endl;
        std::cout << "This is " << --jolene << std::endl;
        Bureaucrat jennifer("Jennifer", 5);
        std::cout << "This is " << jennifer << std::endl;
        std::cout << "This is " << ++jennifer << std::endl;
        std::cout << "This is " << ++jennifer << std::endl;
        std::cout << "This is " << ++jennifer << std::endl;
        std::cout << "This is " << ++jennifer << std::endl;
        std::cout << "This is " << ++jennifer << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
    }
    try {
        Bureaucrat julia("Julia", 146);
        std::cout << "This is " << julia << std::endl;
        std::cout << "This is " << --julia << std::endl;
        std::cout << "This is " << --julia << std::endl;
        std::cout << "This is " << --julia << std::endl;
        std::cout << "This is " << --julia << std::endl;
        std::cout << "This is " << --julia << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
    }


}