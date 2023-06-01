#include "file_logger.h"

FileLogger::FileLogger(std::string file) {
	this->file.open(file, std::ios_base::app | std::ios_base::out);
}
FileLogger::~FileLogger() {
	this->file.close();
}
void FileLogger::print(Message* msg) {
	file << msg;
}