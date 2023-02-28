#include "Brain.hpp"

Brain::Brain() : _type("Brain") {
    std::cout << "Brain constructor called" << std::endl;
};

Brain::Brain(const Brain &other) {
    this->_type = other._type;
    std::cout << "Brain copy constructor called" << std::endl;
};

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
};

std::string Brain::getType(void) {
    return (this->_type);
}

Brain &Brain::operator=(const Brain &other) {
    this->_type = other._type;
    return (*this);
};

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < 100) {
        _ideas[index] = idea;
    }
};

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return _ideas[index];
    } else {
        return "";
    }
}