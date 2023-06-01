#include "draw_player.h"

DrawPlayer::DrawPlayer(String F1, String F2, String F3, String F4): speed(0), direction(DrawPlayer::DOWN), currentFrame(0) {

	image_left.loadFromFile(F1);
	texture_left.loadFromImage(image_left);

	image_right.loadFromFile(F2);
	texture_right.loadFromImage(image_right);

	image_up.loadFromFile(F3);
	texture_up.loadFromImage(image_up);

	image_down.loadFromFile(F4);
	texture_down.loadFromImage(image_down);

	spritePlayer.setTexture(texture_down);
	spritePlayer.setTextureRect(IntRect(0, 0, W_PLAYER, H_PLAYER));
	
	impas = new ImpasMessage();
}

DrawPlayer::DIRS DrawPlayer::getDirection() {
	return direction;
}
void DrawPlayer::setDirection(DIRS dir) {
	direction = dir;
}

float DrawPlayer::getSpeed() {
	return speed;
}
void DrawPlayer::setSpeed(float speed) {
	this->speed = speed;
}

float DrawPlayer::getCurrentFrame(){
	return this->currentFrame;
}

void DrawPlayer::setCurrentFrame(float currentFrame){
	this->currentFrame = currentFrame;
}


void DrawPlayer::updatePosition(float& time, Field* field, LoggerPool* pool) {
	field->getCell(int(field->getCoordPlayer().second / SIZE_CELL), int(field->getCoordPlayer().first / SIZE_CELL))->setPlayerLocation(false);

	switch (direction) {
		case DrawPlayer::RIGHT:
			dx = this->speed;
			dy = 0;
			break;
		case DrawPlayer::LEFT:
			dx = -this->speed;
			dy = 0; 
			break;
		case DrawPlayer::DOWN:
			dx = 0; 
			dy = this->speed;
			break;
		case DrawPlayer::UP:
			dx = 0; 
			dy = -this->speed;
			break;
	}

	field->setCoordPlayer(field->getCoordPlayer().first + dx * time, field->getCoordPlayer().second + dy * time);
	this->speed = 0;
	spritePlayer.setPosition(field->getCoordPlayer().first, field->getCoordPlayer().second);
	interaction(field, pool);
	field->getCell(int(field->getCoordPlayer().second / SIZE_CELL), int(field->getCoordPlayer().first / SIZE_CELL))->setPlayerLocation(true);
}

void DrawPlayer::interaction(Field* field, LoggerPool* pool) {

	int y0 = int(field->getCoordPlayer().second) / SIZE_CELL;
	int x0 = int(field->getCoordPlayer().first) / SIZE_CELL;

	int y1, x1;
	if (int((field->getCoordPlayer().second + 2 * H_PLAYER) / SIZE_CELL) > field->getHeight()) y1 = field->getHeight();
	else y1 = int((field->getCoordPlayer().second + 2 * H_PLAYER) / SIZE_CELL);

	if (int((field->getCoordPlayer().first + 2 * W_PLAYER) / SIZE_CELL) > field->getWidth()) x1 = field->getWidth();
	else x1 = int((field->getCoordPlayer().first + 2 * W_PLAYER) / SIZE_CELL);


	for (int i = y0; i < y1; i++) {
		for (int j = x0; j < x1; j++) {
			if (field->getCell(i, j)->getState() == 0) {
				if (dx > 0) {
					field->setCoordPlayer(j * SIZE_CELL - W_PLAYER, field->getCoordPlayer().second);
				}
				if (dx < 0) {
					field->setCoordPlayer(j * SIZE_CELL + SIZE_CELL, field->getCoordPlayer().second);
				}
				if (dy > 0) {
					field->setCoordPlayer(field->getCoordPlayer().first, i * SIZE_CELL - H_PLAYER - 2);
				}
				if (dy < 0) {
					field->setCoordPlayer(field->getCoordPlayer().first, i * SIZE_CELL + SIZE_CELL);
				}
				pool->logging(impas);
			}
		}
	}
}

Texture* DrawPlayer::getTexturePlayer(DrawPlayer::DIRS dir) {
	switch (dir)
	{
	case DrawPlayer::RIGHT:
		return &texture_right;
	case DrawPlayer::LEFT:
		return &texture_left;
	case DrawPlayer::UP:
		return &texture_up;
	case DrawPlayer::DOWN:
		return &texture_down;
	}
}

Sprite* DrawPlayer::getSpritePlayer() {
	return &spritePlayer;
}

void DrawPlayer::render(DrawPlayer::DIRS dir){
	this->direction = dir; this->speed = SPEED;
	spritePlayer.setTexture(*getTexturePlayer(dir));
	spritePlayer.setTextureRect(IntRect(IntRect(W_PLAYER * int(this->currentFrame), 0, W_PLAYER, H_PLAYER)));
}
