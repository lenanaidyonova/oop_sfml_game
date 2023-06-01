#pragma once
#include "logType.h"

class ErrorLog : public LogType {
public:
	Message* update(Message* msg) override;
};