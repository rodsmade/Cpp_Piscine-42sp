#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
   private:
    Brain *_brain;

   public:
    Dog();
    Dog(const Dog &other);
    ~Dog();

    Dog &operator=(const Dog &other);

    void makeSound() const;
};
