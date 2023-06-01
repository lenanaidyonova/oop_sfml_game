#include "Clear.h"

Clear::Clear(Cell* cell) : cell(cell) {}

void Clear::interact(){
	cell->setState(Cell::EMPTY);
}

/*
Clear::~Clear() {
	delete[] cell->getEvent();
}
*/