#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal() {
    this->_type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
    this->_brain = new Brain();
};

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
};

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
};

Cat &Cat::operator=(const Cat &other){
    this->_type = other._type;
    return (*this);
};

void Cat::setIdea(int index, const std::string& idea) {
    _brain->setIdea(index, idea);
}

// get an idea from the cat's brain at a specific index
std::string Cat::getIdea(int index) const {
    return _brain->getIdea(index);
}

void    Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
};
