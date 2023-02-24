#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->_type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
};

// TODO: make sure the copies are deep, not shallow!
// A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test that your copies are deep copies!
Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type = other._type;
};

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
};

Dog &Dog::operator=(const Dog &other) {
    this->_type = other._type;
    return (*this);
};

void Dog::setType(std::string &type) {
    this->_type = type;
}

void Dog::setIdea(int index, const std::string& idea) {
    _brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return _brain->getIdea(index);
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
};
