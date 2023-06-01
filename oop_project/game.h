#pragma once
#include "creator.h"
#include "window.h"
#include "start_message.h"
#include "end_message.h"
#include "small_field_message.h"
class Game {
private:
	Message* startMessage;
	Message* endMessage;
	Message* smallMessage;
public:
	Game();
	void start();
};