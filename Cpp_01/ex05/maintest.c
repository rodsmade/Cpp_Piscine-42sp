#include <iostream>
using namespace std;

void debug() {
    cout << "Debug message." << endl;
}

void error() {
    cout << "Error message." << endl;
}

void warning() {
    cout << "Warning message." << endl;
}

void info() {
    cout << "Info message." << endl;
}

void printMessage(string type) {
    void (*messagePointers[])() = {debug, error, warning, info};
    string types[] = {"DEBUG", "ERROR", "WARNING", "INFO"};

    for (int i = 0; i < 4; i++) {
        if (type == types[i]) {
            (*messagePointers[i])();
            return;
        }
    }
    cout << "Invalid type" << endl;
}

int main() {
    string type;
    cin >> type;
    printMessage(type);
    return 0;
}