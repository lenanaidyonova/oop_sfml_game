#include "KeyApearance.h"

KeyApearance::KeyApearance(Cell* cell, Player* player, Evnt* event, Evnt* clear) : cell(cell), player(player), event(event), clear(clear) {}


void KeyApearance::interact(){
	if (player->getXP() >= 50) {
		cell->setState(Cell::KEY);
		cell->setEvent(event);
		cell->setClearEvent(clear);
	}
}

