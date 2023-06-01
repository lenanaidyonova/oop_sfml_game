#pragma once
#include "cell.h"
#include "logType.h"
#include "Message.h"

class PlayLog : public LogType {
public:
	Message* update(Message* msg) override;
};