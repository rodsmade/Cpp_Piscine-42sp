#include <iostream>

bool does_not_have_exactly_one_argument(int argc) {
    return (argc != 2);
}

bool has_unprintable_characters(char *arg) {
    int i = -1;

    while (arg[++i])
        if (std::isprint(arg[i]) == 0)
            return (true);
    return (false);
}

int main(int argc, char *argv[]) {
    if (does_not_have_exactly_one_argument(argc)) {
        std::cout << "Provide exactly one argument, e.g.: ./convert 42.0f" << std::endl;
        return (-42);
    }
    if (has_unprintable_characters(argv[1])) {
        std::cout << "Argument has unprintable character in it, come on!" << std::endl;
        return (-42);
    }
    


    return 0;
}