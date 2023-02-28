#pragma once

#include <iostream>

class Animal {
   protected:
    std::string _type;

   public:
    Animal();
    Animal(const Animal &other);
    virtual ~Animal();

    std::string getType(void) const;

    Animal &operator=(const Animal &other);

    virtual void makeSound() const;
};
