#include "functions.hpp"

Base* generate(void) {
    std::srand(std::time(0));
    int randNb = std::rand() % 3;

    if (randNb == 0) {
        return new A();
    } else if (randNb == 1) {
        return new B();
    } else {
        return new C();
    }
};

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A";
    }
    if (dynamic_cast<B*>(p)) {
        std::cout << "B";
    }
    if (dynamic_cast<C*>(p)) {
        std::cout << "C";
    }
    std::cout << std::endl;
};

void identify(Base& p) {
    try {
        A& aPtr = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void) aPtr;
        return;
    } catch (const std::exception& e) {
        try {
            B& bPtr = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            (void) bPtr;
            return;
        } catch (const std::exception& e) {
            try {
                C& cPtr = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                (void) cPtr;
                return;
            } catch (const std::exception& e) {
                std::cout << "ERROR OGKJDFGKASKDOASK" << std::endl;
                return;
            }
        }
    }
};
