#include "Fixed.hpp"

int main()
{
    Fixed hello = Fixed((float const) 2.25);

    std::cout << hello.toFloat() << std::endl;
    std::cout << hello.toInt() << std::endl;
}