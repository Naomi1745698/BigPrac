#include "meteor.h"
#include <iostream>
#include <stdlib.h>


	//setters
	void setSize(int meteorSize);

	//constructors
	~meteor();

//constructors
meteor::meteor() {
	//default meteor constructor
	size = 1 + (rand() % 3);	//meteor size between 1 and 3 (random)
	rowCoordinate = 1;
	columnCoordinate = 1;
	ID = 'm';
}

meteor::meteor(int mSize, int rowCoordinateInput, int columnCoordinateInput) {
	//default meteor constructor
	size = mSize;
	rowCoordinate = rowCoordinateInput;
	columnCoordinate = columnCoordinateInput;
	ID = 'm';
}

//getters
int meteor::getSize() {
	return size;
}

//setters
void meteor::setSize(int meteorSize){
	size = meteorSize;
}


meteor::~meteor() {
}
