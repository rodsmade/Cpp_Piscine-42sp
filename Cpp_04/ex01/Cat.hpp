#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
   private:
    Brain *_brain;

   public:
    Cat();
    Cat(const Cat &other);
    ~Cat();

    Cat &operator=(const Cat &other);

    void setType(const std::string &type);
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;

    void makeSound() const;
};
