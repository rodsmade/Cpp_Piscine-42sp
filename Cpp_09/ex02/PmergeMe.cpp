#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(int argc, char **argv) {
    if (argc < 2)
        throw std::exception();
    
    for (int i = 1; i < argc; i++) {
        // checks validity of argv[i]
        if (!_isPositiveInteger(std::string(argv[i])))
            throw std::exception();
        for (int j = 1; j < i; ++j) {
            if (std::string(argv[j]) == std::string(argv[i]))
                throw std::exception();
        }
        // inserts in list
        _inputArgs.push_back(atoi(argv[i]));
    }

};

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &other) {
    _inputArgs = other._inputArgs;
};

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    _inputArgs = other._inputArgs;
    return *this;
};

std::list<int> &PmergeMe::getInputArgs() {
    return (_inputArgs);
};

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
