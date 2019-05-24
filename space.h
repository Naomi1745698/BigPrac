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


public:
	space(int mapSize, astroObjects* ship);
	void printMap();
	void deleteMap();
	~space();

	//functions to move astroObjects
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void meteorMoveControl();
	void moveMeteorUp();
	void moveMeteorDown();
	void moveMeteorLeft();
	void moveMeteorRight();
	void interactionCheck();
	void printShipStatus();
};
#endif