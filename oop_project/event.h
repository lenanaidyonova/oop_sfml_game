#pragma once

class Evnt {
public:
	virtual void interact() = 0;
	virtual ~Evnt() = default;
};