#pragma once
#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point {
   private:
    Fixed const _x;
    Fixed const _y;

   public:
   // Constructors/Destructor
    Point(void);
    Point(float const x, float const y);
    Point(const Point &other);
    ~Point(void);

	// Accessors
    Fixed const getX(void);
    Fixed const getY(void);

	// Operator overloads
	// -- Assignment operator
    const Point &operator=(const Point &other);
	
	// -- Logical operators
    bool operator==(const Point &other) const;

};

#endif
