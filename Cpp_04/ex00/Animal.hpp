#include <iostream>

class Animal {
    private:
    std::string _type;

    public:
    Animal() ;
    Animal(const std::string type);
    Animal(const Animal &other);
    ~Animal();

    void makeSound();
};
