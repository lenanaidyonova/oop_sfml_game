#include "first_level.h"

Field* FirstLevel::generateLevel(){
	FieldGenerator<FieldSize<30, 30>, SpawnImpas<100>, SpawnPlayer<0, 0>, SpawnBerryEvent<5>, SpawnMushroomEvent<7>, SpawnKey<3, 10, 20> > gen;
	return gen.fill();
}


