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

void Span::addNumber(int number) {
    if (getSize() >= _maxStorage) {
        throw StorageFullException();
    }
    _elements.push_back(number);
};

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    while ( begin != end ) {
        if (getSize() >= _maxStorage) {
            throw StorageFullException();
        }
        _elements.push_back(*begin);
        begin++;
    }
};

int Span::shortestSpan(void) {
    if (getSize() <= 1) {
        throw SpanCantBeFoundException();
    }
    std::vector<int> temp = _elements;

    std::vector<int> diffs(temp.size() - 1);

    // calculate differences (absolute value) between adjacent elements
    for (unsigned long int i = 0; i < diffs.size(); i++)
        diffs[i] = abs(temp[i + 1] - temp[i]);

    // find iterator to minimum element:
    std::vector<int>::iterator minIt = std::min_element(diffs.begin(), diffs.end());
    int minSpan = *minIt;

    return (minSpan);
};

int Span::longestSpan(void) {
    if (getSize() <= 1) {
        throw SpanCantBeFoundException();
    }
    std::vector<int> temp = _elements;

    std::vector<int> diffs(temp.size() - 1);

    // calculate differences (absolute value) between adjacent elements
    for (unsigned long int i = 0; i < diffs.size(); i++)
        diffs[i] = abs(temp[i + 1] - temp[i]);

    // find iterator to maximum element
    std::vector<int>::iterator maxIt = std::max_element(diffs.begin(), diffs.end());
    int maxSpan = *maxIt;

    return (maxSpan);
};
