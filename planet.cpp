#include "planet.h"
#include <string>
#include <stdlib.h>

planet::planet() {
	//default planet constructor
	name = "P-";
	resourceCount = 2 + (rand() % 4);	//planet resource count between 2 and 5 (random)
	rowCoordinate = 2;
	columnCoordinate = 2;
	ID = 'p';
}

planet::planet(std::string pName, int resources, int rowCoordinateInput, int columnCoordinateInput) {
	//defined constructor with defined planet name and resource amount
	name = pName;
	resourceCount = resources;
	rowCoordinate = rowCoordinateInput;
	columnCoordinate = columnCoordinateInput;
	ID = 'p';
}

planet::~planet() {
	//planet destructor
}

int planet::getResources() {
	return resourceCount;
}

int planet::getHealth() {
	//not currently required, function inserted due to virtual function in astroObjects
}

void planet::setHealth(int resources) {
	//not currently required, function inserted due to virtual function in astroObjects
}

void planet::setResources(int resources) {
	resourceCount = (resourceCount + resources);
}