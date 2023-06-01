#pragma once

#include "Berry.h"
#include "Clear.h"
#include "Mushroom.h"
#include "Ending.h"
#include "KeyApearance.h"
#include "Key.h"
#include "field.h"
#include "random"

class Field;

class Factory{
public:
	enum EVN {BERRY, CLEAR, MUSHROOM, ENDING, KEY, KEYAPEARANCE};
	Evnt* createAction(Field* field, Cell* cell, Player* player, EVN evn);
};