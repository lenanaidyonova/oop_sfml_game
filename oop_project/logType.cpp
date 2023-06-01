#include "logType.h"

LogType::LogType() {
	emptyMessage = new EmptyMessage();
}

LogType::~LogType() {
	delete[] emptyMessage;
}