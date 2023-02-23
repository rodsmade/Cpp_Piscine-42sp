#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->_type = "Dog";
    std::cout << this->_type << " constructor called" << std::endl;
};

Dog::Dog(const Dog &other) : Animal(other) {
    this->_type = other._type;
    std::cout << this->_type << " copy constructor called" << std::endl;
};

Dog::~Dog() {
    std::cout << this->_type << " destructor called" << std::endl;
};

Dog &Dog::operator=(const Dog &other) {
    this->_type = other._type;
    return (*this);
};

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
};
