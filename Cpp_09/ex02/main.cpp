#include "PmergeMe.hpp"

template <typename C>
void assertIsSorted(C &sequence) {
    bool isSorted = true;

    for (typename C::size_type i = 0; i < sequence.size() - 1; i++)
        isSorted = isSorted && (sequence[i].first < sequence[i + 1].first);

    assert(isSorted);
}

/**
 * Esse é o código mais seboso que eu já fiz na vida. Perdão.
*/
int main(int argc, char **argv) {
    PmergeMe mergeInsertSorter;
    try {
        mergeInsertSorter = PmergeMe(argc, argv);
    } catch(const std::exception& e) {
        std::cerr << "Error\n";
        return (EXIT_FAILURE);
    }

    std::cout << "Before:\t";
    for (std::list<int>::iterator it = mergeInsertSorter.getInputArgs().begin(); it != mergeInsertSorter.getInputArgs().end(); it++) {
        std::cout << *it << " ";
    }
    if (mergeInsertSorter.getOddOneOut())
        std::cout << mergeInsertSorter.getOddOneOut();
    std::cout << std::endl;

    // TIMER
    struct timeval start_time, end_time;
    long long elapsed_micros_deque, elapsed_micros_vector;

    gettimeofday(&start_time, NULL);
    mergeInsertSorter.sortUsingDeque();
    gettimeofday(&end_time, NULL);

    assertIsSorted(mergeInsertSorter.sortedSequence);
    elapsed_micros_deque = (end_time.tv_sec * 1000000LL + end_time.tv_usec) - (start_time.tv_sec * 1000000LL + start_time.tv_usec);

    gettimeofday(&start_time, NULL);
    mergeInsertSorter.sortUsingVector();
    gettimeofday(&end_time, NULL);

    assertIsSorted(mergeInsertSorter.sortedSequenceVector);
    elapsed_micros_vector = (end_time.tv_sec * 1000000LL + end_time.tv_usec) - (start_time.tv_sec * 1000000LL + start_time.tv_usec);

    std::cout << "After:\t";
    for (std::deque<std::pair<int, int> >::iterator it = mergeInsertSorter.sortedSequence.begin(); it != mergeInsertSorter.sortedSequence.end(); it++)
        std::cout << it->first << " ";
    std::cout << "\n";

    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::deque : " << elapsed_micros_deque << " us" << std::endl;
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::vector : " << elapsed_micros_vector << " us" << std::endl;

    return 0;
}
