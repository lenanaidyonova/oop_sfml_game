#pragma once
#include "field.h"

template<int number_1, int number_2, int number_3>

class SpawnKey {
public:
	void operator()(Field* field) {
		Player* player = field->getPlayer();
		int cur_1 = number_1; int cur_2 = number_2; int cur_3 = number_3;
		if (cur_1 < 0) cur_1 *= (-1); if (cur_2 < 0) cur_2 *= (-1); if (cur_3 < 0) cur_3 *= (-1);
		cur_1 = cur_1 % field->getHeight(); cur_2 = cur_2 % field->getHeight(); cur_3 = cur_3 % field->getHeight();

		field->getCell(cur_1, field->getWidth()-1)->setState(Cell::KEY);
		field->getCell(cur_1, field->getWidth()-1)->setEvent(new Key(player));
		field->getCell(cur_1, field->getWidth()-1)->setClearEvent(new Clear(field->getCell(cur_1, field->getWidth() - 1)));

		field->getCell(cur_2, field->getWidth()/2)->setState(Cell::KEY);
		field->getCell(cur_2, field->getWidth()/2)->setEvent(new Key(player));
		field->getCell(cur_2, field->getWidth()/2)->setClearEvent(new Clear(field->getCell(cur_2, field->getWidth() / 2)));

		field->getCell(cur_3, field->getWidth()/4)->setState(Cell::KEY);
		field->getCell(cur_3, field->getWidth()/4)->setEvent(new Key(player));
		field->getCell(cur_3, field->getWidth()/4)->setClearEvent(new Clear(field->getCell(cur_3, field->getWidth() / 4)));
	}
};