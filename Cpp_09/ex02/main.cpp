#include <cstdlib>  // exit()
#include <deque>
#include <iostream>
#include <list>
#include <sys/time.h>
#include <vector>

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

void    printPair(std::pair<int, int> pair) {
    std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
};

int printErrorAndExit() {
    std::cout << "Error" << std::endl;
    return (EXIT_FAILURE);
};


int main(int argc, char **argv) {
    if (argc == 1)
        return (printErrorAndExit());

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    std::list<int> sequence;
    for (int i = 1; i < argc; i++) {
        // checks validity of argv[i]
        if (!isPositiveInteger(std::string(argv[i])))
            return (printErrorAndExit());
        for (int j = 1; j < i; ++j) {
            if (std::string(argv[j]) == std::string(argv[i]))
                return (printErrorAndExit());
        }
        // inserts in list
        sequence.push_back(atoi(argv[i]));
    }

    gettimeofday(&end_time, NULL);
    // Calculate the elapsed time in microseconds
    long long start_micros = start_time.tv_sec * 1000000LL + start_time.tv_usec;
    long long end_micros = end_time.tv_sec * 1000000LL + end_time.tv_usec;
    long long elapsed_micros = end_micros - start_micros;

    std::cout << "validou e inseriu " << sequence.size() << " ints em " << elapsed_micros << " microseconds\n";

    // Step 1 - Group the elements of X into ⌊n/2⌋ pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
    std::deque<std::pair<int, int> > deque;
    int a, b;
    for (std::list<int>::iterator it = sequence.begin(); it != sequence.end(); it++) {
        a = *(it++);
        b = (it != sequence.end()) ? *it : 0;
        std::pair<int, int> pair(a, b);
        deque.push_back(pair);
        if (it == sequence.end())
            break;
    }

    std::cout << "i now have " << deque.size() << " pairs of numbers\n";
    std::cout << "first pair is: ";
    printPair(deque.front());
    std::cout << "last pair is: ";
    printPair(deque.back());

    // Step 2 - Perform ⌊ n/2 ⌋ comparisons, one per pair, to determine the larger of the two elements in each pair.
    for (std::deque<std::pair<int, int> >::iterator it = deque.begin(); it != deque.end(); it++) {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }

    // Step 3 - Recursively sort the ⌊n/2⌋ larger elements from each pair, creating a sorted sequence S of ⌊n/2⌋ of the input elements, in ascending order.
    

    return 0;
}

