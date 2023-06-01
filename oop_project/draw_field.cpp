#include "draw_field.h"

DrawField::DrawField(std::string fileTexture) {
	mapImage.loadFromFile(fileTexture);
	mapTexture.loadFromImage(mapImage);
	mapSprite.setTexture(mapTexture);
}


Sprite* DrawField:: getSpriteMap() {
	return &mapSprite;
}

void DrawField::setSpriteMap(Field *field, RenderWindow& window) {
	for (int i = 0; i < field->getHeight(); i++){
		for (int j = 0; j < field->getWidth(); j++)
		{
			if (field->getCell(i, j)->getState() == 0) {
				if (i % 2 == 0) mapSprite.setTextureRect(IntRect(45, 0, SIZE_CELL, SIZE_CELL));
				else mapSprite.setTextureRect(IntRect(30, 0, SIZE_CELL, SIZE_CELL));
			}
			if (field->getCell(i, j)->getState() == 1) {
				mapSprite.setTextureRect(IntRect(0, 0, SIZE_CELL, SIZE_CELL));
			}
			if (field->getCell(i, j)->getState() == 2) {
				mapSprite.setTextureRect(IntRect(90, 0, SIZE_CELL, SIZE_CELL));
			}
			if (field->getCell(i, j)->getState() == 3) {
				mapSprite.setTextureRect(IntRect(60, 0, SIZE_CELL, SIZE_CELL));
			}
			if (field->getCell(i, j)->getState() == 4) {
				mapSprite.setTextureRect(IntRect(75, 0, SIZE_CELL, SIZE_CELL));
			}

			mapSprite.setPosition(j * SIZE_CELL, i * SIZE_CELL);
			window.draw(mapSprite);
		}
	}
}

