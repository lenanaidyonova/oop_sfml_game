#pragma once
#include "field.h"
#include "player.h"
#include "logger_pool.h"
#include "impassible_message.h"
#define H_PLAYER	16
#define W_PLAYER	12
#define SIZE_CELL	15
#define SPEED 0.15

using namespace sf;

class DrawPlayer {

public:
	enum DIRS { LEFT, RIGHT, UP, DOWN };
	DrawPlayer(String F1, String F2, String F3, String F4);
	void updatePosition(float& time, Field* field, LoggerPool* pool);
	void interaction(Field* field, LoggerPool* pool);
	Texture* getTexturePlayer(DrawPlayer::DIRS dir);
	Sprite* getSpritePlayer();
	void render(DrawPlayer::DIRS dir);

	DIRS getDirection();
	void setDirection(DIRS dir);
	float getSpeed();
	void setSpeed(float speed);
	float getCurrentFrame();
	void setCurrentFrame(float currentFrame);

private:
	float dx, dy;
	String filePlayer;
	Image image_left;
	Image image_right;
	Image image_up;
	Image image_down;
	Texture texture_left;
	Texture texture_right;
	Texture texture_up;
	Texture texture_down;
	Sprite spritePlayer;
	Message* impas;
	float speed;
	DIRS direction;
	float currentFrame;
};