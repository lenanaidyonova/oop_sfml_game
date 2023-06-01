#pragma once

#include "field.h"
template< int number>
class SpawnMushroomEvent {
public:
	void operator()(Field* field) {
		Player* player = field->getPlayer();
		for (int i = 0; i < field->getHeight(); i++) {
			for (int j = 0; j < field->getWidth(); j++) {
				if (i > 0 || j > 0) {
					if (i == ((j * (number - 3)) % field->getHeight())) {
						field->getCell(i, j)->setState(Cell::MUSHROOM);
						field->getCell(i, j)->setEvent(new Mushroom(player));
						field->getCell(i, j)->setClearEvent(new Clear(field->getCell(i, j)));
					}
				}
			}
		}
	}
};