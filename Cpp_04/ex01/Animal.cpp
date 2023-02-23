#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << this->_type << " constructor called" << std::endl;
};

Animal::Animal(const Animal &other){
    this->_type = other._type;
    std::cout << this->_type << " copy constructor called" << std::endl;
};

Animal::~Animal() {
    std::cout << this->_type << " destructor called" << std::endl;
};

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
