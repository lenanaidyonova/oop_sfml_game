#pragma once
#include "FieldGenerator.h"

class Level {
public:
	virtual Field* generateLevel() = 0;
};