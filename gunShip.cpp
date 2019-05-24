#include <string>
#include "gunShip.h"


gunship::gunship() : spaceship() {
	//default gunship constructor equals spacceship default constructor
}

gunship::gunship(std::string gsName, int gsHealth, int  gsFuel) : spaceship(gsName, gsHealth, gsFuel) {
	//spaceship constructor with defined name, health & fuel
	name = gsName;
	hullHealth = gsHealth;
	fuel = gsFuel;
	rowCoordinate = 0;
	columnCoordinate = 0;
	ID = 'g';
}

gunship::~gunship() {
	//default gunship destructor
}

int gunship::getHealth() {
	return hullHealth;
}

int gunship::getResources() {
	return fuel;
}

void gunship::setHealth(int health) {
	hullHealth = (hullHealth + health);
}

void gunship::setResources(int ssFuel) {
	fuel = (fuel + ssFuel);
}