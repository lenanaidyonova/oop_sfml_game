#pragma once

#include "field.h"

template<int x = 0, int y = 0>

class SpawnPlayer {
public:
	void operator()(Field* field) {
		int cur_x = x; int cur_y = y;
		if (cur_x < 0) cur_x *= -1; if (cur_y < 0) cur_y *= -1;
		cur_x = cur_x % field->getWidth(); cur_y = cur_y % field->getHeight();
		if ((field->getCell(cur_y, cur_x)->getState() == Cell::EMPTY) && (field->getCell(cur_y, cur_x)->getEvent() == nullptr)) {
			field->setCoordPlayer(cur_x * SIZE_CELL, cur_y * SIZE_CELL);
		}
		else {
			field->setCoordPlayer(0, 0);
		}
	}
};