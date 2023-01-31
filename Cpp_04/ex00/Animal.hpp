#include <iostream>

class Animal {
    private:
    std::string type;

    public:
    Animal() ;
    Animal(std::string type);
    Animal(Animal &other);
    ~Animal();
};
