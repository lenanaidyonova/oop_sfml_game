#pragma once
#include "event_player.h"
class Berry : public EventPlayer {
private:
	Player* player;
public:
	Berry(Player* player);
	void interact() override;
	~Berry() = default;
};