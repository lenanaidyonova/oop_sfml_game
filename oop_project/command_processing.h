#pragma once
#define SIZE_DIRS 4
#define SIZE_KEYBOARD 100
#include "draw_player.h"

class CommandProcessing {
public:
	void setCommand(DrawPlayer::DIRS cmd, Keyboard::Key key);
	std::map <DrawPlayer::DIRS, Keyboard::Key> getCommands();
	void callRender( DrawPlayer::DIRS dir);
	void fillDefaultCommands();
	CommandProcessing( DrawPlayer* drawPlayer);
	~CommandProcessing();
private:
	std::ifstream file;
	DrawPlayer* drawPlayer;
	std::map <DrawPlayer::DIRS, Keyboard::Key> commands;
	std::map <DrawPlayer::DIRS, Keyboard::Key> defaultCommands;
};