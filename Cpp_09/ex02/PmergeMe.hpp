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

    std::list<int>  &getInputArgs();
    int             &getOddOneOut();

    void sortUsingDeque();

    std::deque<std::pair<int, int> > sortedSequence;
    std::deque<std::pair<int, int> > unsortedSequence;

   private:
    int             _oddOneOut;
    std::list<int>  _inputArgs;

    bool    _isPositiveInteger(std::string str);
    bool    _operatorLessThanForFirstElementInPair(std::pair<int, int> &lhs, std::pair<int, int> &rhs);
    void    _merge(std::deque<std::pair<int, int> > &arr, std::deque<int>::size_type left, std::deque<int>::size_type middle, std::deque<int>::size_type right);
    void    _mergeSort(std::deque<std::pair<int, int> > &arr, std::deque<int>::size_type left, std::deque<int>::size_type right);
    double  _getNthTerm(double n);
    size_t  _getIndexInSequenceByTermNumber(int termNumber);
    void    _insertRecursive(int lowerLimit, int upperLimit, int elementToInsert);
    void    _binaryInsert(const std::pair<int, int> &element);
};

#endif
