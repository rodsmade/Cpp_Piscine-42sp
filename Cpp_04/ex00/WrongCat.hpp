#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
   protected:
    std::string _type;

   public:
    WrongCat();
    WrongCat(const WrongCat &other);
    ~WrongCat();

    std::string getType(void) const;

    WrongCat &operator=(const WrongCat &other);

    void makeSound() const;
};
