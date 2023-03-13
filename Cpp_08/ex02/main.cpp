#include <iostream>

#include "MutantStack.hpp"

void reportStackSize(const MutantStack<int>& s)
{
    std::cout << s.size() << " elements on stack\n";
}

void reportStackTop(const MutantStack<int>& s)
{
    // Leaves element on stack
    std::cout << "Top element: " << s.top() << '\n';
}

int main()
{
    MutantStack<int> s;

    std::cout << std::boolalpha;
    std::cout << "Initially, s.empty(): " << s.empty() << '\n';

    s.push(2);
    s.push(6);
    s.push(51);

    std::cout << "After adding elements, s.empty(): " << s.empty() << '\n';

    reportStackSize(s);
    reportStackTop(s);
 
    reportStackSize(s);
    s.pop();
 
    reportStackSize(s);
    reportStackTop(s);
}
