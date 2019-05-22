#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "astroObjects.h"
#include <string>

//Spaceship class object
//To be used as superclass to guunship and racer subclasses
//Possible abstract class
//Polymorphism if needed by using spaceship pointers to gunship and racer objects (space class might cover this)

//Spceship movement depletes fuel
//Ship may be refueled at planets

class spaceship : public astroObjects {
protected:
	int hullHealth;
	float fuel;
public:
	spaceship();
	spaceship(std::string name, float fuel);
	virtual ~spaceship();
	friend int geFuel();
	virtual int getSize() = 0;
};
#endif