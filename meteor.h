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
		
		~meteor();

		int getHealth();
		int getResources();
		void setHealth(int);
		void setResources(int);
	};
	#endif 