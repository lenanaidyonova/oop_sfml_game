#pragma once
#include "message.h"
#include "empty_message.h"

class LogType {
protected:
	Message* emptyMessage;
public:
	LogType();
	~LogType();
	virtual Message* update(Message* msg) = 0;
};