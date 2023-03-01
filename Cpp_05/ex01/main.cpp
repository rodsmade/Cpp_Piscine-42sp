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

bool test00_createProperFormShouldNotRaiseException(void) {
    try {
        // criar form certo
        Form admissionForm = Form("Admission", 100, 50);
        return (true);
    } catch (const std::exception& e) {
        return (false);
    }
};

bool test01_copyProperFormShouldNotRaiseException(void) {
    Form admissionForm = Form("Admission", 100, 50);

    try {
        // copiar form certo
        Form copia1(admissionForm);
        return (true);
    } catch (const std::exception& e) {
        return (false);
    }
};

bool test02_assignProperFormShouldNotRaiseException(void) {
    Form admissionForm = Form("Admission", 100, 50);

    try {
        // designar form certo
        Form copia2 = admissionForm;
        return (true);
    } catch (const std::exception& e) {
        return (false);
    }
};

bool test03_printProperFormShouldMatchSpecificString(void) {
    // Arrange
    std::string formName = "Admission";
    int formGradeToSign = 100;
    int formGradeToExecute = 50;
    std::string formGradeToSignStr = "100";
    std::string formGradeToExecuteStr = "50";
    Form admissionForm = Form(formName, formGradeToSign, formGradeToExecute);
    std::string expectedOutput = formName +
                                 " form is not signed and needs grade " +
                                 formGradeToSignStr +
                                 " to be signed and grade " +
                                 formGradeToExecuteStr +
                                 " to be executed.";

    // Act
    std::stringstream ss;
    ss << admissionForm;
    std::string obtainedOutput = ss.str();

    // Assert
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

bool test08_beSignedByBureaucratWithExactGradeNeededShouldNotRaiseException(void) {
    Bureaucrat soninha("Soninha", 10);
    std::string formName = "Admission";
    int formGradeToSign = 10;
    int formGradeToExecute = 50;
    Form admissionForm = Form(formName, formGradeToSign, formGradeToExecute);
    try {
        admissionForm.beSigned(soninha);
        return (true);
    } catch (const std::exception& e) {
        return (false);
    }
};

bool test09_beSignedByBureaucratWithHigherGradeThanNeededShouldNotRaiseException(void) {
    Bureaucrat soninha("Soninha", 2);
    std::string formName = "Admission";
    int formGradeToSign = 10;
    int formGradeToExecute = 50;
    Form admissionForm = Form(formName, formGradeToSign, formGradeToExecute);
    try {
        admissionForm.beSigned(soninha);
        return (true);
    } catch (const std::exception& e) {
        return (false);
    }
};

bool test10_beSignedByBureaucratWithLowerGradeThanNeededShouldRaiseGradeTooLowException(void) {
    Bureaucrat soninha("Soninha", 20);
    std::string formName = "Admission";
    int formGradeToSign = 10;
    int formGradeToExecute = 50;
    Form admissionForm = Form(formName, formGradeToSign, formGradeToExecute);
    try {
        admissionForm.beSigned(soninha);
        return (false);
    } catch (const Form::GradeTooLowException& e) {
        return (true);
    } catch (const std::exception& e) {
        return (false);
    }
};

int main() {
    int totalTests = 11;
    bool (*testFunctions[totalTests])();
    std::string testFunctionsNames[totalTests];

    testFunctions[0] = test00_createProperFormShouldNotRaiseException;
    testFunctionsNames[0] = "test00_createProperFormShouldNotRaiseException";
    testFunctions[1] = test01_copyProperFormShouldNotRaiseException;
    testFunctionsNames[1] = "test01_copyProperFormShouldNotRaiseException";
    testFunctions[2] = test02_assignProperFormShouldNotRaiseException;
    testFunctionsNames[2] = "test02_assignProperFormShouldNotRaiseException";
    testFunctions[3] = test03_printProperFormShouldMatchSpecificString;
    testFunctionsNames[3] = "test03_printProperFormShouldMatchSpecificString";
    testFunctions[4] = test04_createWrongFormWithHighSignatureGradeShouldRaiseGradeTooHighException;
    testFunctionsNames[4] = "test04_createWrongFormWithHighSignatureGradeShouldRaiseGradeTooHighException";
    testFunctions[5] = test05_createWrongFormWithLowSignatureGradeShouldRaiseGradeTooLowException;
    testFunctionsNames[5] = "test05_createWrongFormWithLowSignatureGradeShouldRaiseGradeTooLowException";
    testFunctions[6] = test06_createWrongFormWithHighExecutionGradeShouldRaiseGradeTooLowException;
    testFunctionsNames[6] = "test06_createWrongFormWithHighExecutionGradeShouldRaiseGradeTooLowException";
    testFunctions[7] = test07_createWrongFormWithLowExecutionGradeShouldRaiseGradeTooLowException;
    testFunctionsNames[7] = "test07_createWrongFormWithLowExecutionGradeShouldRaiseGradeTooLowException";
    testFunctions[8] = test08_beSignedByBureaucratWithExactGradeNeededShouldNotRaiseException;
    testFunctionsNames[8] = "test08_beSignedByBureaucratWithExactGradeNeededShouldNotRaiseException";
    testFunctions[9] = test09_beSignedByBureaucratWithHigherGradeThanNeededShouldNotRaiseException;
    testFunctionsNames[9] = "test09_beSignedByBureaucratWithHigherGradeThanNeededShouldNotRaiseException";
    testFunctions[10] = test10_beSignedByBureaucratWithLowerGradeThanNeededShouldRaiseGradeTooLowException;
    testFunctionsNames[10] = "test10_beSignedByBureaucratWithLowerGradeThanNeededShouldRaiseGradeTooLowException";

    for (int i = 0; i < totalTests; ++i) {
        if (!testFunctions[i]()) {
            std::cout << LIGHT_RED BOLD "[NOK]  " RESET LIGHT_RED << testFunctionsNames[i] << RESET << std::endl;
        } else {
            std::cout << LIGHT_GREEN BOLD "[OK]  " RESET LIGHT_GREEN << testFunctionsNames[i] << RESET << std::endl;
        }
    }

    return 0;
}
