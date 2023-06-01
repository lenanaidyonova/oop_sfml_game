#include "game_log.h"

Message* GameLog::update(Message* msg) {
	if (msg->getTag() == Message::GM) {
		return msg;
	}
	return emptyMessage;
}
