#include <string>
#include "racer.h"


racer::racer() : spaceship() {
	//default racer constructor equals spacceship default constructor
}


racer::racer(std::string rsName, int rsHealth, int rsFuel) : spaceship(rsName, rsFuel, rsFuel) {
	//spaceship constructor with defined name, health & fuel
	name = rsName;
	hullHealth = rsHealth;
	fuel = rsFuel;
	rowCoordinate = 0;
	columnCoordinate = 0;
	ID = 'r';
}

racer::~racer() {
	//default racer destructor
}

int racer::getHealth() {
	return hullHealth;
}

int racer::getResources() {
	return fuel;
}

void racer::setHealth(int health) {
	hullHealth = (hullHealth + health);
}

void racer::setResources(int ssFuel) {
	fuel = (fuel + ssFuel);
}