#include "event_manager.h"
#include <iostream>

EventManager::EventManager(Evnt* ending){
	this->ending = ending;
	berryMessage = new BerryMessage();
	mushroomMessage = new MushroomMessage();
	keyMessage = new KeyMessage();
}

EventManager::~EventManager() {
	delete ending;
	//delete[] berryMessage;
	//delete[] mushroomMessage;
	//delete[] keyMessage;
}

void EventManager::manage(Player* player, Field* field, Factory* factory, LoggerPool* pool){
	int flag;
	int y0 = int(field->getCoordPlayer().second) / SIZE_CELL;
	int x0 = int(field->getCoordPlayer().first) / SIZE_CELL;

	int y1, x1;
	if (int((field->getCoordPlayer().second + 2 * H_PLAYER) / SIZE_CELL) > field->getHeight()) y1 = field->getHeight();
	else y1 = int((field->getCoordPlayer().second + 2 * H_PLAYER) / SIZE_CELL);

	if (int((field->getCoordPlayer().first + 2 * W_PLAYER) / SIZE_CELL) > field->getWidth()) x1 = field->getWidth();
	else x1 = int((field->getCoordPlayer().first + 2 * W_PLAYER) / SIZE_CELL);


	for (int i = y0; i < y1; i++) {
		for (int j = x0; j < x1; j++) {
			Cell::STATES currrent = field->getCell(i, j)->getState();
			flag = field->getCell(i, j)->reactionPlayerOnCell();
			if (flag) {
				switch (currrent)
				{
				case Cell::KEY:
					pool->logging(keyMessage);
					break;
				case Cell::BERRY:
					pool->logging(berryMessage);
					break;
				case Cell::MUSHROOM:
					pool->logging(mushroomMessage);
					break;
				}
			}
			//keyAdd->interact();
			ending->interact();	
		}
	}
}

