#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Provide exactly one argument, e.g.: ./convert 42.0f" << std::endl;
        return -42;
    }

    std::cout << argv[0] << " " << argv[1] << std::endl;

    return 0;
}