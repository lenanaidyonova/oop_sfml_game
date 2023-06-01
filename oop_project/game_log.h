#pragma once
#include "logType.h"
#include "Message.h"

class GameLog: public LogType{
public:
	Message* update(Message* msg) override;
};