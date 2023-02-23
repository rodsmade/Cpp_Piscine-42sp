#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>
#include <sstream>
#include <string>

int main()
{
    {
        // Mandatory tests
        std::cout << "Mandatory tests:" << std::endl;
        const Animal* dogPtr = new Dog();
        const Animal* catPtr = new Cat();

        delete dogPtr;//should not create a leak
        delete catPtr;
        std::cout << std::endl;
    }
    {
        // Mandatory tests
        std::cout << "My tests:" << std::endl;
        Cat* catPtr = new Cat();
        catPtr->setIdea(0, "Catch a mouse");
        std::cout << "Cat's idea at index 0: " << catPtr->getIdea(0) << std::endl;
        std::cout << std::endl;

        for (int i = 0; i < 110; i++) {
            std::ostringstream oss;
            oss << i;
            std::string str = oss.str();
            if (i == 1)
                catPtr->setIdea(i, "Catch " + str + " mouse");
            else
                catPtr->setIdea(i, "Catch " + str + " mice");
        }
        for (int i = 0; i < 110; i++) {
            std::ostringstream oss;
            oss << i;
            std::string str = oss.str();
            std::cout << "Cat's idea at index " + str + ": " << catPtr->getIdea(i) << std::endl;
        }

        delete catPtr;
    }
return 0;
}