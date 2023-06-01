#pragma once
#include "player.h"
#include "SFML/Graphics.hpp"
#include <sstream>
using namespace sf;

class ScoreBoard {
public:
	Text scoreBoard(Text text, int xp, int health, int key);
	Text finishBoard(Text text, int xp, bool win);

};