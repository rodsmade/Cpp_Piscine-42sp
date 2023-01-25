#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // vectors
    double dot00, dot01, dot02, dot11, dot12;
    double invDenom;
    dot00 = dot01 = dot02 = dot11 = dot12 = 0;

    if (point == a || point == b || point == c) {
        return (false);
    };

    // Compute vectors
    Point v0 = Point((c.getX() - a.getX()).toFloat(), (c.getY() - a.getY()).toFloat());
    Point v1 = Point((b.getX() - a.getX()).toFloat(), (b.getY() - a.getY()).toFloat());
    Point v2 = Point((point.getX() - a.getX()).toFloat(), (point.getY() - a.getY()).toFloat());

    // Compute dot products
    dot00 = (v0.getX() * v0.getX() + v0.getY() * v0.getY()).toFloat();
    dot01 = (v0.getX() * v1.getX() + v0.getY() * v1.getY()).toFloat();
    dot02 = (v0.getX() * v2.getX() + v0.getY() * v2.getY()).toFloat();
    dot11 = (v1.getX() * v1.getX() + v1.getY() * v1.getY()).toFloat();
    dot12 = (v1.getX() * v2.getX() + v1.getY() * v2.getY()).toFloat();

    // Compute barycentric coordinates
    invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
    double u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    double v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    // Check if point is in triangle
    return (u >= 0) && (v >= 0) && (u + v < 1);
}
