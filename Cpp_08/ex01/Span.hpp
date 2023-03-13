#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>

class Span {
   public:
    Span(unsigned int N);
    Span(const Span &other);
    ~Span(void);
    const Span &operator=(const Span &other);

    unsigned int getSize(void);
    void addNumber(int number);

    class StorageFullException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

   private:
    unsigned int _maxStorage;
    std::vector<int> _elements;
};

#endif