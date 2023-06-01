#pragma once
#include "event_cell.h"

class KeyApearance : public EventCell {
private:
	Cell* cell;
	Player* player;
	Evnt* event;
	Evnt* clear;

public:
	KeyApearance(Cell* cell, Player* player, Evnt* event, Evnt* clear);
	void interact() override;
	~KeyApearance() = default;
};