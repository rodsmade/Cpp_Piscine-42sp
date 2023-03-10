#pragma once

#include <cstddef>

template <typename T>
class Array {
   public:
    // Constructors/Destructor
    Array();
    Array(unsigned int size);
    Array(const Array &other);
    ~Array();

    // operators
    Array<T> &operator=(const Array<T> &other);
    T &operator[](unsigned int index);

    // member functions
    unsigned int size() const;

   private:
    T *_elements;
    unsigned int _size;
};

#include "Array.tpp"
