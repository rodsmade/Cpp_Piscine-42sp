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

    void    _merge(std::deque<std::pair<int, int> > &arr, std::deque<std::pair<int, int> >::size_type left, std::deque<std::pair<int, int> >::size_type middle, std::deque<std::pair<int, int> >::size_type right);
    void    _mergeSort(std::deque<std::pair<int, int> > &arr, std::deque<std::pair<int, int> >::size_type left, std::deque<std::pair<int, int> >::size_type right);
    size_t  _getIndexInSequenceByTermNumber(int termNumber);
    void    _insertRecursive(int lowerLimit, int upperLimit, int elementToInsert);
    void    _binaryInsert(const std::pair<int, int> &element);

    void    _mergeVector(std::vector<std::pair<int, int> > &arr, std::vector<std::pair<int, int> >::size_type left, std::vector<std::pair<int, int> >::size_type middle, std::vector<std::pair<int, int> >::size_type right);
    void    _mergeSortVector(std::vector<std::pair<int, int> > &arr, std::vector<std::pair<int, int> >::size_type left, std::vector<std::pair<int, int> >::size_type right);
    size_t  _getIndexInSequenceByTermNumberVector(int termNumber);
    void    _insertRecursiveVector(int lowerLimit, int upperLimit, int elementToInsert);
    void    _binaryInsertVector(const std::pair<int, int> &element);
};

#endif
