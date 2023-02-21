#include <iostream>
#include <string>
#include <time.h>

void print_canvas(int NUM_LINES, int NUM_COLUMNS) {
    // Print 20 lines of "-" characters
    for (int i = 0; i < NUM_LINES; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            std::cout << "- ";
        }
        std::cout << std::endl;
    }

};

int main() {
    const int NUM_LINES = 20;
    const int NUM_COLUMNS = 20;
    const float FRAME_RATE = 0.5f;
    clock_t start_time;

    print_canvas(NUM_LINES, NUM_COLUMNS);

    // Move cursor to the start of the first line and overwrite it with the new text
    std::cout << "\033[" << NUM_LINES << "A"; // Move cursor up NUM_LINES lines
    std::cout << "\033[0G"; // Move cursor to the start of the line

    //  Wait 2 seconts
    start_time = clock();
    while (static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC < FRAME_RATE);
    
    // Print the new text
    for (int i = 0; i < NUM_LINES; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            if (i == j) {
                std::cout << "x ";
            } else {
                std::cout << "- ";
            }
        }
        std::cout << "\n";
    }

    // Move cursor to the start of the first line and overwrite it with the new text
    std::cout << "\033[" << NUM_LINES << "A"; // Move cursor up NUM_LINES lines
    std::cout << "\033[0G"; // Move cursor to the start of the line

    //  Wait 2 seconts
    start_time = clock();
    while (static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC < FRAME_RATE);
    
    // Print the new text
    for (int i = 0; i < NUM_LINES; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            if (j == 5) {
                std::cout << "x ";
            } else {
                std::cout << "- ";
            }
        }
        std::cout << "\n";
    }

    // Move cursor to the start of the first line and overwrite it with the new text
    std::cout << "\033[" << NUM_LINES << "A"; // Move cursor up NUM_LINES lines
    std::cout << "\033[0G"; // Move cursor to the start of the line

    //  Wait 2 seconts
    start_time = clock();
    while (static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC < FRAME_RATE);
    
    // Print the new text
    for (int i = 0; i < NUM_LINES; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            if (i == 17) {
                std::cout << "x ";
            } else {
                std::cout << "- ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}