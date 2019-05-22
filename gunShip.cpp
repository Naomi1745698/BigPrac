#include <string>
#include "gunShip.h"


gunship::gunship() : spaceship() {
	//default gunship constructor equals spacceship default constructor
}

gunship::gunship(std::string gsName, float  gsFuel) : spaceship(gsName, gsFuel) {
	//spaceship constructor with defined name, health & fuel
	name = gsName;
	hullHealth = 20;
	fuel = gsFuel;
	rowCoordinate = 0;
	columnCoordinate = 0;
	ID = 'g';
}

gunship::~gunship() {
	//default gunship destructor
}

int gunship::getSize() {
	return size;
}