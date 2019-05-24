#ifndef RACER_H
#define RACER_H
#include <string>
#include "spaceship.h"

//Gunship class object
//Subclass of spaceship class
//Ability to move twice as far as gunship at same fuel cost
//Cannot attack

class racer : public spaceship {
public:
	racer();
	racer(std::string, int, int);
	~racer();
	int getHealth();
	int getResources();
	void setHealth(int);
	void setResources(int);
};
#endif