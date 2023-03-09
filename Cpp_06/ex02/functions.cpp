#include "functions.hpp"

Base * generate(void) {
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
    std::cout << "Type of object: ";
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
    std::cout << "Type of object: ";
    if (p.getType() == Type_Base) {
        std::cout << "Base";
    }
    if (p.getType() == Type_A) {
        std::cout << "A";
    }
    if (p.getType() == Type_B) {
        std::cout << "B";
    }
    if (p.getType() == Type_C) {
        std::cout << "C";
    }
    std::cout << std::endl;
};
