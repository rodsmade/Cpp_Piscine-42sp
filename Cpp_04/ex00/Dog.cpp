#include "Dog.hpp"

Dog::Dog() {
    this->_type = "Dog";
};

Dog::Dog(const Dog &other){
    this->_type = other._type;
};

Dog::~Dog() {};

Dog &Dog::operator=(const Dog &other) {
    this->_type = other._type;
    return (*this);
};

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
};
