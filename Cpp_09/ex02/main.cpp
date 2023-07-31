#include "PmergeMe.hpp"

template <typename C>
void printSequence(C &sequence, std::string state) {
    std::cout << state << ":\t";
    for (typename C::iterator it = sequence.begin(); it != sequence.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
};

void assertIsSorted(std::deque<std::pair<int, int> > &sequence) {
    bool isSorted = true;

    for (size_t i = 0; i < sequence.size() - 1; i++)
        isSorted = isSorted && (sequence[i] < sequence[i + 1]);

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

    object.sortUsingDeque();

    assertIsSorted(object.sortedSequence);

    std::cout << "After:\t";
    for (std::deque<std::pair<int, int> >::iterator it = object.sortedSequence.begin(); it != object.sortedSequence.end(); it++)
        std::cout << it->first << " ";
    std::cout << "\n";


    return 0;
}
