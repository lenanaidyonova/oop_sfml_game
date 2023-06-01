#include "field.h"
#include <math.h>
#include <random>

Field::Field(int width, int height) : width(width), height(height), player_coord({ 0,0 }), player(new Player(100,0,0)) {
	for (int i = 0; i < height; i++) {
		field.emplace_back();
		for (int j = 0; j < width; j++) {
			field.at(i).emplace_back();
		}
	}
}


Field::Field(const Field& obj) : width(obj.width), height(obj.height), player_coord(obj.player_coord), player(obj.player) {
	for (int i = 0; i < height; i++) {
		field.emplace_back();
		for (int j = 0; j < width; j++) {
			field.at(i).push_back(obj.field.at(i).at(j));
		}
	}
}

void Field::resizeField(int width, int height) {
	for (int i = 0; i < height; i++) {
		field.at(i).resize(width);
	}
	field.resize(height);
	this->height = height;
	this->width = width;
}

void Field::swap(Field& obj) {
	std::swap(width, obj.width);
	std::swap(height, obj.height);
	std::swap(field, obj.field);
	std::swap(player_coord, obj.player_coord);
	std::swap(player, obj.player);
}

Field& Field::operator=(const Field& obj) {
	if (this != &obj) {
		Field(obj).swap(*this);
	}
	return *this;
}

Field::Field(Field&& obj) noexcept{
	this->swap(obj);
}

Field& Field::operator=(Field&& obj) noexcept{
	if (this != &obj) {
		this->swap(obj);
	}
	return *this;
}

Field::~Field(){
	delete player;
}

Cell* Field::getCell(int y, int x) {
	return &field.at(y).at(x);
}

int Field::getWidth() const{
	return this->width;
}

int Field::getHeight() const{
	return this->height;
}

void Field::setHight(int h) {
	this->height = h;
}
void Field::setWidth(int w) {
	this->width = w;
}

std::vector<std::vector<Cell>>* Field::getField(){
	return &field;
}

std::pair<float,float> Field::getCoordPlayer() const{
	return player_coord;
}

void Field::setCoordPlayer(float x, float y) {
	if (x < 0) x = (width - 1) * SIZE_CELL + (SIZE_CELL - W_PLAYER);  
	if (y < 0) y = (height - 1) * SIZE_CELL + (SIZE_CELL - H_PLAYER);
	if (x > (width - 1) * SIZE_CELL + (SIZE_CELL - W_PLAYER)) x = 0;
	if (y > (height - 1) * SIZE_CELL + (SIZE_CELL - H_PLAYER)) y = 0;
	player_coord.first = x;
	player_coord.second = y;
}


Player* Field::getPlayer(){
	return player;
}








