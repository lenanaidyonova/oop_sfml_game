#pragma once
#include "message.h"
#include "player.h"

class PlayMessage : public Message {
public:
	PlayMessage(std::string message);
};