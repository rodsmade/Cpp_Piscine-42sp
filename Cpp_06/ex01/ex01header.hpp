#pragma once

#include <stdint.h>

#include "Data.hpp"

Data* deserialize(uintptr_t raw);
uintptr_t serialize(Data* ptr);
