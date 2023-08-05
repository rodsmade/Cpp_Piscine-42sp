#include "PmergeMe.hpp"

template <typename C>
void printSequence(C &sequence, std::string state) {
    std::cout << state << ":\t";
    for (typename C::iterator it = sequence.begin(); it != sequence.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
};

template <typename C>
void assertIsSorted(C &sequence) {
    bool isSorted = true;

    for (typename C::size_type i = 0; i < sequence.size() - 1; i++)
        isSorted = isSorted && (sequence[i].first < sequence[i + 1].first);

    assert(isSorted);
}

int main(int argc, char **argv) {
    PmergeMe object;
    try {
        object = PmergeMe(argc, argv);
    } catch(const std::exception& e) {
        std::cerr << "Error\n";
        return (EXIT_FAILURE);
    }

    printSequence(object.getInputArgs(), std::string("Before"));

    // TIMER
    struct timeval start_time, end_time;
    long long elapsed_micros_deque, elapsed_micros_vector;

    gettimeofday(&start_time, NULL);
    object.sortUsingDeque();
    gettimeofday(&end_time, NULL);

    assertIsSorted(object.sortedSequence);
    elapsed_micros_deque = (end_time.tv_sec * 1000000LL + end_time.tv_usec) - (start_time.tv_sec * 1000000LL + start_time.tv_usec);

    gettimeofday(&start_time, NULL);
    object.sortUsingVector();
    gettimeofday(&end_time, NULL);

    assertIsSorted(object.sortedSequenceVector);
    elapsed_micros_vector = (end_time.tv_sec * 1000000LL + end_time.tv_usec) - (start_time.tv_sec * 1000000LL + start_time.tv_usec);

    std::cout << "After:\t";
    for (std::deque<std::pair<int, int> >::iterator it = object.sortedSequence.begin(); it != object.sortedSequence.end(); it++)
        std::cout << it->first << " ";
    std::cout << "\n";

    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::deque : " << elapsed_micros_deque << " us" << std::endl;
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::vector : " << elapsed_micros_vector << " us" << std::endl;

    return 0;
}
