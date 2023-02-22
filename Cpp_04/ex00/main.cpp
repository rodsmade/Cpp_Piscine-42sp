#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    {  // Pdf tests:
        std::cout << "Pdf tests:" << std::endl;
        const Animal* ptrToAnimal = new Animal();
        const Animal* ptrToDog = new Dog();
        const Animal* ptrToCat = new Cat();
        std::cout << ptrToDog->getType() << " " << std::endl;
        std::cout << ptrToCat->getType() << " " << std::endl;
        ptrToCat->makeSound();  // will output the cat sound!
        ptrToDog->makeSound();
        ptrToAnimal->makeSound();
        std::cout << std::endl;

        delete ptrToAnimal;
        delete ptrToDog;
        delete ptrToCat;
    }
    {  // My tests:
        std::cout << "My tests:" << std::endl;
        std::cout << "Method calling by pointer:" << std::endl;
        // If I use a base class pointer to point to an inherited class, the pointer will go for the base class' definition of the function (bc there's no 'virtual' declaration there)
        const WrongAnimal* ptrToWrongAnimal = new WrongAnimal();
        const WrongAnimal* ptrToWrongCat = new WrongCat();
        ptrToWrongCat->makeSound();
        ptrToWrongAnimal->makeSound();
        delete ptrToWrongAnimal;
        delete ptrToWrongCat;

        std::cout << "Method calling by object:" << std::endl;
        // However, if I simply instantiate the objects, because I'm explicitly and directly calling the inherited class' object, no confusion takes place.
        const WrongAnimal wrongAnimalObj = WrongAnimal();
        const WrongCat wrongCatObj = WrongCat();
        wrongCatObj.makeSound();
        wrongAnimalObj.makeSound();

        std::cout << "WrongCat says: my type is " << wrongCatObj.getType() << std::endl;
        std::cout << "WrongCat says: my base class' type is " << wrongCatObj.WrongAnimal::getType() << std::endl;

    }
    return 0;
}
