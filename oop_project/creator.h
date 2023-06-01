#pragma once
#include "draw_field.h"
#include "controller.h"
#include "draw_player.h"
#include "event_manager.h"
#include "scoreboard.h"
#include "FieldBuilder.h"
#include "control_scan.h"
#include "command_processing.h"
#include "first_level.h"

class Creator {
public:
	Creator( LoggerPool* pool, std::vector<ControlScan*> controls, Level* level);
	DrawPlayer* getDrawPlayer();
	Player* getPlayer();
	DrawField* getDrawField();
	Field* getField();
	Controller* getController();
	EventManager* getEventManager();
	Factory* getFactory();
	ScoreBoard* getScoreBoard();
	LoggerPool* getLoggerPool();
	CommandProcessing* getCommandProcessing();
	std::vector<ControlScan*> getControls();
	~Creator();

private:
	Level* level;
	FieldBuilder* builder;
	LoggerPool* loggerPool;
	CommandProcessing* cmdProcessing;
	std::vector<ControlScan*> controls;
	Field* field;
	DrawField* draw_field;
	Player* player;
	DrawPlayer* draw_player;
	Controller* controller;
	EventManager* event_manager;
	Factory* factory;
	ScoreBoard* score_board;
};