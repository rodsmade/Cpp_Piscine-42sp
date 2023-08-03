#include "PmergeMe.hpp"

/*==============================================================================
===  CONSTRUCTION / DESTRUCTION                                              ===
==============================================================================*/
PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "argc: " << argc << std::endl;
        throw std::exception();
    }
    
    for (int i = 1; i < argc; i++) {
        // checks validity of argv[i]
        if (!_isPositiveInteger(std::string(argv[i]))) {
            std::cout << "not positive integer\n";
            throw std::exception();
        }
        for (int j = 1; j < i; ++j) {
            if (std::string(argv[j]) == std::string(argv[i])) {
                std::cout << "duplicate\n";
                throw std::exception();
            }
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

/*==============================================================================
===  OPERATOR OVERLOADS                                                      ===
==============================================================================*/
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    _inputArgs = other._inputArgs;
    return *this;
};

/*==============================================================================
===  GETTERS/SETTERS                                                         ===
==============================================================================*/
std::list<int> &PmergeMe::getInputArgs() {
    return (_inputArgs);
};

int &PmergeMe::getOddOneOut() {
    return (_oddOneOut);
};

/*==============================================================================
===  PRIVATE FUNCTIONS                                                       ===
==============================================================================*/
// General use
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
