#include "error_message.h"

ErrorMessage::ErrorMessage(std::string message) {
	this->message = message;
	this->tag = Message::EM;
	this->message = this->tags[tag] + this->message;
}