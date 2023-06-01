#pragma once
#include "event.h"
#include "cell.h"

class EventCell: public Evnt {
public:
	void virtual interact() = 0;
	virtual ~EventCell() = default;
};