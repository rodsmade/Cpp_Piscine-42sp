#pragma once

#include <cstddef>

/* Example:
template <typename T>
class Stack {
public:
  Stack();
  void push(T value);
  T pop();
  bool isEmpty();
private:
  std::vector<T> elements_;
};
*/

template <typename T>
class Array {
   public:
    Array();
    Array(unsigned int size);
    void do_something();

   private:
    T *_elements;
    unsigned int _size;
};

#include "Array.tpp"