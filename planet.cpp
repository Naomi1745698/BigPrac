#include "planet.h"
#include <string>

planet::planet() {
	//default planet constructor
	name = "Earth";
	resourceCount = 1;
	size = resourceCount;
	rowCoordinate = 2;
	columnCoordinate = 2;
	ID = 'p';
}

planet::planet(std::string pName, int resources, int rowCoordinateInput, int columnCoordinateInput) {
	//defined constructor with defined planet name and resource amount
	name = pName;
	resourceCount = resources;
	size = resourceCount;
	rowCoordinate = rowCoordinateInput;
	columnCoordinate = columnCoordinateInput;
	ID = 'p';
}

planet::~planet() {
	//planet destructor
}

void planet::destroyPlanet() {
	if (resourceCount == 0) {
		//~planet();
	}
}

int planet::getSize() {
	return size;
}