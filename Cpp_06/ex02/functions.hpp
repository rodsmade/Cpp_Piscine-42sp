#pragma once

#include <cstdlib> // rand, srand
#include <ctime> // time
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);
