#ifndef ASTROOBJECTS_H
#define ASTROOBJECTS_H
#include <string>

//Space class
//Class to act as base class of Meteor, Planet, and Spaceship objects
//Possibly abstract
//Polymorphism displayed by using space type pointers to Meteor, Planet, and Spaceship objects


class astroObjects {
protected:
	std::string name;
	int size;
	int rowCoordinate;
	int columnCoordinate;

	char ID;

public:
	astroObjects();					//default constructor
	void printName();				//function to print object name

	void printLocation();			//function to print object location - ***POSSIBLY VIRTUAL***
	void setCoordinate(int rowCoordinate, int columnCoordinate);	//set object coordinates for movement reference
	int getRowCoordinate();			//function to return object x coordinate
	int getColumnCoordinate();		//function to return object y coordinate
	char getID();					//function to return object ID

	virtual int getSize() = 0;

	~astroObjects();				//default destructor
};
#endif