#pragma once
#include "player.h"
#include "Factory.h"
#include "field.h"
#include "random"
#include "event.h"
#include "Berry.h"
#include "Clear.h"
#include "Ending.h"
#include "Key.h"
#include "Mushroom.h"
#include "KeyApearance.h"
#include "logger_pool.h"
#include "berry_message.h"
#include "mushroom_message.h"
#include "key_message.h"

class EventManager {
public:
	EventManager(Evnt* ending);
	~EventManager();
	void manage(Player* player, Field* field, Factory* factory, LoggerPool* pool);
private:
	Evnt* ending;
	Message* berryMessage;
	Message* mushroomMessage;
	Message* keyMessage;
};