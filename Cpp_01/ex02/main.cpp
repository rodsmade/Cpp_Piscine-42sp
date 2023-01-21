#include <iostream>

int main() {
    std::string aString = "HI THIS IS BRAIN";
    std::string *stringPTR = &aString;
    std::string &stringREF = aString;
    // se não inicializar a ref, o compilador reclama:  error: declaration of reference variable 'stringREF' requires an initializer

    std::cout << "Address of aString: " << &aString << std::endl;
    std::cout << "Address pointed to by stringPTR: " << stringPTR << std::endl;
    std::cout << "Address pointed to by stringREF: " << &stringREF << std::endl;

    std::cout << "Value of aString: " << aString << std::endl;
    std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF: " << stringREF << std::endl;

    return (0);
}