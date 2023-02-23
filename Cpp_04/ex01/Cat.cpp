#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->_type = "Cat";
    std::cout << this->_type << " constructor called" << std::endl;
};

Cat::Cat(const Cat &other) : Animal(other) {
    *this = other;
    std::cout << this->_type << " copy constructor called" << std::endl;
};

Cat::~Cat() {
    std::cout << this->_type << " destructor called" << std::endl;
};

Cat &Cat::operator=(const Cat &other){
    this->_type = other._type;
    return (*this);
};

void    Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
};
