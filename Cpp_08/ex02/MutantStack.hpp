#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iterator>
#include <stack>

template <typename T>
class MutantStack {
   public:
    MutantStack();
    ~MutantStack();
    MutantStack &operator=(const MutantStack &other);
    // TODO:
    const T &top() const;
    bool empty() const;
    std::size_t size() const;
    void push(T element);
    void pop();

   private:
    std::stack<T> _mStack;


};

#include "MutantStack.tpp"

#endif