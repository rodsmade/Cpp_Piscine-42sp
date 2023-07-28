#include <sys/time.h>

#include <cstdlib>  // exit()
#include <deque>
#include <iostream>
#include <list>

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
}

void mergeSort(std::deque<std::pair<int, int> > &arr, std::deque<int>::size_type left, std::deque<int>::size_type right) {
    if (left < right) {
        std::deque<int>::size_type middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
};

double getNthTerm(double n) {
    // term 1:  2 = 2.
    // term 2:  2 = 2^2 - 2
    // term 3:  6 = 2^3 - (2 ^2 - 2)
    // term 4: 10 = 2^4 - (2ˆ3 - (2 ^2 - 2))
    // term 5: 22 = 2^5 - (2^4 - (2ˆ3 - (2 ^2 - 2)))
    // term 6: 42 = 2^6 - (2^5 - (2^4 - (2ˆ3 - (2 ^2 - 2))))
    // term 7: 86 = 2^7 - (2^6 - (2^5 - (2^4 - (2ˆ3 - (2 ^2 - 2)))))
    if (n == 1)
        return 2;
    else
        return pow(2, n) - getNthTerm(n - 1);
};

std::pair<int, int> getPosition(int value, std::deque<std::pair<int, int> > *sortedSequence) {
    size_t i = 0;
    for (; i < sortedSequence->size(); i++) {
        if ((*sortedSequence)[i].first == value)
            return ((*sortedSequence)[i]);
    }
    return ((*sortedSequence)[--i]);
};

// int storedValue(int index, std::deque<std::pair<int, int> > *sortedSequence) {
//     for (size_t i = 0; i < sortedSequence->size(); i++) {
//         if ((*sortedSequence)[i].second == index)
//             return ((*sortedSequence)[i].first);
//     }
//     return 0;
// };

size_t getIndexInSequenceByTermNumber(int termNumber, std::deque<std::pair<int, int> > *sortedSequence) {
    size_t i = 0;

    while ((*sortedSequence)[i].second != termNumber)
        i++;

    return i;
};

void insertRecursive(int lowerLimit, int upperLimit, int elementToInsert, std::deque<std::pair<int, int> > *sortedSequence) {
    if (elementToInsert < (*sortedSequence)[lowerLimit].first) {
        std::deque<std::pair<int, int> >::iterator it = sortedSequence->begin();
        while (it->first != (*sortedSequence)[lowerLimit].first)
            ++it;
        sortedSequence->insert(it, std::pair<int, int>(elementToInsert, -42));
    }
    else if (elementToInsert > (*sortedSequence)[upperLimit].first) {
        std::deque<std::pair<int, int> >::iterator it = sortedSequence->begin();
        while (it->first != (*sortedSequence)[upperLimit].first)
            ++it;
        ++it;
        sortedSequence->insert(it, std::pair<int, int>(elementToInsert, -42));
    }
    else if (upperLimit - lowerLimit == 1) {
        std::deque<std::pair<int, int> >::iterator it = sortedSequence->begin();
        while (it->first != (*sortedSequence)[upperLimit].first)
            ++it;
        sortedSequence->insert(it, std::pair<int, int>(elementToInsert, -42));
    }
    else {
        int middlePoint = (lowerLimit + upperLimit) / 2;
        if (elementToInsert < (*sortedSequence)[middlePoint].first)
            insertRecursive(lowerLimit, middlePoint, elementToInsert, sortedSequence);
        else
            insertRecursive(middlePoint, upperLimit, elementToInsert, sortedSequence);
    }
};

void binaryInsert(const std::pair<int, int> &element, std::deque<std::pair<int, int> > *sortedSequence) {
    int elementToInsert = element.first;
    int upperLimit = element.second - 1;

    insertRecursive(0, getIndexInSequenceByTermNumber(upperLimit, sortedSequence), elementToInsert, sortedSequence);
    return;
};

int main(int argc, char **argv) {
    if (argc == 1)
        return (printErrorAndExit());

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

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

    int widow = 0;
    if ((argc - 1) % 2) {  // qtd de numeros da sequencia eh impar
        widow = inputArgs.back();
        inputArgs.pop_back();
    }

    gettimeofday(&end_time, NULL);
    // Calculate the elapsed time in microseconds
    long long start_micros = start_time.tv_sec * 1000000LL + start_time.tv_usec;
    long long end_micros = end_time.tv_sec * 1000000LL + end_time.tv_usec;
    long long elapsed_micros = end_micros - start_micros;

    std::cout << "validou e inseriu " << inputArgs.size() << " ints em " << elapsed_micros << " microseconds\n";

    // Step 1 - Group the elements of X into ⌊n/2⌋ pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
    std::deque<std::pair<int, int> > deque;
    int a, b;
    for (std::list<int>::iterator it = inputArgs.begin(); it != inputArgs.end(); it++) {
        a = *(it++);
        b = *it;
        std::pair<int, int> pair(a, b);
        deque.push_back(pair);
    }

    // std::cout << "i now have " << deque.size() << " pairs of numbers\n";
    // std::cout << "first pair is: ";
    // printPair(deque.front());
    // std::cout << "last pair is: ";
    // printPair(deque.back());

    // Step 2 - Perform ⌊ n/2 ⌋ comparisons, one per pair, to determine the larger of the two elements in each pair.
    for (std::deque<std::pair<int, int> >::iterator it = deque.begin(); it != deque.end(); it++) {
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }

    // Step 3 - Recursively sort the ⌊n/2⌋ larger elements from each pair, creating a sorted sequence S of ⌊n/2⌋ of the input elements, in ascending order.
    // std::cout << "before sorting\n";
    // for (std::deque<std::pair<int, int> >::iterator it = deque.begin(); it != deque.end(); it++)
    //     printPair(*it);
    mergeSort(deque, 0, deque.size() - 1);

    std::cout << "sorted by first element maybe we shall see\n";
    for (std::deque<std::pair<int, int> >::iterator it = deque.begin(); it != deque.end(); it++)
        printPair(*it);

    std::deque<std::pair<int, int> > largerElementsSequence;
    std::deque<std::pair<int, int> > unsortedElementsSequence;
    unsortedElementsSequence.push_back(std::pair<int, int>(0, 0));
    unsortedElementsSequence.push_back(std::pair<int, int>(0, 1));

    std::deque<std::pair<int, int> >::iterator it = deque.begin();
    int index = 1;
    largerElementsSequence.push_back(std::pair<int, int>(it->first, index));
    it++;
    index++;
    for (; it != deque.end(); it++) {
        largerElementsSequence.push_back(std::pair<int, int>(it->first, index));
        unsortedElementsSequence.push_back(std::pair<int, int>(it->second, index));
        index++;
    }

    // Step 4 - Insert at the start of S the element that was paired with the first and smallest element of S
    largerElementsSequence.push_front(std::pair<int, int>(deque[0].second, 0));
    if (widow)
        unsortedElementsSequence.push_back(std::pair<int, int>(widow, index));

    std::cout << "sequence of largers final passo 4:\n";
    for (std::deque<std::pair<int, int> >::iterator it = largerElementsSequence.begin(); it != largerElementsSequence.end(); it++)
        std::cout << "[" << it->second << "] " << it->first << std::endl;
    std::cout << "sequence of unsorted final passo 4:\n";
    for (std::deque<std::pair<int, int> >::iterator it = unsortedElementsSequence.begin(); it != unsortedElementsSequence.end(); it++)
        std::cout << "[" << it->second << "] " << it->first << std::endl;

    // Step 5 - LETS GO
    // 5.1 - partition into groups
    // 2, 2, 6, 10, 22, 42, 86,
    // int totalUnsortedElements = unsortedElementsSequence.size() - 2;

    // 5.2 - order elements by index in reverse order within their groups
    // std::reverse(first, last);
    double n = 1;
    double term, begin, end;
    begin = 2;
    double sequenceSize = unsortedElementsSequence.size();
    while (sequenceSize > 0) {
        end = begin + getNthTerm(n);
        term = getNthTerm(n);
        std::reverse(&unsortedElementsSequence[begin], &unsortedElementsSequence[end]);
        n++;
        begin = end;
        sequenceSize -= term;
    }

    std::cout << "TESTE 123\n";

    // std::cout << "sequence of unsorted revertido por subgrupo:\n";
    // for (std::deque<std::pair<int, int> >::iterator it = unsortedElementsSequence.begin(); it != unsortedElementsSequence.end(); it++)
    //     std::cout << "[" << it->second << "] " << it->first << std::endl;
    
    // 5.3 - insert elements into S. use binary search from the start of S up to but not including xi to determine where to insert yi.
    unsortedElementsSequence.pop_front();
    unsortedElementsSequence.pop_front();
    while (unsortedElementsSequence.size() > 0) {
        std::deque<std::pair<int, int> > *ponteiro = &largerElementsSequence;
        binaryInsert(unsortedElementsSequence[0], ponteiro);
        unsortedElementsSequence.pop_front();
    }

    std::cout << "sequence of sorted final:\n";
    for (std::deque<std::pair<int, int> >::iterator it = largerElementsSequence.begin(); it != largerElementsSequence.end(); it++)
        std::cout << "[" << it->second << "] " << it->first << std::endl;

    return 0;
}
