#include "Key.h"

Key::Key(Player* player) : player(player) {}

void Key::interact(){
	player->setKey(player->getKey() + 1);
	//player->setXP(-player->getXP());
}
