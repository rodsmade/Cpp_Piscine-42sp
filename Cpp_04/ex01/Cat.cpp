#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain) {
    std::cout << "Cat constructor called" << std::endl;
};

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain)) {
    std::cout << "Cat copy constructor called" << std::endl;
};

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
};

Cat &Cat::operator=(const Cat &other){
    if (this != &other) { // check for self-assignment
        _type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain); // deep copy
    }
    return *this;
};

void Cat::setType(std::string &type) {
    this->_type = type;
}

void Cat::setIdea(int index, const std::string& idea) {
    _brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return _brain->getIdea(index);
}

void    Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
};
