#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "space.h"
#include "astroObjects.h"
#include "meteor.h"
#include "spaceship.h"
#include "planet.h"
#include "gunShip.h"
#include "racer.h"

space::space(int mapSize, astroObjects* ship) {
	
	srand(time(NULL));			//reset random number generator every time program runs (does not update otherwise)
	m_mapSize = mapSize;

	meteorCount = 0;
	maxMeteorCount = 1 + (rand() % m_mapSize);		//random number of meteors generated based on map size
	planetCount = 0;
	maxPlanetCount = 1 + (rand() % m_mapSize);		//random number of planets generated based on map size

	row = 0;
	column = 0;

	meteorMap = new astroObjects**[m_mapSize]; 						//allocate a dynamic array of m_mapSize astroObjects pointers (rows)
	planetMap = new astroObjects **[m_mapSize]; 					//allocate a dynamic array of m_mapSize astroObjects pointers (rows)
	spaceshipMap = new astroObjects **[m_mapSize]; 					//allocate a dynamic array of m_mapSize astroObjects pointers (rows)
	
	for (int i = 0; i < m_mapSize; i++) {
		meteorMap[i] = new astroObjects *[m_mapSize]; 				//(columns) dynamic array of astroObjects pointers
		planetMap[i] = new astroObjects *[m_mapSize]; 				//(columns) dynamic array of astroObjects pointers
		spaceshipMap[i] = new astroObjects *[m_mapSize]; 			//(columns) dynamic array of astroObjects pointers
	}

	while (meteorCount < maxMeteorCount) {							//loop to generate meteor objects
		row = rand() % m_mapSize;
		column = rand() % m_mapSize;
		astroObjects* m1 = new meteor;
		meteorMap[row][column] = m1;								//random, dynamic allocation to meteor map
		m1->setCoordinate(row, column);								//set meteor coordinates
		meteorCount++;
	}

	while (planetCount < maxPlanetCount) {							//loop to generate planet objects
		row = rand() % m_mapSize;
		column = rand() % m_mapSize;
		astroObjects* p1 = new planet;
		planetMap[row][column] = p1;								//random, dynamic allocation to planet map
		p1->setCoordinate(row, column);								//set planet coordinates
		planetCount++;
	}


	spaceshipMap[0][0] = ship;				//add player ship to map bottom left corner
	playerShip = ship;

	//NOTE: map spaces not filled with astroObjects are pointers to NULL
}


//print map function
//output varies dependent on whether different objects are located within the same space

//screen clear function still required

