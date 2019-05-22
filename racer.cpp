#include <string>
#include "racer.h"


racer::racer() : spaceship() {
	//default racer constructor equals spacceship default constructor
}


racer::racer(std::string rsName, float  rsFuel) : spaceship(rsName, rsFuel) {
	//spaceship constructor with defined name, health & fuel
	name = rsName;
	hullHealth = 10;
	fuel = rsFuel;
	rowCoordinate = 0;
	columnCoordinate = 0;
	ID = 'r';
}

racer::~racer() {
	//default racer destructor
}

int racer::getSize() {
	return size;
}