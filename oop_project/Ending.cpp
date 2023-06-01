#include "Ending.h"

Ending::Ending(Player* player) : player(player) {}

void Ending::interact(){
	if (player->getHealth() <= 0) {
		player->setAlive(false);
	}
	else if (player->getKey() == 3) {
		player->setAlive(false);
	}
}
