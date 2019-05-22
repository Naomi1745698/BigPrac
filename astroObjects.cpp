#include "astroObjects.h"
#include <iostream>
#include <string>

//astroObjects constructor with ID = 0 (empty space)
astroObjects::astroObjects() {
	ID = '0';
}


//print name function (generic)
void astroObjects::printName() {
	std::cout << name << std::endl;
}


//function to print object x & y coordinates
void astroObjects::printLocation() {
	std::cout << "X-Coordinate: " << columnCoordinate << std::endl;
	std::cout << "Y-Coordinate: " << rowCoordinate << std::endl;
}

//function to set row and column coordinates
void astroObjects::setCoordinate(int row, int column) {
	rowCoordinate = row;
	columnCoordinate = column;
}

//function to return object row coordinate (y coordinate)
int astroObjects::getRowCoordinate() {
	return rowCoordinate;
}


//function to return object column coordinate (x coordinate)
int astroObjects::getColumnCoordinate() {
	return columnCoordinate;
}


//function to return object ID
char astroObjects::getID() {
	return ID;
}

astroObjects::~astroObjects() {
	//default astroObjects destructor
}