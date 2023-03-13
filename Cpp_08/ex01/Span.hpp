#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <vector>

class Span {
   public:
    Span(unsigned int N);
    Span(const Span &other);
    ~Span(void);
    const Span &operator=(const Span &other);

    // MEMBER FUNCTIONS
    unsigned int getSize(void);
    void addNumber(int number);
    int shortestSpan(void);
    int longestSpan(void);


    class StorageFullException : public std::exception {
       public:
        virtual const char *what() const throw();
    };
    class SpanCantBeFoundException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

   private:
    unsigned int _maxStorage;
    std::vector<int> _elements;
};

#endif