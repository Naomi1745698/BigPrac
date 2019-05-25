#ifndef METEOR_H
#define METEOR_H
#include "astroObjects.h"


//meteors move around the map randomly by 1-block each move
//if a spaceship hits the meteor, health is deducted (this function is on the spaceship.h file)
//damage delt is based on meteor size (1,2, or 3)



class meteor : public astroObjects {
private:
	int size;			//1 = smol, 1 damage. 2 = medium, 2 damage, 3 = big, 3 damagae

public:
	//constructors
	meteor();
	meteor(int size, int rowCoordinateInput, int columnCoordinateInput);

	//getters
	int getSize();

	//setters
	void setSize(int meteorSize);

	//constructors
	~meteor();
};
#endif
