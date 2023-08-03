#include "PmergeMe.hpp"

template <typename Container>
std::string listToString(Container &sequence) {
    std::string concatenatedSequence("");

    for (typename Container::iterator it = sequence.begin(); it != sequence.end(); it++) {
        std::stringstream ss;
        ss << *it;
        concatenatedSequence += ss.str();
        concatenatedSequence += " ";
    }
    return concatenatedSequence;
};

template <typename Container>
std::string containerToString(Container &sequence) {
    std::string concatenatedSequence("");

    for (typename Container::iterator it = sequence.begin(); it != sequence.end(); it++) {
        std::stringstream ss;
        ss << it->first;
        concatenatedSequence += ss.str();
        concatenatedSequence += " ";
    }
    return concatenatedSequence;
};

template <typename Container>
void assertIsSorted(Container &sequence) {
    bool isSorted = true;

    for (typename Container::size_type i = 0; i < sequence.size() - 1; i++)
        isSorted = isSorted && (sequence[i].first < sequence[i + 1].first);

    assert(isSorted);
}

int main(int argc, char **argv) {
    PmergeMe object;
    // try {
    object = PmergeMe(argc, argv);
    // } catch(const std::exception& e) {
        // std::cerr << "Error\n";
        // return (EXIT_FAILURE);
    // }

    std::cout << "Before:\t" << listToString(object.getInputArgs()) << std::endl;

    struct timeval start_time, end_time;
    long long start_micros;
    long long end_micros;
    long long elapsed_micros;

    gettimeofday(&start_time, NULL);

    std::deque<std::pair<int, int> > dequeGeneric = object.mergeInsertionSort<std::deque<std::pair<int, int> > >();

    gettimeofday(&end_time, NULL);

    start_micros = start_time.tv_sec * 1000000LL + start_time.tv_usec;
    end_micros = end_time.tv_sec * 1000000LL + end_time.tv_usec;
    elapsed_micros = end_micros - start_micros;

    std::cout << "After:\t" << containerToString(dequeGeneric) << std::endl;

    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::deque : " << elapsed_micros << " microseconds." << std::endl;

    gettimeofday(&start_time, NULL);
    
    std::vector<std::pair<int, int> > vectorGeneric = object.mergeInsertionSort<std::vector<std::pair<int, int> > >();

    gettimeofday(&end_time, NULL);

    start_micros = start_time.tv_sec * 1000000LL + start_time.tv_usec;
    end_micros = end_time.tv_sec * 1000000LL + end_time.tv_usec;
    elapsed_micros = end_micros - start_micros;

    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::vector : " << elapsed_micros << " microseconds." << std::endl;

    assertIsSorted(dequeGeneric);
    assertIsSorted(vectorGeneric);

    return 0;
}
