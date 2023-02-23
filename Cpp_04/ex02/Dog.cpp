#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->_type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
};

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type = other._type;
};

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
};

Dog &Dog::operator=(const Dog &other) {
    this->_type = other._type;
    return (*this);
};

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
};
