#pragma once
#include "game_log.h"
#include "play_log.h"
#include "error_log.h"
#include "console_logger.h"
#include "file_logger.h"
#include "logger.h"


class LoggerPool {
public:
	LoggerPool(std::vector<Logger*> loggers, std::vector<LogType*> logs);
	void logging(Message* msg);
private: 
	std::vector<LogType*> logs;
	std::vector<Logger*> loggers;
};