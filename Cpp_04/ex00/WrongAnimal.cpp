#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->_type = "WrongAnimal";
};

WrongAnimal::WrongAnimal(const WrongAnimal &other){
    this->_type = other._type;
};

WrongAnimal::~WrongAnimal() {};

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    this->_type = other._type;
    return (*this);
};

std::string WrongAnimal::getType(void) const {
    return this->_type;
};

void WrongAnimal::makeSound() const {
    std::cout << "* makes weird noises *" << std::endl;
};
