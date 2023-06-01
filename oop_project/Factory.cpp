#include "Factory.h"

Evnt* Factory::createAction(Field* field, Cell* cell, Player* player, EVN evn){

	switch (evn){
	case Factory::BERRY:
		return new Berry(player);
	case Factory::CLEAR:
		return new Clear(cell);
	case Factory::MUSHROOM:
		return new Mushroom(player);
	case Factory::ENDING:
		return new Ending(player);
	case Factory::KEY:
		return new Key(player);
	case Factory::KEYAPEARANCE:
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(1, std::min(field->getHeight(), field->getWidth()));
		int i = distrib(gen);
		int j = distrib(gen);
		return new KeyApearance(field->getCell(i, j), player, new Key(player), new Clear(field->getCell(i, j)));
	}
	
}
