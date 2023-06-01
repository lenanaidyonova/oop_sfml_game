#pragma once
#include "field.h"
#include<SFML/Graphics.hpp>
#include <fstream>
#define SIZE_CELL	15
using namespace sf;

class DrawField {
public:
	DrawField(std::string fileTexture);
	Sprite* getSpriteMap();
	void setSpriteMap(Field* field, RenderWindow& window);

private:
	Image mapImage;
	Texture mapTexture;
	Sprite mapSprite;
};