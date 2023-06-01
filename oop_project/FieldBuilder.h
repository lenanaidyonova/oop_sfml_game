#pragma once
#include "field.h"
#include "random"
#include "Factory.h"
#include "player.h"

class FieldBuilder {
public:
	Field* createField(int width, int height);
	void fillStates(Field* field);
	void fillEvents(Field* field, Factory* factory, Player* player);
};