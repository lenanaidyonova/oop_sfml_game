#pragma once
#include "control_scan.h"
#include <fstream>
#include "window_command.h"
#include <iostream>

class ControlGUI : public ControlScan {
private:
	std::ofstream file;
	WindowCommand* windowCommand;
public:
	ControlGUI(WindowCommand* windowCmd);
	void controlScan(CommandProcessing* cmdProcessing) override;
};