void space::printMap() {
	//Rows = i
	//Colums = j
	//inverted the rows to print from bottom left instead of top right
	//loops to check through every array location of meteor, planet and spaceship maps and vary printed output based on astroObject combination
	
	//int amount = 3;
	for(int i = 0; i < 3;i++){
		std::cout << "\n\n\n\n\n\n\n\n\n\n" << std::endl;
	}

	for (int i = m_mapSize - 1; i > -1; i--) {
		for (int j = 0; j < m_mapSize; j++) {
			if (meteorMap[i][j] == NULL && planetMap[i][j] == NULL && spaceshipMap[i][j] == NULL) {			//pointer to NULL space in all three maps
				std::cout << " " << " " << " ";
			}
			else if (meteorMap[i][j] != NULL && planetMap[i][j] == NULL && spaceshipMap[i][j] == NULL) {	//pointer to meteor only
				std::cout << " " << meteorMap[i][j]->getID() << " ";
			}
			else if (meteorMap[i][j] == NULL && planetMap[i][j] != NULL && spaceshipMap[i][j] == NULL) {	//pointer to planet only
				std::cout << " " << planetMap[i][j]->getID() << " ";
			}
			else if (meteorMap[i][j] == NULL && planetMap[i][j] == NULL && spaceshipMap[i][j] != NULL) {	//pointer to spaceship only
				std::cout << " " << spaceshipMap[i][j]->getID() << " ";
			}
			else if (meteorMap[i][j] != NULL && planetMap[i][j] != NULL && spaceshipMap[i][j] == NULL) {	//pointers to meteor and planet in same location
				std::cout << " " << meteorMap[i][j]->getID() << planetMap[i][j]->getID();
			}
			else if (meteorMap[i][j] != NULL && planetMap[i][j] == NULL && spaceshipMap[i][j] != NULL) {	//pointers to meteor and spaceship in same location
				std::cout << " " << meteorMap[i][j]->getID() << spaceshipMap[i][j]->getID();
			}
			else if (meteorMap[i][j] == NULL && planetMap[i][j] != NULL && spaceshipMap[i][j] != NULL) {	//pointers to planet and spaceship in same location
				std::cout << " " << planetMap[i][j]->getID() << spaceshipMap[i][j]->getID();
			}
			else if (meteorMap[i][j] != NULL && planetMap[i][j] != NULL && spaceshipMap[i][j] != NULL) {			//pointers to meteor, planet and spaceship in same location
				std::cout << meteorMap[i][j]->getID() << planetMap[i][j]->getID() << spaceshipMap[i][j]->getID();
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void space::interactionCheck() {
	//Rows = i
	//Colums = j
	//inverted the rows to consider map from bottom left instead of top right
	//loops to check through every array location of meteor, planet and spaceship maps and call appropriate interaction functions
	
	for (int i = m_mapSize - 1; i > -1; i--) {
		for (int j = 0; j < m_mapSize; j++) {
			if (meteorMap[i][j] != NULL && planetMap[i][j] == NULL && spaceshipMap[i][j] != NULL) {	//pointers to meteor and spaceship in same location
				std::cout << " " << meteorMap[i][j]->getID() << spaceshipMap[i][j]->getID();
			}
			else if (meteorMap[i][j] == NULL && planetMap[i][j] != NULL && spaceshipMap[i][j] != NULL) {	//pointers to planet and spaceship in same location
				std::cout << " " << planetMap[i][j]->getID() << spaceshipMap[i][j]->getID();
			}
			else if (meteorMap[i][j] != NULL && planetMap[i][j] != NULL && spaceshipMap[i][j] != NULL) {			//pointers to meteor, planet and spaceship in same location
				std::cout << meteorMap[i][j]->getID() << planetMap[i][j]->getID() << spaceshipMap[i][j]->getID();
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

space::~space() {
	//memory clean-up

	//loops to delete randomly generted astroObjects and playership
	//only if space is not NULL (nothing to delete in NULL space)
	for (int i = 0; i < m_mapSize; i++) {
		for (int j = 0; j < m_mapSize; j++) {
    		if (meteorMap[i][j] != NULL) {
    			delete meteorMap[i][j];
    		}
    		
    		if (planetMap[i][j] != NULL) {
    			delete planetMap[i][j];
    		}
    		
    		if (spaceshipMap[i][j] != NULL) {
    			delete spaceshipMap[i][j];
    		}
    	}
	}
	
	//delete 2-D map arrays
	for (int i = 0; i < m_mapSize; i++) {
    	delete[] meteorMap[i];
    	delete[] planetMap[i];
    	delete[] spaceshipMap[i];
	}
	delete[] meteorMap;
	delete[] planetMap;
	delete[] spaceshipMap;
}

//function to move object up one row (increase y coordinate)
void space::moveUp() {
	astroObjects* temp;											//temporary astroObjects pointer to enable swapping of objects

	int rowCoordinate = playerShip->getRowCoordinate();			//get row and column coordinate values from playerShip object
	int columnCoordinate = playerShip->getColumnCoordinate();

	if (rowCoordinate != (m_mapSize - 1))	{								//edge of space (boundary) check
		if (spaceshipMap[rowCoordinate+1][columnCoordinate] == NULL) {		//if space is empty within map (NULL), move object up
			temp = spaceshipMap[rowCoordinate+1][columnCoordinate]; 
			spaceshipMap[rowCoordinate+1][columnCoordinate] = spaceshipMap[rowCoordinate][columnCoordinate];
			spaceshipMap[rowCoordinate][columnCoordinate] = temp;
			rowCoordinate = (rowCoordinate + 1);						//update object row coordinate (y coordinate)
		}
	}
	else {
		std::cout << "You've reached the boundary of space! Turn back!" << std::endl;		//edge of space reached warning, applicable to spaceship only
	}
	playerShip->setCoordinate(rowCoordinate,columnCoordinate);			//update playerShip new coordinate
}


//function to move object down one row (decrease y coordinate)
void space::moveDown() {
	astroObjects* temp;											//temporary astroObjects pointer to enable swapping of objects

	int rowCoordinate = playerShip->getRowCoordinate();			//get row and column coordinate values from playerShip object
	int columnCoordinate = playerShip->getColumnCoordinate();

	if (rowCoordinate != 0) {												//edge of space (boundary) check
		if (spaceshipMap[rowCoordinate-1][columnCoordinate] == NULL) {		//if space is empty within map (NULL), move object down
			temp = spaceshipMap[rowCoordinate-1][columnCoordinate]; 
			spaceshipMap[rowCoordinate-1][columnCoordinate] = spaceshipMap[rowCoordinate][columnCoordinate];
			spaceshipMap[rowCoordinate][columnCoordinate] = temp;
			rowCoordinate = (rowCoordinate - 1);						//update object row coordinate (y coordinate)
		}
	}
	else {
		std::cout << "You've reached the boundary of space! Turn back!" << std::endl;		//edge of space reached warning, applicable to spaceship only
	}
	playerShip->setCoordinate(rowCoordinate,columnCoordinate);			//update playerShip new coordinate
}


//function to move object left one column (decrease x coordinate)
void space::moveLeft() {
	astroObjects* temp;											//temporary astroObjects pointer to enable swapping of objects

	int rowCoordinate = playerShip->getRowCoordinate();			//get row and column coordinate values from playerShip object
	int columnCoordinate = playerShip->getColumnCoordinate();
	
	if (columnCoordinate != 0) {											//edge of space (boundary) check
		if (spaceshipMap[rowCoordinate][columnCoordinate-1] == NULL) {		//if space is empty within map (NULL), move object left
			temp = spaceshipMap[rowCoordinate][columnCoordinate-1]; 
			spaceshipMap[rowCoordinate][columnCoordinate-1] = spaceshipMap[rowCoordinate][columnCoordinate];
			spaceshipMap[rowCoordinate][columnCoordinate] = temp;
			columnCoordinate = (columnCoordinate - 1);					//update object column coordinate (x coordinate)
		}
	}
	else {
		std::cout << "You've reached the boundary of space! Turn back!" << std::endl;		//edge of space reached warning, applicable to spaceship only
	}
	playerShip->setCoordinate(rowCoordinate,columnCoordinate);			//update playerShip new coordinate
}

//function to move object right one column (increase x coordinate)
void space::moveRight() {
	astroObjects* temp;											//temporary astroObjects pointer to enable swapping of objects

	int rowCoordinate = playerShip->getRowCoordinate();			//get row and column coordinate values from playerShip object
	int columnCoordinate = playerShip->getColumnCoordinate();

	if (columnCoordinate != (m_mapSize - 1)) {								//edge of space (boundary) check
		if (spaceshipMap[rowCoordinate][columnCoordinate+1] == NULL) {		//if space is empty within map (NULL), move object left
			temp = spaceshipMap[rowCoordinate][columnCoordinate+1]; 
			spaceshipMap[rowCoordinate][columnCoordinate+1] = spaceshipMap[rowCoordinate][columnCoordinate];
			spaceshipMap[rowCoordinate][columnCoordinate] = temp;
			columnCoordinate = (columnCoordinate + 1);					//update object column coordinate (x coordinate)
		}
	}
	else {
		std::cout << "You've reached the boundary of space! Turn back!" << std::endl;		//edge of space reached warning, applicable to spaceship only
	}
	playerShip->setCoordinate(rowCoordinate,columnCoordinate);			//update playerShip new coordinate
}

void space::printShipStatus(){
	//CALL BOTH FUEL, NAME AND HEALTH STATUS	
	//PRINT IT OUT.
};