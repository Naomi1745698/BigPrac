#ifndef METEOR_H
#define METEOR_H
#include "astroObjects.h"


//Meteor class object
//Moves around map automatically
//Damages encountered spaceship
//Damage dealt is based on meteor size


class meteor : public astroObjects {
public:
	meteor();
	meteor(int size, int rowCoordinate, int columnCoordinate);
	virtual ~meteor();
	int getSize();
};
#endif