#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iterator>
#include <stack>

class MutantStack {
   public:
    MutantStack();
    ~MutantStack();
    MutantStack &operator=(const MutantStack &other);
    // TODO:
    // top();
    // empty();
    // size();
    // push();
    // pop();


};

#include "MutantStack.tpp"

#endif