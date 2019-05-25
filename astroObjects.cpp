#include "astroObjects.h"
#include <iostream>
#include <string>
using namespace std;

//astroObjects constructor with ID = 0 (empty space)
astroObjects::astroObjects() {
	ID = '0';
}


//print name function (generic)
void astroObjects::printName() {
	cout << name << endl;
}


//function to print object x & y coordinates
void astroObjects::printLocation() {
	cout << "X-Coordinate: " << columnCoordinate << endl;
	cout << "Y-Coordinate: " << rowCoordinate << endl;
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

//function to return object name
string astroObjects::getName() {
	return name;
}

astroObjects::~astroObjects() {
	//default astroObjects destructor
}