#ifndef PLANET_H
#define PLANET_H
#include <string>
#include "astroObjects.h"

//Planet class object
//Planets are stationary objects in space
//Spaceships can refuel at planets
//If fuel resources depleted, planet is destroyed

class planet : public astroObjects {
protected:
	int resourceCount;
public:
	planet();										//default constructor
	planet(std::string, int, int, int);				//planet constructor with name, resource count, and x & y coordinates
	~planet();										//default destructor
	int getHealth();
	int getResources();
	void setHealth(int);
	void setResources(int);
};
#endif