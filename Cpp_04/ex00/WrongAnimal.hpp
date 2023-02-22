#pragma once

#include <iostream>

class WrongAnimal {
   protected:
    std::string _type;

   public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    ~WrongAnimal();

    std::string getType(void) const;

    WrongAnimal &operator=(const WrongAnimal &other);

    void makeSound() const;
};
