#include <iostream>

class Animal {
public:
    void makeSound() { 
        // virtual function with a default implementation
        std::cout << "This animal makes a sound.\n";
    }
};

class Dog : virtual public Animal {
public:
    void makeSound() { 
        // override the base class implementation
        std::cout << "This dog barks.\n";
    }
};

class Cat : public Animal {
public:
    void makeSound() { 
        // override the base class implementation
        std::cout << "This cat meows.\n";
    }
};

int main() {
    Animal* animalPtr;
    Dog dog;
    Cat cat;

    animalPtr = &dog;
    animalPtr->makeSound();  // calls Dog::makeSound()
    dog.makeSound();  // calls Dog::makeSound()

    animalPtr = &cat;
    animalPtr->makeSound();  // calls Cat::makeSound()
    cat.makeSound();  // calls Cat::makeSound()

    return 0;
}