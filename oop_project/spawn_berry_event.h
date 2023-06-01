#include "field.h"

template< int number>
class SpawnBerryEvent {
public:
	void operator()(Field* field) {
		Player* player = field->getPlayer();
		for (int i = 0; i < field->getHeight(); i++) {
			for (int j = 0; j < field->getWidth(); j++) {
				if (i > 0 || j > 0) {
					if (i == ((j * number) % field->getHeight())) {
						field->getCell(i, j)->setState(Cell::BERRY);
						field->getCell(i, j)->setEvent(new Berry(player));
						field->getCell(i, j)->setClearEvent(new Clear(field->getCell(i, j)));
					}
				}
			}
		}
	}
};