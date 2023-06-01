#pragma once
#include "field.h"

template < int max_count>

class SpawnImpas {
public:
	void operator()(Field* field) {
		int k = 0;
		for (int i = 2; i < field->getHeight(); i++) {
			for (int j = 2; j < field->getWidth(); j++) {
				if (k == max_count) return;
					if (((i == j) || (i + j == field->getWidth() - 1)) && (i % 7 != 0)) {
						field->getCell(i, j)->setState(Cell::IMPAS);
						k++;
					}
			}
		}
	}
};