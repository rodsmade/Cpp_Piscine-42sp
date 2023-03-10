#include <iostream>

#include "Array.hpp"

int main() {
    Array<int> myArr(5);

    for (unsigned int i = 0; i < myArr.size(); i++)
        std::cout << "myArr[" << i << "]: " << myArr[i] << std::endl;

    try {
        std::cout << "[5]: " << myArr[5] << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "myArr is " << myArr.size() << " elements long" << std::endl;

    Array<int> copy(myArr);

    for (unsigned int i = 0; i < copy.size(); i++)
        copy[i] = 2;

    for (unsigned int i = 0; i < myArr.size(); i++)
        std::cout << "copy[" << i << "]: " << myArr[i] << std::endl;
    std::cout << "copy is " << myArr.size() << " elements long" << std::endl;

    return 0;
}