#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>  // exit()
#include <deque>
#include <iostream>
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
    int &getOddOneOut();

    // All of this will GO eventually
    void sortUsingDeque();
    void sortUsingVector();

    template <typename Container>
    Container mergeInsertionSortGENERIC() {
        // Step 1 - Group the elements of X into ⌊n/2⌋ pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
        Container pairs;
        int a, b;
        for (std::list<int>::iterator it = _inputArgs.begin(); it != _inputArgs.end(); it++) {
            a = *it;
            b = *(++it);
            std::pair<int, int> pair(a, b);
            pairs.push_back(pair);
        }

        // Step 2 - Perform ⌊ n/2 ⌋ comparisons, one per pair, to determine the larger of the two elements in each pair.
        for (typename Container::iterator it = pairs.begin(); it != pairs.end(); it++) {
            if (it->first < it->second)
                std::swap(it->first, it->second);
        }

        // Step 3 - Recursively sort the ⌊n/2⌋ larger elements from each pair, creating a sorted sequence S of ⌊n/2⌋ of the input elements, in ascending order.
        _mergeSortGENERIC(pairs, 0, pairs.size() - 1);

        // Step 4 - Insert at the start of S the element that was paired with the first and smallest element of S
        Container sortedSequence;
        Container unsortedSequence;

        unsortedSequence.push_back(std::pair<int, int>(0, 0));
        unsortedSequence.push_back(std::pair<int, int>(0, 1));

        typename Container::iterator it = pairs.begin();
        int index = 1;
        sortedSequence.push_back(std::pair<int, int>(it->first, index));
        it++;
        index++;
        for (; it != pairs.end(); it++) {
            sortedSequence.push_back(std::pair<int, int>(it->first, index));
            unsortedSequence.push_back(std::pair<int, int>(it->second, index));
            index++;
        }

        sortedSequence.insert(sortedSequence.begin(), std::pair<int, int>(pairs[0].second, 0));
        if (_oddOneOut)
            unsortedSequence.push_back(std::pair<int, int>(_oddOneOut, index));

        // Step 5 - LETS GO
        // 5.1 - partition into groups and order elements by index in reverse order within their groups
        // 2, 2, 6, 10, 22, 42, 86, etc.
        double n = 1;
        double begin, end, nthTerm;
        begin = 2;
        double elementsLeft = unsortedSequence.size() - 2;  // first 2 elements don't count !!
        while (elementsLeft > 0) {
            nthTerm = _getNthTerm(n);
            if (nthTerm <= elementsLeft)
                end = begin + nthTerm;
            else
                end = begin + elementsLeft;
            std::reverse(&unsortedSequence[begin], &unsortedSequence[end]);
            n++;
            begin = end;
            elementsLeft -= nthTerm;
        }

        // 5.2 - insert elements into S. use binary search from the start of S up to but not including xi to determine where to insert yi.
        unsortedSequence.erase(unsortedSequence.begin());
        unsortedSequence.erase(unsortedSequence.begin());
        while (unsortedSequence.size() > 0) {
            _binaryInsertGENERIC(unsortedSequence[0], sortedSequence);
            unsortedSequence.erase(unsortedSequence.begin());
        }

        return (sortedSequence);
    };

    // All of this will GO eventually
    std::deque<std::pair<int, int> > sortedSequence;
    std::deque<std::pair<int, int> > unsortedSequence;
    std::vector<std::pair<int, int> > sortedSequenceVector;
    std::vector<std::pair<int, int> > unsortedSequenceVector;

   private:
    int _oddOneOut;
    std::list<int> _inputArgs;

    // General use
    bool _isPositiveInteger(std::string str);
    bool _operatorLessThanForFirstElementInPair(std::pair<int, int> &lhs, std::pair<int, int> &rhs);
    double _getNthTerm(double n);

    // Deque-specific
    void _merge(std::deque<std::pair<int, int> > &arr, std::deque<std::pair<int, int> >::size_type left, std::deque<std::pair<int, int> >::size_type middle, std::deque<std::pair<int, int> >::size_type right);
    void _mergeSort(std::deque<std::pair<int, int> > &arr, std::deque<std::pair<int, int> >::size_type left, std::deque<std::pair<int, int> >::size_type right);
    size_t _getIndexInSequenceByTermNumber(int termNumber);
    void _insertRecursive(int lowerLimit, int upperLimit, int elementToInsert);
    void _binaryInsert(const std::pair<int, int> &element);

    // Vector-specific
    void _mergeVector(std::vector<std::pair<int, int> > &arr, std::vector<std::pair<int, int> >::size_type left, std::vector<std::pair<int, int> >::size_type middle, std::vector<std::pair<int, int> >::size_type right);
    void _mergeSortVector(std::vector<std::pair<int, int> > &arr, std::vector<std::pair<int, int> >::size_type left, std::vector<std::pair<int, int> >::size_type right);
    size_t _getIndexInSequenceByTermNumberVector(int termNumber);
    void _insertRecursiveVector(int lowerLimit, int upperLimit, int elementToInsert);
    void _binaryInsertVector(const std::pair<int, int> &element);

    // GENERIC BABES
    template <typename Container>
    void _mergeGENERIC(Container &container, typename Container::size_type left, typename Container::size_type middle, typename Container::size_type right) {
        typename Container::size_type i, j, k;
        typename Container::size_type n1 = middle - left + 1;
        typename Container::size_type n2 = right - middle;

        Container L(n1);
        Container R(n2);

        for (i = 0; i < n1; i++)
            L[i] = container[left + i];
        for (j = 0; j < n2; j++)
            R[j] = container[middle + 1 + j];

        i = 0;
        j = 0;
        k = left;

        while (i < n1 && j < n2) {
            if (_operatorLessThanForFirstElementInPair(L[i], R[j])) {
                container[k] = L[i];
                i++;
            } else {
                container[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            container[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            container[k] = R[j];
            j++;
            k++;
        }
    };

    template <typename Container>
    void _mergeSortGENERIC(Container &container, typename Container::size_type left, typename Container::size_type right) {
        if (left < right) {
            typename Container::size_type middle = left + (right - left) / 2;

            _mergeSortGENERIC(container, left, middle);
            _mergeSortGENERIC(container, middle + 1, right);

            _mergeGENERIC(container, left, middle, right);
        }
    };

    template <typename Container>
    size_t _getIndexInSequenceByTermNumberGENERIC(int termNumber, Container &sortedSequence) {
        size_t i = 0;

        while (sortedSequence[i].second != termNumber)
            i++;

        return i;
    };

    template <typename Container>
    void _insertRecursiveGENERIC(int lowerLimit, int upperLimit, int elementToInsert, Container &sortedSequence) {
        if (elementToInsert < sortedSequence[lowerLimit].first) {
            typename Container::iterator it = sortedSequence.begin();
            while (it->first != sortedSequence[lowerLimit].first)
                ++it;
            sortedSequence.insert(it, std::pair<int, int>(elementToInsert, -42));
        } else if (elementToInsert > sortedSequence[upperLimit].first) {
            typename Container::iterator it = sortedSequence.begin();
            while (it->first != sortedSequence[upperLimit].first)
                ++it;
            ++it;
            sortedSequence.insert(it, std::pair<int, int>(elementToInsert, -42));
        } else if (upperLimit - lowerLimit == 1) {
            typename Container::iterator it = sortedSequence.begin();
            while (it->first != sortedSequence[upperLimit].first)
                ++it;
            sortedSequence.insert(it, std::pair<int, int>(elementToInsert, -42));
        } else {
            int middlePoint = (lowerLimit + upperLimit) / 2;
            if (elementToInsert < sortedSequence[middlePoint].first)
                _insertRecursiveGENERIC(lowerLimit, middlePoint, elementToInsert, sortedSequence);
            else
                _insertRecursiveGENERIC(middlePoint, upperLimit, elementToInsert, sortedSequence);
        }
    };

    template <typename Container>
    void _binaryInsertGENERIC(const std::pair<int, int> &element, Container &sortedSequence) {
        int elementToInsert = element.first;
        int upperLimit = _getIndexInSequenceByTermNumberGENERIC(element.second, sortedSequence) - 1;

        _insertRecursiveGENERIC(0, upperLimit, elementToInsert, sortedSequence);
        return;
    };
};

#endif
