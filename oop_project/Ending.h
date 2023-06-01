#pragma once
#include "event_player.h"
class Ending: public EventPlayer{
private:
	Player* player;
public:
	Ending(Player* player);
	void interact() override;
	~Ending() = default;
};