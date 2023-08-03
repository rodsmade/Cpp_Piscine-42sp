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

    // object.sortUsingDeque();

    // assertIsSorted(object.sortedSequence);

    // std::cout << "After Deque:\t";
    // for (std::deque<std::pair<int, int> >::iterator it = object.sortedSequence.begin(); it != object.sortedSequence.end(); it++)
    //     std::cout << it->first << " ";
    // std::cout << "\n";

    object.sortUsingVector();

    assertIsSorted(object.sortedSequenceVector);

    std::cout << "After Vector:\t";
    for (std::vector<std::pair<int, int> >::iterator it = object.sortedSequenceVector.begin(); it != object.sortedSequenceVector.end(); it++)
        std::cout << it->first << " ";
    std::cout << "\n";

    return 0;
}
