#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
    Point a = Point(2.0f, 2.0f);
    Point b = Point(9.0f, 17.0f);
    Point c = Point(18.0f, 2.0f);

    // Point point = Point(0.5f, 1.0f);

    Point point;
    // point = a;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            point = Point(j * 1.0f, (20 - i) * 1.0f);
            if (bsp(a, b, c, point))
                std::cout << "O ";
            else
                std::cout << "- ";
        }
        std::cout << std::endl;
    }

    return 0;
}