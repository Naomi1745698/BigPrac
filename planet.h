#ifndef PLANET_H
#define PLANET_H
#include <string>
#include "astroObjects.h"
using namespace std;

//Planet class object
//Planets are stationary objects in space
//Spaceships can refuel at planets
//If fuel resources depleted, planet is destroyed
//planets are either 'fuel' types OR 'health' types - this is decided by variable 'name'

class planet : public astroObjects {
protected:
	int resourceCount;
public:
	planet();
	planet(string resourceType, int resources, int rowCoordinateInput, int columnCoordinateInput);
	string getName();
	int getHealth();				//dont use, just here because the virtual function
	int getResources();
	void setHealth(int);			//dont use, just here because the virtual function
	void setResources(int);
	~planet();

};
#endif