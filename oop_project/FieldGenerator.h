#pragma once

#include "spawn_berry_event.h"
#include "spawn_impas.h"
#include "spawn_key.h"
#include "spawn_player.h"
#include "field_size.h"
#include "spawn_mushroom_event.h"
#include "spawn_impas_second.h"


template<class ...Rules>
class FieldGenerator {
public:
	Field* fill() {
		Field* field = new Field();
		(Rules()(field), ...);

		return field;
	}
};