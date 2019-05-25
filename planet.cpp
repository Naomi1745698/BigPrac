#include "planet.h"
#include <string>
#include <stdlib.h>

//constructors
planet::planet() {
	//default planet constructor
	name = "fuel";						//automaticaly sets to fuel-type planet
	resourceCount = 2 + (rand() % 4);	//planet resource count between 2 and 5 (random)
	rowCoordinate = 2;
	columnCoordinate = 2;
	ID = 'p';
}

planet::planet(string resourceType, int resources, int rowCoordinateInput, int columnCoordinateInput) {
	//defined constructor with defined planet name and resource amount
	name = resourceType;
	resourceCount = resources;
	rowCoordinate = rowCoordinateInput;
	columnCoordinate = columnCoordinateInput;
	ID = 'p';
}

//getters
string planet::getName(){
	return name;
}

int planet::getHealth(){
	//not currently required, function inserted due to virtual function in astroObjects
}

int planet::getResources(){
	return resourceCount;
}

//setters
void planet::setHealth(int resources){
	//not currently required, function inserted due to virtual function in astroObjects
}

void planet::setResources(int resources){
	resourceCount = (resourceCount + resources);		//rather than setting an amount, this function adds resources
}

//deconstructor
planet::~planet(){
}
