#include <iostream>

#include "Array.hpp"

int main() {
    Array<int> myArr(5);

    std::cout << "[0]: " << myArr[0] << std::endl;
    std::cout << "[1]: " << myArr[1] << std::endl;
    std::cout << "[2]: " << myArr[2] << std::endl;
    std::cout << "[3]: " << myArr[3] << std::endl;
    std::cout << "[4]: " << myArr[4] << std::endl;

    try {
        std::cout << "[5]: " << myArr[5] << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "this array is " << myArr.size() << " elements long" << std::endl;

    return 0;
}