#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Joanne", 10);
        std::cout << "Bureaucrat " << b1.getName() << " is grade " << b1.getGrade() << "." << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}