#include "Point.hpp"

// CONSTRUCTORS / DESTRUCTOR ===================================================
Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)){};

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)){};

Point::Point(const Point &other) {
    *this = other;
};

Point::~Point(void){};

// ACCESSORS ===================================================================
Fixed const Point::getX(void) {
	return this->_x;
}

Fixed const Point::getY(void) {
	return this->_y;
}

// OPERATOR OVERLOADS ==========================================================
// ASSIGNMENT OPERATOR -------------------------------------------------
const Point &Point::operator=(const Point &other){
	(Fixed &) _x = other._x;
	(Fixed &) _y = other._y;
	return (*this);
};

// LOGICAL OPERATORS ---------------------------------------------------
bool Point::operator==(const Point &other) const {
	if (this->_x == other._x
		&& this->_y == other._y)
		return (true);
	else
		return (false);
};
