#include <iostream>

#include "MutantStack.hpp"

// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }

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
    s.push(42);
    s.push(51);

    std::cout << "After adding elements, s.empty(): " << s.empty() << '\n';

    reportStackSize(s);
    reportStackTop(s);
 
    reportStackSize(s);
    s.pop();
 
    reportStackSize(s);
    reportStackTop(s);


    MutantStack<int>::iterator it = s.begin();
    MutantStack<int>::iterator ite = s.end();

    for (int index = 0; index < (ite - it); index++){
        std::cout << "Pos [" << index << "] Value[" << *(it + index) << "]" << std::endl;
    }
}
