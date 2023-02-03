#include <iostream>

class Animal {
    protected:
    std::string _type;

    public:
    Animal() ;
    Animal(const std::string type);
    Animal(const Animal &other);
    ~Animal();

    Animal &operator=(const Animal &other);

    void makeSound();

};
