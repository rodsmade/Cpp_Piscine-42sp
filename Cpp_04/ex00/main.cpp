#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // Pdf tests:
    const Animal* ptrToAnimal = new Animal();
    const Animal* ptrToDog = new Dog();
    const Animal* ptrToCat = new Cat();
    std::cout << ptrToDog->getType() << " " << std::endl;
    std::cout << ptrToCat->getType() << " " << std::endl;
    ptrToCat->makeSound();  // will output the cat sound!
    ptrToDog->makeSound();
    ptrToAnimal->makeSound();

    return 0;
}
