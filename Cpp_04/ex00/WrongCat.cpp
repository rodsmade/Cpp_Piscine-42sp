#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    this->_type = "WrongCat";
};

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    *this = other;
};

WrongCat::~WrongCat() {};

std::string WrongCat::getType(void) const {
    return this->_type;
};

WrongCat &WrongCat::operator=(const WrongCat &other){
    this->_type = other._type;
    return (*this);
};

void    WrongCat::makeSound() const {
    std::cout << "Meow!" << std::endl;
};
