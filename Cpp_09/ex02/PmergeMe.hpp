#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>  // exit()
#include <iostream>
#include <deque>
#include <list>
#include <vector>

class PmergeMe {
   public:
    PmergeMe();
    PmergeMe(int argc, char **argv);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    std::list<int> &getInputArgs();

   private:
    std::list<int> _inputArgs;

    bool _isPositiveInteger(std::string str);

};

#endif
