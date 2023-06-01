#include "Mushroom.h"

void Mushroom::interact(){
	player->setHealth(player->getHealth() -10);
	player->setXP(-5);
}

Mushroom::Mushroom(Player* player) : player(player) {}
