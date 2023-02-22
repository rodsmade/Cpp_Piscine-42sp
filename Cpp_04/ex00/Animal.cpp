#include "Animal.hpp"

Animal::Animal() {
    this->_type = "Animal";
};

Animal::Animal(const Animal &other){
    this->_type = other._type;
};

Animal::~Animal() {};

Animal &Animal::operator=(const Animal &other) {
    this->_type = other._type;
    return (*this);
};

std::string Animal::getType(void) const {
    return this->_type;
};

void Animal::makeSound() const {
    std::cout << "* makes weird noises *" << std::endl;
};
