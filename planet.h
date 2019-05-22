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
	planet(std::string name, int resourceCount, int rowCoordinateInput, int columnCoordinateInput);	//planet constructor with name, resource count, and x & y coordinates
	virtual ~planet();										//default destructor

	void destroyPlanet();							//destroy planet functions if resources depleted
	int getSize();
};
#endif