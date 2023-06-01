#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player {
public:
	Player(int health, int xp, int key);
	Player(const Player& obj);
	Player& operator=(const Player& obj);
	Player(Player&& obj) noexcept;
	Player& operator=(Player&& obj) noexcept;
	int getHealth() const;
	int getXP() const;
	int getKey() const;
	void setHealth(int health);
	void setXP(int xp);
	void setKey(int key);
	bool getAlive() const;
	void setAlive(bool state);
	
	
private:
	void swap(Player& obj);
	int health;
	int xp;
	int key;
	bool alive;
};