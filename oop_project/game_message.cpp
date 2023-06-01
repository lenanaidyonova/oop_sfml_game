#include "game_message.h"

GameMessage::GameMessage(std::string message) {
	this->message = message;
	this->tag = Message::GM;
	this->message = this->tags[tag] + this->message;
}