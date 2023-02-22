#include "Cat.hpp"

Cat::Cat() {
    this->_type = "Cat";
};

Cat::Cat(const Cat &other) : Animal(other) {
    *this = other;
};

Cat::~Cat() {};

Cat &Cat::operator=(const Cat &other){
    this->_type = other._type;
    return (*this);
};

void    Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
};
