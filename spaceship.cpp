#include "spaceship.h"
#include <string>
#include <stdlib.h>

spaceship::spaceship() {
	//default spaceship constructor
	name = "Rocket";
	hullHealth = 10;
	fuel = 10;
	rowCoordinate = 0;
	columnCoordinate = 0;
	ID = 's';
}

spaceship::spaceship(std::string ssName, int ssHullHealth, int ssFuel) {
	//spaceship constructor with defined name, health & fuel
	name = ssName;
	hullHealth = ssHullHealth;
	fuel = ssFuel;
	rowCoordinate = 0;
	columnCoordinate = 0;
	ID = 's';
}

spaceship::~spaceship() {

}