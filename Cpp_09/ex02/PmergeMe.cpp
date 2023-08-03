#include "PmergeMe.hpp"

// -------------------------------
// CANONICAL FORM
// -------------------------------
PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(int argc, char **argv) {
    if (argc < 2)
        throw std::exception();
    
    for (int i = 1; i < argc; i++) {
        // checks validity of argv[i]
        if (!_isPositiveInteger(std::string(argv[i])))
            throw std::exception();
        for (int j = 1; j < i; ++j) {
            if (std::string(argv[j]) == std::string(argv[i]))
                throw std::exception();
        }
        // inserts in list
        _inputArgs.push_back(atoi(argv[i]));
    }

    if (_inputArgs.size() % 2) {
        _oddOneOut = _inputArgs.back();
        _inputArgs.pop_back();
    }
};

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &other) {
    _inputArgs = other._inputArgs;
};

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    _inputArgs = other._inputArgs;
    return *this;
};

// -------------------------------
// GETTERS
// -------------------------------
std::list<int> &PmergeMe::getInputArgs() {
    return (_inputArgs);
};

int &PmergeMe::getOddOneOut() {
    return (_oddOneOut);
};

// -------------------------------
// PRIVATE FUNCTIONS
// -------------------------------
bool PmergeMe::_isPositiveInteger(std::string str) {
    if (str.length() == 0 || str.length() > 10)
        return (false);

    for (std::string::iterator it = str.begin(); it != str.end(); it++)
        if (!isdigit(*it))
            return (false);

    long i = std::atol(str.c_str());
    if (i == 0 || i > INT_MAX)
        return (false);

    return (true);
};

bool PmergeMe::_operatorLessThanForFirstElementInPair(std::pair<int, int> &lhs, std::pair<int, int> &rhs) {
    return (lhs.first < rhs.first);
}

double PmergeMe::_getNthTerm(double n) {
    if (n == 1)
        return 2;
    else
        return pow(2, n) - _getNthTerm(n - 1);
};

