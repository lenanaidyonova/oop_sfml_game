#pragma once
#include <map>
#include "draw_player.h"


class WindowCommand {
public:
	std::map<DrawPlayer::DIRS, Keyboard::Key> controlCommands();
};