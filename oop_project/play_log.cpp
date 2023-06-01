#include "play_log.h"

Message* PlayLog::update(Message* msg) {
	if (msg->getTag() == Message::PM) {
		return msg;
	}
	return emptyMessage;
}
