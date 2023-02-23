#pragma once

#include <iostream>

class Animal {
    protected:
    std::string _type;

    public:
    Animal() ;
    Animal(const Animal &other);
    virtual ~Animal();
    Animal &operator=(const Animal &other);

    virtual void makeSound() const = 0;

};
