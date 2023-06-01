#include "FieldBuilder.h"

Field* FieldBuilder::createField(int width, int height){
    Field* field = new Field(width, height);
	for (int i = 0; i < height; i++) {
		field->getField()->emplace_back();
		for (int j = 0; j < width; j++) {
			field->getField()->at(i).emplace_back();
		}
	}
	return field;
}

void FieldBuilder::fillStates(Field* field){
	field->getField()->at(0).at(0).setPlayerLocation(true);
	for (int i = 1; i < field->getHeight(); i++) {
		for (int j = 1; j < field->getWidth(); j++) {
			if ((i != 0 || j!= 0) && (i != 1 || j != 0) && (i != 0 || j != 1) && (i != 1 || j != 1))
			{	std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> distrib(1, 30);

				switch (distrib(gen)) {
				case 1:
					field->getCell(i, j)->setState(Cell::BERRY);
					break;
				case 2:
					field->getCell(i, j)->setState(Cell::IMPAS);
					break;
				case 4:
					field->getCell(i, j)->setState(Cell::MUSHROOM);
				default:
					break;
				}
			}
		}
	}

}

void FieldBuilder::fillEvents(Field* field, Factory* factory, Player* player){
	for (int i = 0; i < field->getHeight(); i++) {
		for (int j = 0; j < field->getWidth(); j++) {
			switch (field->getCell(i,j)->getState()) {
			case Cell::BERRY:
				field->getCell(i, j)->setEvent(factory->createAction(field, field->getCell(i, j), player, Factory::BERRY));
				field->getCell(i, j)->setClearEvent(factory->createAction(field, field->getCell(i, j), player, Factory::CLEAR));
				break;
			case Cell::MUSHROOM:
				field->getCell(i, j)->setEvent(factory->createAction(field, field->getCell(i, j), player, Factory::MUSHROOM));
				field->getCell(i, j)->setClearEvent(factory->createAction(field, field->getCell(i, j), player, Factory::CLEAR));
				break;
			}
			
		}
	}
}
