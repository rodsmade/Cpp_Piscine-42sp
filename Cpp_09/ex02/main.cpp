#include <cstdlib>  // exit()
#include <deque>
#include <iostream>

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

    std::cout << "inseriu " << sequence.size() << " ints\n";


    return 0;
}
