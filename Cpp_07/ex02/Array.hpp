#pragma once

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
    Array(T arg);
    void do_something();

   private:
    T m_data;
};

#include "Array.tpp"