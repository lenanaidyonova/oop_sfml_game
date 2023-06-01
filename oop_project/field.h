#pragma once
#include "cell.h"
#include "Factory.h"
#include <vector>
#define H_PLAYER	16
#define W_PLAYER	12
#define SIZE_CELL	15


class Field {
private:
	int width;
	int height;
	std::vector<std::vector<Cell>> field;
	std::pair<float, float> player_coord;
	void swap(Field& obj);
	Player* player;

public:
	Field(int width = 30, int height = 30);

	Field(const Field& obj);
	Field& operator= (const Field& obj);
	Field(Field&& obj) noexcept;
	Field& operator=(Field&& obj) noexcept;
	~Field();

	Cell* getCell(int y, int x);
	void resizeField(int width, int height);
	int getWidth() const;
	int getHeight() const;
	void setHight(int h);
	void setWidth(int w);

	std::vector<std::vector<Cell>>* getField();

	std::pair<float, float> getCoordPlayer() const;
	void setCoordPlayer(float x, float y);
	Player* getPlayer();
};