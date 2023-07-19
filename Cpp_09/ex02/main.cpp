#include <cstdlib>  // exit()
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

#include <set>

int main(int argc, char **argv) {
    if (argc == 1)
        return (printErrorAndExit());

    std::set<int> sequence;
    for (int i = 1; i < argc; i++) {
        // checks validity of argv[i]
        if (!isPositiveInteger(std::string(argv[i])))
            return (printErrorAndExit());
        // inserts in set, if duplicate, halts execution
        if (sequence.insert(std::atoi(argv[i])).second == false)
            return (printErrorAndExit());
    }

    std::cout << "inseriu " << sequence.size() << " ints\n";
    return 0;
}
