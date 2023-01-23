#include "Fixed.hpp"

int main()
{
    Fixed hello = Fixed((float const) 42.42);

    std::cout << hello.toFloat() << std::endl;
    std::cout << hello.toInt() << std::endl;

    std::cout << hello << std::endl;
}