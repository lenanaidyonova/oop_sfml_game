#include "second_level.h"

Field* SecondLevel::generateLevel(){
	FieldGenerator<FieldSize<30, 30>, SpawnImpasSecond<300>, SpawnPlayer<15, 15>, SpawnBerryEvent<8>, SpawnMushroomEvent<7>, SpawnKey<3, 10, 20> > gen;

	return gen.fill();
}
