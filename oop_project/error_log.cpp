#include "error_log.h"

Message* ErrorLog::update(Message* msg) {
	if (msg->getTag() == Message::EM) {
		return msg;
	}
	return emptyMessage;
}
