#include <cstdlib>  // exit()
#include <iostream>
#include <deque>
#include <list>

std::deque<std::pair<int, int> > sortedSequence;
std::deque<std::pair<int, int> > unsortedSequence;

bool isPositiveInteger(std::string str) {
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

void printPair(std::pair<int, int> pair) {
    std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
};

int printErrorAndExit() {
    std::cout << "Error" << std::endl;
    return (EXIT_FAILURE);
};

bool operatorLessThanForFirstElementInPair(std::pair<int, int> &lhs, std::pair<int, int> &rhs) {
    return (lhs.first < rhs.first);
}

void merge(std::deque<std::pair<int, int> > &arr, std::deque<int>::size_type left, std::deque<int>::size_type middle, std::deque<int>::size_type right) {
    std::deque<int>::size_type i, j, k;
    std::deque<int>::size_type n1 = middle - left + 1;
    std::deque<int>::size_type n2 = right - middle;

    std::deque<std::pair<int, int> > L(n1);
    std::deque<std::pair<int, int> > R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (operatorLessThanForFirstElementInPair(L[i], R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
};

void mergeSort(std::deque<std::pair<int, int> > &arr, std::deque<int>::size_type left, std::deque<int>::size_type right) {
    if (left < right) {
        std::deque<int>::size_type middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
};

double getNthTerm(double n) {
    if (n == 1)
        return 2;
    else
        return pow(2, n) - getNthTerm(n - 1);
};

size_t getIndexInSequenceByTermNumber(int termNumber) {
    size_t i = 0;

    while (sortedSequence[i].second != termNumber)
        i++;

    return i;
};

void insertRecursive(int lowerLimit, int upperLimit, int elementToInsert) {
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
            insertRecursive(lowerLimit, middlePoint, elementToInsert);
        else
            insertRecursive(middlePoint, upperLimit, elementToInsert);
    }
};

void binaryInsert(const std::pair<int, int> &element) {
    int elementToInsert = element.first;
    int upperLimit = getIndexInSequenceByTermNumber(element.second) - 1;

    insertRecursive(0, upperLimit, elementToInsert);
    return;
};

template <typename C>
void printSequence(C &sequence, std::string state) {
    std::cout << state << ":\t";
    for (typename C::iterator it = sequence.begin(); it != sequence.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
};

void assertIsSorted() {
    bool isSorted = true;

    for (size_t i = 0; i < sortedSequence.size() - 1; i++)
        isSorted = isSorted && (sortedSequence[i] < sortedSequence[i + 1]);

    assert(isSorted);
}

int main(int argc, char **argv) {
    if (argc == 1)
        return (printErrorAndExit());

    std::list<int> inputArgs;
    for (int i = 1; i < argc; i++) {
        // checks validity of argv[i]
        if (!isPositiveInteger(std::string(argv[i])))
            return (printErrorAndExit());
        for (int j = 1; j < i; ++j) {
            if (std::string(argv[j]) == std::string(argv[i]))
                return (printErrorAndExit());
        }
        // inserts in list
        inputArgs.push_back(atoi(argv[i]));
    }

    int unpairedElement = 0;
    if ((argc - 1) % 2) {
        unpairedElement = inputArgs.back();
        inputArgs.pop_back();
    }

    printSequence(inputArgs, std::string("Before"));

    // Step 1 - Group the elements of X into ⌊n/2⌋ pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
    std::deque<std::pair<int, int> > deque;
    int a, b;
    for (std::list<int>::iterator it = inputArgs.begin(); it != inputArgs.end(); it++) {
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
    mergeSort(deque, 0, deque.size() - 1);

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

    sortedSequence.push_front(std::pair<int, int>(deque[0].second, 0));
    if (unpairedElement)
        unsortedSequence.push_back(std::pair<int, int>(unpairedElement, index));

    // Step 5 - LETS GO
    // 5.1 - partition into groups and order elements by index in reverse order within their groups
    // 2, 2, 6, 10, 22, 42, 86, etc.
    double n = 1;
    double begin, end, nthTerm;
    begin = 2;
    double elementsLeft = unsortedSequence.size() - 2; // first 2 elements don't count !!
    while (elementsLeft > 0) {
        nthTerm = getNthTerm(n);
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
    unsortedSequence.pop_front();
    unsortedSequence.pop_front();
    while (unsortedSequence.size() > 0) {
        binaryInsert(unsortedSequence[0]);
        unsortedSequence.pop_front();
    }

    assertIsSorted();

    std::cout << "After:\t";
    for (std::deque<std::pair<int, int> >::iterator it = sortedSequence.begin(); it != sortedSequence.end(); it++)
        std::cout << it->first << " ";
    std::cout << "\n";


    return 0;
}
