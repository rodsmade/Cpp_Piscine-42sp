#include <time.h>

#include <iostream>
#include <string>

#include "Point.hpp"

const int NUM_LINES = 20;
const int NUM_COLUMNS = 20;
const int NUMBER_OF_PATTERNS = 5;
const float FRAME_RATE = 0.5f;

bool bsp(Point const a, Point const b, Point const c, Point const point);

void printCanvas(void) {
    // Print 20 lines of "-" characters
    for (int i = 0; i < NUM_LINES; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            std::cout << "- ";
        }
        std::cout << std::endl;
    }
};

void waitFrameRateTick(void) {
    //  Wait 2 seconts
    clock_t start_time = clock();
    while (static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC < FRAME_RATE)
        ;
}

void resetCursorPosition(void) {
    // Move cursor to the start of the first line and overwrite it with the new text
    std::cout << "\033[" << NUM_LINES << "A";  // Move cursor up NUM_LINES lines
    std::cout << "\033[0G";                    // Move cursor to the start of the line
};

void printPattern0(void) {
    Point a = Point(9.0f, 17.0f);
    Point b = Point(2.0f, 2.0f);
    Point c = Point(18.0f, 2.0f);

    // Print matrix
    for (int i = 0; i < NUM_LINES; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            Point point(j * 1.0f, (NUM_LINES - i) * 1.0f);
            if (bsp(a, b, c, point))
                std::cout << "O ";
            else
                std::cout << "- ";
        }
        std::cout << std::endl;
    }
};

void printPattern1(void) {
    Point a = Point(2.0f, 12.0f);
    Point b = Point(9.0f, 17.0f);
    Point c = Point(18.0f, 2.0f);

    // Print matrix
    for (int i = 0; i < NUM_LINES; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            Point point(j * 1.0f, (NUM_LINES - i) * 1.0f);
            if (bsp(a, b, c, point))
                std::cout << "O ";
            else
                std::cout << "- ";
        }
        std::cout << std::endl;
    }
};

void printPattern2(void) {
    Point a = Point(2.0f, 2.0f);
    Point b = Point(2.0f, 17.0f);
    Point c = Point(18.0f, 2.0f);

    // Print matrix
    for (int i = 0; i < NUM_LINES; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            Point point(j * 1.0f, (NUM_LINES - i) * 1.0f);
            if (bsp(a, b, c, point))
                std::cout << "O ";
            else
                std::cout << "- ";
        }
        std::cout << std::endl;
    }
};

void printPattern3(void) {
    Point a = Point(2.0f, 2.0f);
    Point b = Point(2.0f, 17.0f);
    Point c = Point(13.0f, 9.0f);

    // Print matrix
    for (int i = 0; i < NUM_LINES; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            Point point(j * 1.0f, (NUM_LINES - i) * 1.0f);
            if (bsp(a, b, c, point))
                std::cout << "O ";
            else
                std::cout << "- ";
        }
        std::cout << std::endl;
    }
};

void printPattern4(void) {
    Point a = Point(18.0f, 2.0f);
    Point b = Point(13.0f, 2.0f);
    Point c = Point(9.0f, 17.0f);

    // Print matrix
    for (int i = 0; i < NUM_LINES; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            Point point(j * 1.0f, (NUM_LINES - i) * 1.0f);
            if (bsp(a, b, c, point))
                std::cout << "O ";
            else
                std::cout << "- ";
        }
        std::cout << std::endl;
    }
};

void (*printPatterns[NUMBER_OF_PATTERNS])() = {&printPattern0, &printPattern1, &printPattern2, &printPattern3, &printPattern4};

int main() {
    printCanvas();

    for (int i = 0; i < 40; i++) {
        waitFrameRateTick();
        resetCursorPosition();
        printPatterns[i % NUMBER_OF_PATTERNS]();
    }

    return 0;
}