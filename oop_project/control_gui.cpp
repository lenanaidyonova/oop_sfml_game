#include "control_gui.h"

ControlGUI::ControlGUI(WindowCommand* windowCmd) : windowCommand(windowCmd) {}

void ControlGUI::controlScan(CommandProcessing* cmdProcessing) {
	this->file.open("controllKeys.txt");
	std::map<DrawPlayer::DIRS, Keyboard::Key> commands = windowCommand->controlCommands();
	for (int i = 0; i < commands.size(); i++) {
		this->file << i << "\n" << commands[static_cast<DrawPlayer::DIRS>(i)] << "\n";
	}
	this->file.close();
	setControll(cmdProcessing);
}