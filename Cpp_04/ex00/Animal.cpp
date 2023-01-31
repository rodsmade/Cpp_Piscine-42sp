#include "Animal.hpp"

Animal::Animal() {
    this->_type = "undefined";
};

Animal::Animal(const std::string type) : _type(type) {};

Animal::Animal(const Animal &other){
    *this = other;
};

Animal::~Animal() {};

void Animal::makeSound() {
    std::cout << "* makes weird noises *" << std::endl;
};
