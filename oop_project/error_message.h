#pragma once
#include "message.h"

class ErrorMessage : public Message {
public:
	ErrorMessage(std::string message);
};