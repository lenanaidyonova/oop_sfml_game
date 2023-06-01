#pragma once
#include "event_player.h"

class Key : public EventPlayer {
private:
	Player* player;
public:
	Key(Player* player);
	void interact() override;
	~Key() = default;
};