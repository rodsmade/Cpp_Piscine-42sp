#include "Brain.hpp"

Brain::Brain() : _type("Brain") {
    std::cout << this->_type << " constructor called" << std::endl;
};

Brain::Brain(const Brain &other){
    this->_type = other._type;
    std::cout << this->_type << " copy constructor called" << std::endl;
};

Brain::~Brain() {
    std::cout << this->_type << " destructor called" << std::endl;
};

std::string Brain::getType(void) {
    return (this->_type);
}

Brain &Brain::operator=(const Brain &other) {
    this->_type = other._type;
    return (*this);
};
