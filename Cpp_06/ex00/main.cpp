#include "ConvertedNumber.hpp"

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

bool isNumericString(std::string argument) {
    int i;

    (argument[0] == '-') ? i = 0 : i = -1;
    while (argument[++i]) {
        if (!std::isdigit(argument[i]))
            return (false);
    }
    return (true);
}

bool isValidIntValue(std::string argument) {
    long temp = std::atol(argument.c_str());
    if (temp > INT_MAX || temp < INT_MIN) {
        return (false);
    }
    return (true);
}

bool isSpecialNumericValue(std::string argument) {
    return (argument == "nan" || argument == "nanf" || argument == "inf" ||
            argument == "-inf" || argument == "inff" || argument == "-inff");
}

bool isValidDecimal(std::string argument) {
    int i;
    int countDots = 0;
    int countFs = 0;

    // Checa se o formato tá minimamente dentro do esperado (apenas 1 '.', podendo terminar em f)
    // pra evitar "modo C" de fazer isso precisa de uma função em <algorithms> q é proibida então . . .
    (argument[0] == '-') ? i = 0 : i = -1;
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
    (argument[0] == '-') ? i = 0 : i = -1;
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
    if (argument.size() == 1 && !std::isdigit(argument[0])) {
        // aqui já sei de antemão que não é "" e que é printável; não sendo dígito, logo é char
        return ("char");
    } else if (isNumericString(argument) && isValidIntValue(argument)) {
        return ("int");
    } else if (argument.size() > 1 && (isSpecialNumericValue(argument) || isValidDecimal(argument))) {
        if (endsInF(argument) && argument != "inf" && argument != "-inf")
            return ("float");
        else
            return ("double");
    }
    std::cout << "Provide either one char, an int, a double or a float - don't forget the decimal point and at least one decimal place for decimals, e.g. 42.0, also make sure int is within the interval [INT_MIN, INT_MAX]" << std::endl;
    exit(-42);
}

std::string validateInput(int argc, char *argv1) {
    if (doesNotHaveExactlyOneArgument(argc)) {
        std::cout << "Provide exactly one argument, e.g.: ./convert 42.0f" << std::endl;
        exit(-42);
    }
    if (hasUnprintableCharacters(argv1)) {
        std::cout << "Argument has unprintable character in it, come on!" << std::endl;
        exit(-42);
    }
    if (isEmptyString(argv1)) {
        std::cout << "Argument is empty. I'm watching you 👀" << std::endl;
        exit(-42);
    }

    return (std::string(argv1));
}

/*
    TODO:
    + tratar casos de max e min float/double
*/
int main(int argc, char *argv[]) {
    std::string argument = validateInput(argc, argv[1]);
    std::string originalType = decideOriginalType(argument);

    ConvertedNumber convertedNumber = ConvertedNumber(originalType, argument);

    convertedNumber.printNumberInAllFormats();

    return 0;
}