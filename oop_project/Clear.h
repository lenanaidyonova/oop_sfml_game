#pragma once
#include "event_cell.h"

class Clear : public EventCell{
private:
	Cell* cell;
public:
	Clear(Cell* cell);
	void interact() override;
	~Clear() = default;
};