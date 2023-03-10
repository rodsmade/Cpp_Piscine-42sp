#include <iostream>

#include "Array.hpp"

int main() {

    Array<int> emptyArr;

    Array<int> myArr(5);

    std::cout << "myArr is " << myArr.size() << " elements long" << std::endl;
    for (unsigned int i = 0; i < myArr.size(); i++)
        std::cout << "myArr[" << i << "]: " << myArr[i] << std::endl;

    try {
        std::cout << "[5]: " << myArr[5] << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Array<int> copy(myArr);

    for (unsigned int i = 0; i < copy.size(); i++)
        copy[i] = 42;

    std::cout << "copy is " << copy.size() << " elements long" << std::endl;
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << "copy[" << i << "]: " << copy[i] << std::endl;
    for (unsigned int i = 0; i < myArr.size(); i++)
        std::cout << "myArr[" << i << "]: " << myArr[i] << std::endl;

    return 0;
}