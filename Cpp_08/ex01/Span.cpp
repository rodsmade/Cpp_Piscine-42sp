#include "Span.hpp"

Span::Span(unsigned int N) : _maxStorage(N){};

Span::Span(const Span &other) : _maxStorage(other._maxStorage) {};

Span::~Span(void) {};

const Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxStorage = other._maxStorage;
    }
    return (*this);
};
