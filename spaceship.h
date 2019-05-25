#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "astroObjects.h"
#include <string>

//Spaceship class object
//To be used as superclass to gunship and racer subclasses
//Possible abstract class
//Polymorphism if needed by using spaceship pointers to gunship and racer objects (space class might cover this)

//Spceship movement depletes fuel
//Ship may be refueled at planets

class spaceship : public astroObjects {
protected:
	int hullHealth;
	int fuel;
public:
	spaceship();
	spaceship(std::string, int, int);
	~spaceship();
	virtual int getHealth() = 0;
	virtual int getResources() = 0;
	virtual void setHealth(int) = 0;
	virtual void setResources(int) = 0;
};
#endif