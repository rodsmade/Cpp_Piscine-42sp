#include <ctype.h>

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

bool doesNotHaveExactlyOneArgument(int argc) {
    return (argc != 2);
}

bool hasUnprintableCharacters(char *arg) {
    int i = -1;

    while (arg[++i])
        if (std::isprint(arg[i]) == 0)
            return (true);
    return (false);
}

bool isEmptyString(char *arg) {
    std::string argStr = arg;

    if (argStr.size() == 0) {
        return (true);
    };
    return (false);
}

std::string decideOriginalType(std::string argument) {
    if (argument.size() == 1) {
        // aqui sei que é printable (testei na main)
        return ("char");
    } else if (argument.size() > 1 && ((argument.find('.') != std::string::npos && std::isdigit(argument[argument.find('.') + 1])) || argument.compare("nan") == 0 || argument.compare("nanf") == 0)) {
        if (argument[argument.size() - 1] == 'f')
            return ("float");
        else
            return ("double");
    }
    return ("undefined");
}

int main(int argc, char *argv[]) {
    if (doesNotHaveExactlyOneArgument(argc)) {
        std::cout << "Provide exactly one argument, e.g.: ./convert 42.0f" << std::endl;
        return (-42);
    }
    if (hasUnprintableCharacters(argv[1])) {
        std::cout << "Argument has unprintable character in it, come on!" << std::endl;
        return (-42);
    }
    if (isEmptyString(argv[1])) {
        std::cout << "Argument is empty. I'm watching you 👀" << std::endl;
        return (-42);
    }

    // std::string string1 = "nanf";
    // std::string string2 = "nan";
    // std::cout << (string1.compare(string2)) << std::endl; // returns 0 if equivalent

    std::string argument = argv[1];
    std::string originalType = decideOriginalType(argument);

    std::cout << "Argument type is: " << originalType << std::endl;

    // float f = std::atof(argv[1]);
    // // Set the number of decimal places to 1 and enable fixed-point notation
    // std::cout << std::fixed << std::setprecision(1);
    // // Print the float with a decimal point and trailing zeros
    // std::cout << "The float value is: " << f << "f" << std::endl;

    return 0;
}