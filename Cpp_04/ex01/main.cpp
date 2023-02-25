#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>
#include <sstream>
#include <string>

int main()
{
    {
        // Mandatory tests
        std::cout << "===================================================== Mandatory tests:" << std::endl;
        {
            std::cout << "--- Basic Constructor and Destructor test ---" << std::endl;
            const Animal* dogPtr = new Dog();
            const Animal* catPtr = new Cat();

            delete dogPtr;//should not create a leak
            delete catPtr;
        }
        {
            std::cout << std::endl;
            std::cout << "--- Array test ---" << std::endl;
            std::cout << "... creating array ..." << std::endl;
            Animal *animals[10];
            for (int i = 0; i < 10; i++) {
                if (i % 2) {
                    animals[i] = new Dog();
                } else {
                    animals[i] = new Cat();
                }
            }
            std::cout << "... destroying array ..." << std::endl;
            for (int i = 0; i < 10; i++) {
                delete animals[i];
            }
        }

        std::cout << std::endl;
    }
    {
        // My tests
        std::cout << "===================================================== My tests:" << std::endl;

        std::cout << "--- Instantiating a Cat object: ---" << std::endl;
        Cat* catPtr = new Cat();

        std::cout << std::endl;
        std::cout << "--- Setting and getting one idea: ---" << std::endl;
        catPtr->setIdea(0, "Catch a mouse");
        std::cout << "Cat's idea at index 0: " << catPtr->getIdea(0) << std::endl;
        std::cout << std::endl;

        std::cout << std::endl;
        std::cout << "--- Setting and getting many ideas: ---" << std::endl;
        for (int i = 0; i < 101; i++) {
            std::ostringstream oss;
            oss << i;
            std::string str = oss.str();
            if (i == 1)
                catPtr->setIdea(i, "Catch " + str + " mouse");
            else
                catPtr->setIdea(i, "Catch " + str + " mice");
        }
        for (int i = 0; i < 101; i++) {
            std::ostringstream oss;
            oss << i;
            std::string str = oss.str();
            std::cout << "Cat's idea at index " + str + ": " << catPtr->getIdea(i) << std::endl;
        }

        std::cout << std::endl;
        std::cout << "--- Destroying a Cat object: ---" << std::endl;
        delete catPtr;

        std::cout << std::endl;
        std::cout << "--- Copying a Cat object: ---" << std::endl;
        std::string newType = "Persian";
        Cat cat1;
        Cat cat2 = cat1; // Deep copy
        std::cout << cat1.getType() << " is the type of cat1" << std::endl;
        std::cout << cat2.getType() << " is the type of cat2" << std::endl;
        cat2.setType(newType);
        std::cout << cat1.getType() << " is the type of cat1" << std::endl;
        std::cout << cat2.getType() << " is the type of cat2" << std::endl;
    }
    {
        std::cout << std::endl;
        std::cout << "===================================================== Surprise, surprise!" << std::endl;
        Dog doggo;
        {
            Dog temp = doggo;
            temp.setIdea(0, "Wag my lil' tail at all times");
            doggo.setIdea(0, "Wag my lil' tail at all times");
            temp.setIdea(1, "Suss out everything with my lil' snoot");
            std::cout << "0th idea in my brain: " << temp.getIdea(0) << std::endl;
            std::cout << "1st idea in my brain: " << temp.getIdea(1) << std::endl;
        }
        std::cout << "0th idea in my brain: " << doggo.getIdea(0) << std::endl;
        std::cout << "1st idea in my brain: " << doggo.getIdea(1) << std::endl;
        Cat purrBall;
        {
            Cat temp = purrBall;
            temp.setIdea(0, "Sniff toes and look astonished");
            purrBall.setIdea(0, "Sniff toes and look astonished");
            temp.setIdea(1, "Tip every glass I come across");
            std::cout << "0th idea in my brain: " << temp.getIdea(0) << std::endl;
            std::cout << "1st idea in my brain: " << temp.getIdea(1) << std::endl;
        }
        std::cout << "0th idea in my brain: " << purrBall.getIdea(0) << std::endl;
        std::cout << "1st idea in my brain: " << purrBall.getIdea(1) << std::endl;
    }
    return 0;
}