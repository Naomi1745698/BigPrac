#ifndef GUNSHIP_H
#define GUNSHIP_H
#include <string>
#include "spaceship.h"

//Gunship class object
//Subclass of spaceship class
//Ability to attack meteors
//Movement and attacks deplete fuel

class gunship : public spaceship {
public:
	gunship();
	gunship(std::string, int, int);
	//Movements from virtual classes
	~gunship();
	int getHealth();
	int getResources();
	void setHealth(int);
	void setResources(int);
};
#endif