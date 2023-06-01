#include "message.h"

Message::Message() {
	tags = { {Message::GM, "[GM] "}, {Message::PM, "[PM] "}, {Message::EM, "[EM] "} };
}

std::string Message::getMessage() {
	return message;
}

Message::TAGS Message::getTag() {
	return this->tag;
}