void PmergeMe::_merge(std::deque<std::pair<int, int> > &container, std::deque<std::pair<int, int> >::size_type left, std::deque<std::pair<int, int> >::size_type middle, std::deque<std::pair<int, int> >::size_type right) {
    std::deque<std::pair<int, int> >::size_type i, j, k;
    std::deque<std::pair<int, int> >::size_type n1 = middle - left + 1;
    std::deque<std::pair<int, int> >::size_type n2 = right - middle;

    std::deque<std::pair<int, int> > L(n1);
    std::deque<std::pair<int, int> > R(n2);

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

void PmergeMe::_mergeSort(std::deque<std::pair<int, int> > &container, std::deque<std::pair<int, int> >::size_type left, std::deque<std::pair<int, int> >::size_type right) {
    if (left < right) {
        std::deque<std::pair<int, int> >::size_type middle = left + (right - left) / 2;

        _mergeSort(container, left, middle);
        _mergeSort(container, middle + 1, right);

        _merge(container, left, middle, right);
    }
};

size_t PmergeMe::_getIndexInSequenceByTermNumber(int termNumber) {
    size_t i = 0;

    while (sortedSequence[i].second != termNumber)
        i++;

    return i;
};

void PmergeMe::_insertRecursive(int lowerLimit, int upperLimit, int elementToInsert) {
    if (elementToInsert < sortedSequence[lowerLimit].first) {
        std::deque<std::pair<int, int> >::iterator it = sortedSequence.begin();
        while (it->first != sortedSequence[lowerLimit].first)
            ++it;
        sortedSequence.insert(it, std::pair<int, int>(elementToInsert, -42));
    }
    else if (elementToInsert > sortedSequence[upperLimit].first) {
        std::deque<std::pair<int, int> >::iterator it = sortedSequence.begin();
        while (it->first != sortedSequence[upperLimit].first)
            ++it;
        ++it;
        sortedSequence.insert(it, std::pair<int, int>(elementToInsert, -42));
    }
    else if (upperLimit - lowerLimit == 1) {
        std::deque<std::pair<int, int> >::iterator it = sortedSequence.begin();
        while (it->first != sortedSequence[upperLimit].first)
            ++it;
        sortedSequence.insert(it, std::pair<int, int>(elementToInsert, -42));
    }
    else {
        int middlePoint = (lowerLimit + upperLimit) / 2;
        if (elementToInsert < sortedSequence[middlePoint].first)
            _insertRecursive(lowerLimit, middlePoint, elementToInsert);
        else
            _insertRecursive(middlePoint, upperLimit, elementToInsert);
    }
};

void PmergeMe::_binaryInsert(const std::pair<int, int> &element) {
    int elementToInsert = element.first;
    int upperLimit = _getIndexInSequenceByTermNumber(element.second) - 1;

    _insertRecursive(0, upperLimit, elementToInsert);
    return;
};

void PmergeMe::_mergeVector(std::vector<std::pair<int, int> > &container, std::vector<std::pair<int, int> >::size_type left, std::vector<std::pair<int, int> >::size_type middle, std::vector<std::pair<int, int> >::size_type right) {
    std::vector<std::pair<int, int> >::size_type i, j, k;
    std::vector<std::pair<int, int> >::size_type n1 = middle - left + 1;
    std::vector<std::pair<int, int> >::size_type n2 = right - middle;

    std::vector<std::pair<int, int> > L(n1);
    std::vector<std::pair<int, int> > R(n2);

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

void PmergeMe::_mergeSortVector(std::vector<std::pair<int, int> > &container, std::vector<std::pair<int, int> >::size_type left, std::vector<std::pair<int, int> >::size_type right) {
    if (left < right) {
        std::vector<std::pair<int, int> >::size_type middle = left + (right - left) / 2;

        _mergeSortVector(container, left, middle);
        _mergeSortVector(container, middle + 1, right);

        _mergeVector(container, left, middle, right);
    }
};

size_t PmergeMe::_getIndexInSequenceByTermNumberVector(int termNumber) {
    size_t i = 0;

    while (sortedSequenceVector[i].second != termNumber)
        i++;

    return i;
};

void PmergeMe::_insertRecursiveVector(int lowerLimit, int upperLimit, int elementToInsert) {
    if (elementToInsert < sortedSequenceVector[lowerLimit].first) {
        std::vector<std::pair<int, int> >::iterator it = sortedSequenceVector.begin();
        while (it->first != sortedSequenceVector[lowerLimit].first)
            ++it;
        sortedSequenceVector.insert(it, std::pair<int, int>(elementToInsert, -42));
    }
    else if (elementToInsert > sortedSequenceVector[upperLimit].first) {
        std::vector<std::pair<int, int> >::iterator it = sortedSequenceVector.begin();
        while (it->first != sortedSequenceVector[upperLimit].first)
            ++it;
        ++it;
        sortedSequenceVector.insert(it, std::pair<int, int>(elementToInsert, -42));
    }
    else if (upperLimit - lowerLimit == 1) {
        std::vector<std::pair<int, int> >::iterator it = sortedSequenceVector.begin();
        while (it->first != sortedSequenceVector[upperLimit].first)
            ++it;
        sortedSequenceVector.insert(it, std::pair<int, int>(elementToInsert, -42));
    }
    else {
        int middlePoint = (lowerLimit + upperLimit) / 2;
        if (elementToInsert < sortedSequenceVector[middlePoint].first)
            _insertRecursiveVector(lowerLimit, middlePoint, elementToInsert);
        else
            _insertRecursiveVector(middlePoint, upperLimit, elementToInsert);
    }
};

void PmergeMe::_binaryInsertVector(const std::pair<int, int> &element) {
    int elementToInsert = element.first;
    int upperLimit = _getIndexInSequenceByTermNumberVector(element.second) - 1;

    _insertRecursiveVector(0, upperLimit, elementToInsert);
    return;
};


// -------------------------------
// MEMBER FUNCTIONS
// -------------------------------
void PmergeMe::sortUsingDeque() {
    // Step 1 - Group the elements of X into ⌊n/2⌋ pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
    std::deque<std::pair<int, int> > deque;
    int a, b;
    for (std::list<int>::iterator it = _inputArgs.begin(); it != _inputArgs.end(); it++) {
        a = *(it++);
        b = *it;
        std::pair<int, int> pair(a, b);
        deque.push_back(pair);
    }

    // Step 2 - Perform ⌊ n/2 ⌋ comparisons, one per pair, to determine the larger of the two elements in each pair.
    for (std::deque<std::pair<int, int> >::iterator it = deque.begin(); it != deque.end(); it++) {
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }

    // Step 3 - Recursively sort the ⌊n/2⌋ larger elements from each pair, creating a sorted sequence S of ⌊n/2⌋ of the input elements, in ascending order.
    _mergeSort(deque, 0, deque.size() - 1);

    // Step 4 - Insert at the start of S the element that was paired with the first and smallest element of S

    unsortedSequence.push_back(std::pair<int, int>(0, 0));
    unsortedSequence.push_back(std::pair<int, int>(0, 1));

    std::deque<std::pair<int, int> >::iterator it = deque.begin();
    int index = 1;
    sortedSequence.push_back(std::pair<int, int>(it->first, index));
    it++;
    index++;
    for (; it != deque.end(); it++) {
        sortedSequence.push_back(std::pair<int, int>(it->first, index));
        unsortedSequence.push_back(std::pair<int, int>(it->second, index));
        index++;
    }

    sortedSequence.insert(sortedSequence.begin(), std::pair<int, int>(deque[0].second, 0));
    if (_oddOneOut)
        unsortedSequence.push_back(std::pair<int, int>(_oddOneOut, index));

    // Step 5 - LETS GO
    // 5.1 - partition into groups and order elements by index in reverse order within their groups
    // 2, 2, 6, 10, 22, 42, 86, etc.
    double n = 1;
    double begin, end, nthTerm;
    begin = 2;
    double elementsLeft = unsortedSequence.size() - 2; // first 2 elements don't count !!
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
        _binaryInsert(unsortedSequence[0]);
        unsortedSequence.erase(unsortedSequence.begin());
    }
};

void PmergeMe::sortUsingVector() {
    // Step 1 - Group the elements of X into ⌊n/2⌋ pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
    std::vector<std::pair<int, int> > vector;
    int a, b;
    for (std::list<int>::iterator it = _inputArgs.begin(); it != _inputArgs.end(); it++) {
        a = *it;
        b = *(++it);
        std::pair<int, int> pair(a, b);
        vector.push_back(pair);
    }

    // Step 2 - Perform ⌊ n/2 ⌋ comparisons, one per pair, to determine the larger of the two elements in each pair.
    for (std::vector<std::pair<int, int> >::iterator it = vector.begin(); it != vector.end(); it++) {
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }

    // Step 3 - Recursively sort the ⌊n/2⌋ larger elements from each pair, creating a sorted sequence S of ⌊n/2⌋ of the input elements, in ascending order.
    _mergeSortVector(vector, 0, vector.size() - 1);

    // Step 4 - Insert at the start of S the element that was paired with the first and smallest element of S

    unsortedSequenceVector.push_back(std::pair<int, int>(0, 0));
    unsortedSequenceVector.push_back(std::pair<int, int>(0, 1));

    std::vector<std::pair<int, int> >::iterator it = vector.begin();
    int index = 1;
    sortedSequenceVector.push_back(std::pair<int, int>(it->first, index));
    it++;
    index++;
    for (; it != vector.end(); it++) {
        sortedSequenceVector.push_back(std::pair<int, int>(it->first, index));
        unsortedSequenceVector.push_back(std::pair<int, int>(it->second, index));
        index++;
    }

    sortedSequenceVector.insert(sortedSequenceVector.begin(), std::pair<int, int>(vector[0].second, 0));
    if (_oddOneOut)
        unsortedSequenceVector.push_back(std::pair<int, int>(_oddOneOut, index));

    // Step 5 - LETS GO
    // 5.1 - partition into groups and order elements by index in reverse order within their groups
    // 2, 2, 6, 10, 22, 42, 86, etc.
    double n = 1;
    double begin, end, nthTerm;
    begin = 2;
    double elementsLeft = unsortedSequenceVector.size() - 2; // first 2 elements don't count !!
    while (elementsLeft > 0) {
        nthTerm = _getNthTerm(n);
        if (nthTerm <= elementsLeft)
            end = begin + nthTerm;
        else
            end = begin + elementsLeft;
        std::reverse(&unsortedSequenceVector[begin], &unsortedSequenceVector[end]);
        n++;
        begin = end;
        elementsLeft -= nthTerm;
    }

    // 5.2 - insert elements into S. use binary search from the start of S up to but not including xi to determine where to insert yi.
    unsortedSequenceVector.erase(unsortedSequenceVector.begin());
    unsortedSequenceVector.erase(unsortedSequenceVector.begin());
    while (unsortedSequenceVector.size() > 0) {
        _binaryInsertVector(unsortedSequenceVector[0]);
        unsortedSequenceVector.erase(unsortedSequenceVector.begin());
    }
};
