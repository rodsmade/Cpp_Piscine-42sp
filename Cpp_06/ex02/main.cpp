#include "functions.hpp"

int main() {
    Base *randomClass = generate();

    identify(randomClass);
    identify(*randomClass);

    delete randomClass;

    return (0);
}