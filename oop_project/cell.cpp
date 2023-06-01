#include "cell.h"

Cell::Cell() {
	state = Cell::EMPTY;
	event = nullptr;
	clear_event = nullptr;
	playerLocation = true;
}

Cell::Cell(const Cell& obj){
	state = obj.state;
	playerLocation = obj.playerLocation;
	event = obj.event;
	clear_event = obj.clear_event;
}

Cell& Cell::operator=(const Cell& obj) {
	if (this != &obj) {
		state = obj.state;
		playerLocation = obj.playerLocation;
		event = obj.event;
		clear_event = obj.clear_event;
	}
	return *this;
}


Cell::STATES Cell::getState() const{
	return this->state;
}

void Cell::setState(STATES state) {
	this->state = state;
}

bool Cell::IsPlayer() const {
	return playerLocation;
}

void Cell::setPlayerLocation(bool playerLocation) {
	this->playerLocation = playerLocation;
}

void Cell::setEvent(Evnt* event) {
	this->event = event;
}

void Cell::setClearEvent(Evnt* event){
	this->clear_event = event;
}

Evnt* Cell::getEvent() {
	return event;
}

Evnt* Cell::getClearEvent(){
	return this->clear_event;
}

int Cell::reactionPlayerOnCell() {
	if (state != EMPTY) {
		event->interact();
		clear_event->interact();
		return 1;
	} 
	return 0;
}
