#include "creator.h"
#include <iostream>

Creator::Creator( LoggerPool* pool, std::vector<ControlScan*> controls, Level* level){
    this->controls = controls;
    this->loggerPool = pool;
    this->level = level;
    this->field = level->generateLevel();
    this->player = field->getPlayer();
    //builder = new FieldBuilder();
    //field = new Field(sizeField.first, sizeField.second);
    //player = new Player(100, 0, 0);
    //field = builder->createField(sizeField.first, sizeField.second);
    //builder->fillStates(field);
    draw_field = new DrawField("Grass.png");
    draw_player = new DrawPlayer("l_sprite.png", "r_sprite.png", "u_sprite.png", "d_sprite.png");
    cmdProcessing = new CommandProcessing(draw_player);
    cmdProcessing->fillDefaultCommands();
    controller = new Controller();
    factory = new Factory();
    //builder->fillEvents(field, factory, player);
    event_manager = new EventManager(factory->createAction(field, field->getCell(0,0), player, Factory::ENDING)) ;
    score_board = new ScoreBoard();
}

Creator::~Creator() {
    delete draw_field;
    delete draw_player;
    delete controller;
    delete event_manager;
    delete factory;
    delete score_board;
    //delete loggerPool;
    delete cmdProcessing;
}

DrawPlayer* Creator::getDrawPlayer() {
    return draw_player;
}
Player* Creator::getPlayer() {
    return player;
}
DrawField* Creator::getDrawField() {
    return draw_field;
}
Field* Creator::getField() {
    return field;
}

Controller* Creator::getController() {
    return controller;
}

EventManager* Creator::getEventManager() {
    return event_manager;
}

Factory* Creator::getFactory() {
    return factory;
}

ScoreBoard* Creator::getScoreBoard(){
    return score_board;
}

LoggerPool* Creator::getLoggerPool(){
    return loggerPool;
}

CommandProcessing* Creator::getCommandProcessing(){
    return cmdProcessing;
}

std::vector<ControlScan*> Creator::getControls(){
    return controls;
}
