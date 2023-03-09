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

bool isValidDecimal(std::string argument) {
    int i = -1;
    int countDots = 0;
    int countFs = 0;

    // Checa se o formato tá minimamente dentro do esperado (apenas 1 '.', podendo terminar em f)
    // pra evitar "modo C" de fazer isso precisa de uma função em <algorithms> q é proibida então . . .
    while (argument[++i]) {
        if (argument[i] == '.') {
            countDots++;
        };
        if (argument[i] == 'f') {
            countFs++;
        };
    }
    if (countDots != 1 || countFs > 1)
        return (false);

    // Checa se tem somente dígitos ou '.' dentro
    i = -1;
    while (argument[++i]) {
        if (!std::isdigit(argument[i]) && argument[i] != '.' && argument[i] != 'f')
            return (false);
    }

    // Checa se tem ao menos uma casa decimal depois do ponto
    if (!std::isdigit(argument[argument.find('.') + 1]))
        return (false);

    return (true);
}

bool endsInF(std::string argument) {
    return (argument[argument.size() - 1] == 'f');
}

std::string decideOriginalType(std::string argument) {
    if (argument.size() == 1) {
        // aqui sei que é printable (testei na main)
        return ("char");
    } else if (argument.size() > 1 && (isValidDecimal(argument) || argument.compare("nan") == 0 || argument.compare("nanf") == 0)) {
        if (endsInF(argument))
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

    std::string argument = argv[1];
    std::string originalType = decideOriginalType(argument);

    if (originalType.compare("undefined") == 0) {
        std::cout << "Provide either one char, a double or a float - don't forget the decimal point and at least one decimal place for decimals, e.g. 42.0" << std::endl;
        return (-42);
    }

    std::cout << "Argument type is: " << originalType << std::endl;

    // float f = std::atof(argv[1]);
    // // Set the number of decimal places to 1 and enable fixed-point notation
    // std::cout << std::fixed << std::setprecision(1);
    // // Print the float with a decimal point and trailing zeros
    // std::cout << "The float value is: " << f << "f" << std::endl;

    return 0;
}