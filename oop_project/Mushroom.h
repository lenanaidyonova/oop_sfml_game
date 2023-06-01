#pragma once
#include "event_player.h"

class Mushroom: public EventPlayer {
private:
	Player* player;
public:
	Mushroom(Player* player);
	void interact() override;
	~Mushroom() = default;
};