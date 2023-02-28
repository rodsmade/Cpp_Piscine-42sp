#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain) {
    std::cout << "Dog constructor called" << std::endl;
};

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain)) {
    std::cout << "Dog copy constructor called" << std::endl;
};

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
};

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {  // check for self-assignment
        _type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain);  // deep copy
    }
    return *this;
};

void Dog::setType(const std::string &type) {
    this->_type = type;
}

void Dog::setIdea(int index, const std::string &idea) {
    _brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return _brain->getIdea(index);
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
};
