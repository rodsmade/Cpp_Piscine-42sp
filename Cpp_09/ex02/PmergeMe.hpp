#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cassert>  // assert()
#include <climits>  // INT_MAX
#include <cstdlib>  // exit()
#include <deque>
#include <iostream>
#include <list>
#include <math.h>
#include <sys/time.h>
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
    void sortUsingVector();

    std::deque<std::pair<int, int> > sortedSequence;
    std::deque<std::pair<int, int> > unsortedSequence;
    std::vector<std::pair<int, int> > sortedSequenceVector;
    std::vector<std::pair<int, int> > unsortedSequenceVector;

   private:
    int             _oddOneOut;
    std::list<int>  _inputArgs;

    bool    _isPositiveInteger(std::string str);
    bool    _operatorLessThanForFirstElementInPair(std::pair<int, int> &lhs, std::pair<int, int> &rhs);
    double  _getNthTerm(double n);

    void    _reversePairsInRange(double begin, double end);
    void    _merge(std::deque<std::pair<int, int> > &arr, std::deque<int>::size_type left, std::deque<int>::size_type middle, std::deque<int>::size_type right);
    void    _mergeSort(std::deque<std::pair<int, int> > &arr, std::deque<int>::size_type left, std::deque<int>::size_type right);
    size_t  _getIndexInSequenceByTermNumber(int termNumber);
    void    _insertRecursive(int lowerLimit, int upperLimit, int elementToInsert);
    void    _binaryInsert(const std::pair<int, int> &element);

    void    _reversePairsInRangeVector(double begin, double end);
    void    _mergeVector(std::vector<std::pair<int, int> > &arr, std::vector<int>::size_type left, std::vector<int>::size_type middle, std::vector<int>::size_type right);
    void    _mergeSortVector(std::vector<std::pair<int, int> > &arr, std::vector<int>::size_type left, std::vector<int>::size_type right);
    size_t  _getIndexInSequenceByTermNumberVector(int termNumber);
    void    _insertRecursiveVector(int lowerLimit, int upperLimit, int elementToInsert);
    void    _binaryInsertVector(const std::pair<int, int> &element);
};

#endif
