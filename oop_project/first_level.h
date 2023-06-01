#pragma once

#include "level.h"

class FirstLevel : public Level {
public:
	Field* generateLevel() override;
};