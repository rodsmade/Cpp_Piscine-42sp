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

int printErrorAndExit() {
    std::cout << "Error" << std::endl;
    return (EXIT_FAILURE);
};


int main(int argc, char **argv) {
    if (argc == 1)
        return (printErrorAndExit());

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    std::deque<int> sequence;
    for (int i = 1; i < argc; i++) {
        // checks validity of argv[i]
        if (!isPositiveInteger(std::string(argv[i])))
            return (printErrorAndExit());
        for (int j = 1; j < i; ++j) {
            if (std::string(argv[j]) == std::string(argv[i]))
                return (printErrorAndExit());
        }
        // inserts in deque
        sequence.push_back(atoi(argv[i]));
    }

    gettimeofday(&end_time, NULL);
    // Calculate the elapsed time in microseconds
    long long start_micros = start_time.tv_sec * 1000000LL + start_time.tv_usec;
    long long end_micros = end_time.tv_sec * 1000000LL + end_time.tv_usec;
    long long elapsed_micros = end_micros - start_micros;

    std::cout << "validou e inseriu " << sequence.size() << " ints em " << elapsed_micros << " microseconds\n";

    // Step 1 - Group the elements of X into ⌊n/2⌋ pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
    std::list<std::pair<int, int> > list;
    int a, b;
    for (std::deque<int>::iterator it = sequence.begin(); it != sequence.end(); it++) {
        a = *(it++);
        b = (it != sequence.end()) ? *it : 0;
        std::pair<int, int> pair(a, b);
        list.push_back(pair);
        if (it == sequence.end())
            break;
    }

    std::cout << "i now have " << list.size() << " pairs of numbers\n";
    std::cout << "first pair is (" << list.front().first << ", " << list.front().second << ")\n";
    std::cout << "last pair is (" << list.back().first << ", " << list.back().second << ")\n";



    return 0;
}
