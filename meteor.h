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
		meteor(int mSize, int rowCoordinateInput, int columnCoordinateInput);
		int getHealth();
		int getResources();					//dont use, just here because the virtual function
		void setHealth(int mSize);
		void setResources(int ssFuel);		//dont use, just here because the virtual function
		~meteor();

	};
	#endif 