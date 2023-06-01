#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "controller.h"
using namespace sf;

class ControlScan {
private:
	std::ifstream file;
public:
	virtual void controlScan(CommandProcessing* cmdProcessing) = 0;
	ControlScan();
	void setControll(CommandProcessing* cmdProcessing);
};