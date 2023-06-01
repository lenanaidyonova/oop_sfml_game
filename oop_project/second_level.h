#pragma once

#include "level.h"

class SecondLevel : public Level {
public:
	Field* generateLevel() override;
};