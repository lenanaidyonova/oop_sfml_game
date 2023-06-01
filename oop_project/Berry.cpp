#include "Berry.h"

Berry::Berry(Player* player) : player(player) {};

void Berry::interact() {
	player->setXP(10);
	player->setHealth(player->getHealth() + 1);
}
