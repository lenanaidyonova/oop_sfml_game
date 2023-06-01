#pragma once
#include <iostream>
#include "event.h"
#include "event_player.h"

class Cell {
public:
	enum STATES { IMPAS, EMPTY, KEY, BERRY, MUSHROOM};
	Cell();
	Cell(const Cell& obj);
	Cell& operator= (const Cell& obj);

	STATES getState() const;
	void setState(STATES state);

	bool IsPlayer() const;
	void setEvent(Evnt* event);
	void setClearEvent(Evnt* event);
	void setPlayerLocation(bool playerLocation);
	Evnt* getEvent();
	Evnt* getClearEvent();
	int reactionPlayerOnCell();

private:
	STATES state;
	bool playerLocation;
	Evnt* event;
	Evnt* clear_event;
};