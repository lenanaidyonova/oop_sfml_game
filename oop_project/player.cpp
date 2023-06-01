#include "player.h"

Player::Player(int health, int xp, int key) :health(health), xp(xp), key(key), alive(true) {};

void Player::swap(Player& obj){
	std::swap(health, obj.health);
	std::swap(xp, obj.xp);
	std::swap(key, obj.key);
	std::swap(alive, obj.alive);
}

Player::Player(const Player& obj) {
	health = obj.health;
	xp = obj.xp;
	key = obj.key;
	alive = obj.alive;
}

Player& Player::operator=(const Player& obj){
	if (this != &obj) {
		Player(obj).swap(*this);
	}
	return *this;
}

Player::Player(Player&& obj) noexcept {
	this->swap(obj);
}

Player& Player::operator=(Player&& obj) noexcept {
	if (this != &obj) {
		this->swap(obj);
	}
	return *this;
}


int Player::getHealth() const{
	return health;
}

int Player::getXP() const {
	return xp;
}
int Player::getKey() const{
	return key;
}

void Player::setHealth(int health) {
	this->health = health;
}

void Player::setXP(int XP) {
	this->xp += XP;
}

void Player::setKey(int key){
	this->key = key;
}
bool Player::getAlive() const{
	return alive;
}
void Player::setAlive(bool state){
	this->alive = state;
}
