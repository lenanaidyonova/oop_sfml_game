#pragma once
#include "message.h"

class GameMessage : public Message {
public:
	GameMessage(std::string message);
};