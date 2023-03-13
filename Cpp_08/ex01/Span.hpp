#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {
   public:
    Span(unsigned int N);
    Span(const Span &other);
    ~Span(void);
    const Span &operator=(const Span &other);

   private:
    unsigned int _maxStorage;
    std::vector<int> _elements;
};

#endif