#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    std::vector<int> v(arr, arr + 5);
    int value = 3;
    try {
        std::vector<int>::iterator it = easyfind(v, value);
        std::cout << "Value " << value << " found at index " << std::distance(v.begin(), it) << std::endl;
    }
    catch (const std::out_of_range& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    value = 42;
    try {
        std::vector<int>::iterator it = easyfind(v, value);
        std::cout << "Value " << value << " found at index " << std::distance(v.begin(), it) << std::endl;
    }
    catch (const std::out_of_range& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    return 0;
}