#ifndef SPACE_H
#define SPACE_H
#include "astroObjects.h"
#include "meteor.h"
#include "planet.h"
#include "spaceship.h"


class space
{
protected:
	int m_mapSize;		//map size variable
	int row, column;	// map row and column references

	astroObjects*** meteorMap;		//meteor map 2-D array of pointers to astroObjects
	int meteorCount;				//meteor counter
	int maxMeteorCount;				//maximum meteor number

	astroObjects*** planetMap;		//meteor map 2-D array of pointers to astroObjects
	int planetCount;				//planet counter
	int maxPlanetCount;				//maximum planet number
	
	astroObjects*** spaceshipMap;	//spaceship map 2-D array of pointers to astroObjects
	astroObjects* playerShip;		//player ship pointer
	bool destinationReached = false;


public:
	space(int, astroObjects*);
	void printMap();
	void deleteMap();
	~space();

	//functions to move astroObjects
	//bool spaceshipMoveControl();
	void moveUp();
	void moveDown();				//spaceship control functions
	void moveLeft();
	void moveRight();
	void meteorMoveControl();
	void moveMeteorUp(astroObjects*);
	void moveMeteorDown(astroObjects*);			//meteor control functions
	void moveMeteorLeft(astroObjects*);
	void moveMeteorRight(astroObjects*);

	void interactionCheck();		//check function for object interaction
	void printShipStatus();			//print ship status (health and fuel)
	bool checkWinningCondition();	//check if ship has reached destination
	bool checkShipStatus();			//check if ship is out of fuel or too damaged
};
#endif