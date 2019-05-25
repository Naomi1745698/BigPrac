#include <iostream>
#include <stdlib.h>
#include "meteor.h"


meteor::meteor() {
	//default meteor constructor
	name = "Mr.Meteor";			//cute but we dont need this tho
	size = 1 + (rand() % 3);	//meteor size between 1 and 3 (random)
	rowCoordinate = 1;
	columnCoordinate = 1;
	ID = 'm';
}
meteor::meteor(int mSize, int rowCoordinateInput, int columnCoordinateInput) {
	//default meteor constructor
	name = "Mr.Meteor";			//cute but we dont need this tho
	size = mSize;
	rowCoordinate = rowCoordinateInput;
	columnCoordinate = columnCoordinateInput;
	ID = 'm';
}

//getters
int meteor::getHealth() {
	return size;
}

int meteor::getResources() {
	//not currently required, function inserted due to virtual function in astroObjects
}

//setters
void meteor::setHealth(int mSize){
	size = (size + mSize);
}

void meteor::setResources(int ssFuel){
	//not currently required, function inserted due to virtual function in astroObjects
}

//deconstructor
meteor::~meteor(){
}