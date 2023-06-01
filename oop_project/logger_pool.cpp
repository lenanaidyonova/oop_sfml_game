#include "logger_pool.h"

LoggerPool::LoggerPool(std::vector<Logger*> loggers, std::vector<LogType*> logs) : loggers(loggers), logs(logs) {}


void LoggerPool::logging(Message* message) {
	for (int i = 0; i < logs.size(); i++) {
		Message* msg = logs.at(i)->update(message);
		for (int j = 0; j < loggers.size(); j++) {
			loggers.at(j)->print(msg);
		}
	}
}

