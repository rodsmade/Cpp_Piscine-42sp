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

const char *Span::SpanCantBeFoundException::what() const throw() {
    return ("No span can be found!");
};

// MEMBER FUNCTIONS
unsigned int Span::getSize(void) {
    return _elements.size();
};

int Span::shortestSpan(void) {
    if (getSize() <= 1) {
        throw SpanCantBeFoundException();
    }

    std::vector<int> temp = _elements;

    std::sort(temp.begin(), temp.end());  // sort vector

    std::vector<int> diffs(temp.size() - 1);

    for (long unsigned int i = 0; i < diffs.size(); i++) {
        diffs[i] = temp[i + 1] - temp[i];
    }

    std::sort(diffs.begin(), diffs.end());  // sort vector

    return (diffs[0]);
};

int Span::longestSpan(void) {
    return (0);
};

void Span::addNumber(int number) {
    if (this->getSize() >= _maxStorage) {
        throw StorageFullException();
    }
    _elements.push_back(number);
};
