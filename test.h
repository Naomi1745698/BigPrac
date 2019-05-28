#ifndef TEST_H
#define TEST_H
#include "test.h"
#include <iostream>
#include <string>
#include <iostream>
#include "astroObjects.h"
#include "meteor.h"
#include "spaceship.h"
#include "planet.h"
#include "gunShip.h"
#include "racer.h"
#include "space.h"
#include <ctime>
#include <cstring>
#include <cctype>
class test {
public:
	std::string spaceshipName;
	spaceship *playerShip;
	spaceship *playerShip1;
	astroObjects *planet1;
	astroObjects *meteor1;
	//astroObjects* planet1;
	//planet related variables
	std::string planetResourceName = "K9";
	int startResources = 20;

	//Common for all	
	int health = 100;
	int addHealth = 50;
	int addResources = 50;
	int fuel = 20;
	int PASS = 0;
	//Meteor related variable
	int meteorSize = 25;
	test();
	void mapTesting();
	void gunShipTesting();
	void racerTesting();
	void planetTesting();
	void meteorTesting();
	void boundaryTesting();
	~test();
};
#endif