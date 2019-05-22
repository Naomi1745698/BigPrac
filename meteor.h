#ifndef METEOR_H
#define METEOR_H

//meteors move around the map randomly by 1-block each move
//if a spaceship hits the meteor, health is deducted (this function is on the spaceship.h file)

class meteor:public astroobjects{

public:
	//constructors
	meteor();

	//setters
	void move();

	//constructors
	~meteor();
	
};

#endif