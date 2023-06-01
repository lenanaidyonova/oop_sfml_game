#include "game.h"

Game::Game() {
	startMessage = new StartMessage();
	endMessage = new EndMessage();
	smallMessage = new SmallMessage();
}


void Game::start() {
	ProjectWindow project_window;
	std::vector<LogType*> logs = project_window.logWindow();
	std::vector<Logger*>  loggers = project_window.outLogWindow();
	WindowCommand* windowCommand = new WindowCommand();
	std::vector<ControlScan*> controls = project_window.controlScanWindow(windowCommand);
	LoggerPool* pool = new LoggerPool(loggers, logs);
	//std::pair <int, int> sizeField = project_window.menu();
	/*
	if (sizeField.first < 2 || sizeField.second < 2) {
		pool->logging(smallMessage);
		return;
	}*/
	Level* level = project_window.levelWindow();
	Creator* creator = new Creator(pool, controls, level);
	creator->getLoggerPool()->logging(startMessage);
	project_window.openWindow(creator);
	creator->getLoggerPool()->logging(endMessage);
	project_window.finishWindow(creator);
}