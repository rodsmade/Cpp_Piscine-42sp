#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
};

Animal::Animal(const Animal &other) {
    this->_type = other._type;
    std::cout << "Animal copy constructor called" << std::endl;
};

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
};

Animal &Animal::operator=(const Animal &other) {
    this->_type = other._type;
    return (*this);
};
