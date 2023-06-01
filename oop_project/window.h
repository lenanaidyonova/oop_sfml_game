#pragma once
#include <iostream> 
#include "controller.h"
#include "Creator.h"
#include "control_gui.h"
#include "first_level.h"
#include "second_level.h"


using namespace sf;

class ProjectWindow {
public:
	void openWindow(Creator* creator);
	std::pair<int,int> menu();
	void finishWindow(Creator* creator);
	Level* levelWindow();
	std::vector<LogType*> logWindow();
	std::vector<Logger*> outLogWindow();
	std::vector<ControlScan*> controlScanWindow(WindowCommand* windowCommand);
	
};