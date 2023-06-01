#pragma once
#include "field.h"

template < int max_count>

class SpawnImpasSecond {
public:
	void operator()(Field* field) {
		int k = 0;
		for (int i = 1; i < field->getHeight(); i++) {
			for (int j = 1; j < field->getWidth(); j++) {
				if (k == max_count) return;
				if (i % 3 == 0 && j % 2 == 0) {
					field->getCell(i, j)->setState(Cell::IMPAS);
					k++;
				}
			}
		}
	}
};