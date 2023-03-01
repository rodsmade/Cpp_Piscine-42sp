#include "Bureaucrat.hpp"

#define BOLD "\033[1m"
#define ORANGE "\033[38;2;255;165;0m"
#define VIOLET "\033[38;2;75;0;130m"
#define DARK_GRAY "\033[90m"
#define BG_LIGHT_YELLOW "\033[103m"
#define LIGHT_GREEN "\033[92m"
#define LIGHT_YELLOW "\033[93m"
#define LIGHT_BLUE "\033[94m"
#define LIGHT_CYAN "\033[96m"
#define LIGHT_MAGENTA "\033[95m"
#define LIGHT_RED "\033[91m"
#define RESET "\033[0m"

#include <sstream>

#define toString(x) static_cast<std::ostringstream&>(            \
                        (std::ostringstream() << std::dec << x)) \
                        .str()

bool test00_createProperFormShouldNotRaiseException(void) {
    try {
        // criar form certo
        Form permitirAdmissao = Form("Formulário de Admissão", 100, 50);
        std::cout << permitirAdmissao << std::endl;
        return (true);
    } catch (const std::exception& e) {
        return (false);
    }
};

bool test01_copyProperFormShouldNotRaiseException(void) {
    Form permitirAdmissao = Form("Formulário de Admissão", 100, 50);

    try {
        // copiar form certo
        Form copia1(permitirAdmissao);
        return (true);
    } catch (const std::exception& e) {
        return (false);
    }
};

bool test02_assignProperFormShouldNotRaiseException(void) {
    Form permitirAdmissao = Form("Formulário de Admissão", 100, 50);

    try {
        // designar form certo
        Form copia2 = permitirAdmissao;
        return (true);
    } catch (const std::exception& e) {
        return (false);
    }
};

bool test03_printProperFormShouldMatchSpecificString(void) {
    std::string formName = "Admission";
    int formGradeToSign = 100;
    int formGradeToExecute = 50;
    std::string formGradeToSignStr = "100";
    std::string formGradeToExecuteStr = "50";
    Form permitirAdmissao = Form(formName, formGradeToSign, formGradeToExecute);

    std::string expectedOutput = formName + " form is not signed and needs grade " + formGradeToSignStr + " to be signed and grade " + formGradeToExecuteStr + " to be executed.";
    std::string obtainedOutput = permitirAdmissao;

    if (obtainedOutput == expectedOutput) {
        return (true);
    } else {
        return (false);
    }
};

bool test04_createWrongFormWithHighSignatureGradeShouldRaiseGradeTooHighException(void) {
    try {
        Form wrongForm("Admission", -42, 50);
    } catch (const Form::GradeTooHighException& e) {
        return (true);
    };
    return (false);
};

bool test05_createWrongFormWithLowSignatureGradeShouldRaiseGradeTooLowException(void) {
    try {
        Form wrongForm("Admission", 420, 50);
    } catch (const Form::GradeTooLowException& e) {
        return (true);
    };
    return (false);
};

bool test06_createWrongFormWithHighExecutionGradeShouldRaiseGradeTooLowException(void) {
    try {
        Form wrongForm("Admission", 42, -50);
    } catch (const Form::GradeTooHighException& e) {
        return (true);
    };
    return (false);
};

bool test07_createWrongFormWithLowExecutionGradeShouldRaiseGradeTooLowException(void) {
    try {
        Form wrongForm("Admission", 42, 420);
    } catch (const Form::GradeTooLowException& e) {
        return (true);
    };
    return (false);
};

int main() {
    int totalTests = 8;
    bool (*testFunctions[totalTests])();

    testFunctions[0] = test00_createProperFormShouldNotRaiseException;
    testFunctions[1] = test01_copyProperFormShouldNotRaiseException;
    testFunctions[2] = test02_assignProperFormShouldNotRaiseException;
    testFunctions[3] = test03_printProperFormShouldMatchSpecificString;
    testFunctions[4] = test04_createWrongFormWithHighSignatureGradeShouldRaiseGradeTooHighException;
    testFunctions[5] = test05_createWrongFormWithLowSignatureGradeShouldRaiseGradeTooLowException;
    testFunctions[6] = test06_createWrongFormWithHighExecutionGradeShouldRaiseGradeTooLowException;
    testFunctions[7] = test07_createWrongFormWithLowExecutionGradeShouldRaiseGradeTooLowException;

    for (int i = 0; i < totalTests; ++i) {
        std::string iToString = toString(i);
        if (i < 10) {
            iToString = "0" + iToString;
        };

        if (!testFunctions[i]()) {
            std::cout << LIGHT_RED "Test" << iToString << ": " BOLD "[NOK]" RESET RESET << std::endl;
        } else {
            std::cout << LIGHT_GREEN "Test" << iToString << ": " BOLD "[OK]" RESET RESET << std::endl;
        }
    }


    // // criar form com execute grade mais alta
    // try {
    //     Form formErrado1("Formulário de Admissão", 100, -50);
    // } catch (const Form::GradeTooHighException& e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // };

    // // criar form com execute grade mais baixa
    // try {
    //     Form formErrado1("Formulário de Admissão", 100, 500);
    // } catch (const Form::GradeTooHighException& e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // };

    // // criar um burocrata
    // Bureaucrat bureaucrat("Soninha", 10);
    // // be signed por um burocrata com exatamente o nivel
    // // be signed por um burocrata como nivel mais alto

    // // try catch
    // // be signed por um burocrata como nivel mais baixo

    return 0;
}
