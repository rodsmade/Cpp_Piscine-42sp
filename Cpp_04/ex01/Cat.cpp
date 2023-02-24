#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal(), _brain(new Brain) {
    std::cout << "Cat constructor called" << std::endl;
};

// TODO: make sure the copies are deep, not shallow!
// A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test that your copies are deep copies!
Cat::Cat(const Cat &other) : _brain(new Brain(*other._brain)) {
    std::cout << "Cat copy constructor called" << std::endl;
};

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
};

Cat &Cat::operator=(const Cat &other){
    this->_type = other._type;
    return (*this);
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
