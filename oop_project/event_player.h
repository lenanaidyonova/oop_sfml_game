#pragma once
#include "player.h"
#include "event.h"

class EventPlayer: public Evnt {
public:
	virtual void interact() = 0;
	virtual ~EventPlayer() = default;
};