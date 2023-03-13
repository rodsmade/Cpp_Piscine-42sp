#include "Span.hpp"

Span::Span(unsigned int N) : _maxStorage(N){};

Span::Span(const Span &other) : _maxStorage(other._maxStorage){};

Span::~Span(void){};

const Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxStorage = other._maxStorage;
    }
    return (*this);
};

const char *Span::StorageFullException::what() const throw() {
    return ("This storage is full to the brim!");
};

// member classes
unsigned int Span::getSize(void) {
    return _elements.size();
};

void Span::addNumber(int number) {
    if (this->getSize() >= _maxStorage) {
        throw StorageFullException();
    }
    _elements.push_back(number);
};
