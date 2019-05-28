#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "space.h"
#include "gunShip.h"
#include "racer.h"

space::space(int mapSize, astroObjects* ship) {
	
	srand(time(NULL));			//reset random number generator every time program runs (does not update otherwise)
	m_mapSize = mapSize;

	meteorCount = 0;
	maxMeteorCount =  (m_mapSize + (rand() % m_mapSize));		//random number of meteors generated based on map size
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
		row = rand() %  m_mapSize;
		column = rand() % m_mapSize;
		if (meteorMap[row][column] == NULL || ( row != 0 && column != 0 ) ) {	//stops the player ship from starting in the same spot as a meteor
			astroObjects* m1 = new meteor;
			meteorMap[row][column] = m1;								//random, dynamic allocation to meteor map
			m1->setCoordinate(row, column);								//set meteor coordinates
			meteorCount++;
		}
	}

	while (planetCount < maxPlanetCount) {							//loop to generate planet objects
		row = rand() % m_mapSize;
		column = rand() % m_mapSize;
		if (planetMap[row][column] == NULL || ( row+m_mapSize != 0 && column != 0 ) ) {	//stops the player ship from starting in the same spot as a planet
			astroObjects* p1 = new planet;
			planetMap[row][column] = p1;								//random, dynamic allocation to planet map
			p1->setCoordinate(row, column);								//set planet coordinates
			planetCount++;
		}
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
	
	//leaves a gap
	for(int i = 0; i < 20;i++) {
		std::cout << "\n" << std::endl;
	}

	std::cout << "-";
	for(int i = 0; i < m_mapSize;i++) {
		std::cout << "------";
	}
	std::cout << std::endl;

	for (int i = m_mapSize - 1; i > -1; i--) {
		std::cout << "|";
		for (int j = 0; j < m_mapSize; j++) {
			if (spaceshipMap[i][j] == NULL && i == (m_mapSize - 1) && j == (m_mapSize - 1)) {				//print destination
				std::cout << " " << " " << "X" << " " << " " << "|";
			}
			else if (meteorMap[i][j] == NULL && planetMap[i][j] == NULL && spaceshipMap[i][j] == NULL) {	//pointer to NULL space in all three maps
				std::cout << " " << " " << " " << " " << " " << "|";
			}
			else if (meteorMap[i][j] != NULL && planetMap[i][j] == NULL && spaceshipMap[i][j] == NULL) {	//pointer to meteor only
				std::cout << " " << "o--" << " " << "|";
			}
			else if (meteorMap[i][j] == NULL && planetMap[i][j] != NULL && spaceshipMap[i][j] == NULL) {	//pointer to planet only
				std::cout << " " << "(" << " " << ")" << " " << "|";
			}
			else if (meteorMap[i][j] == NULL && planetMap[i][j] == NULL && spaceshipMap[i][j] != NULL) {	//pointer to spaceship only
				std::cout << " " << "/" << "^" << "\\" << " " << "|";
			}
			else if (meteorMap[i][j] != NULL && planetMap[i][j] != NULL && spaceshipMap[i][j] == NULL) {	//pointers to meteor and planet in same location
				std::cout << "o-" << " " << "()" << "|";
			}
			else if (meteorMap[i][j] != NULL && planetMap[i][j] == NULL && spaceshipMap[i][j] != NULL) {	//pointers to meteor and spaceship in same location
				std::cout << "^" << " " << "o-" << "|";
			}
			else if (meteorMap[i][j] == NULL && planetMap[i][j] != NULL && spaceshipMap[i][j] != NULL) {	//pointers to planet and spaceship in same location
				std::cout << " " << "(" << "^" << ")" << " " << "|";
			}
			else if (meteorMap[i][j] != NULL && planetMap[i][j] != NULL && spaceshipMap[i][j] != NULL) {	//pointers to meteor, planet and spaceship in same location
				std::cout << "o-" << "(" << "^" << ")" << "|";
			}
		}
		std::cout << std::endl;
		std::cout << "-";
		for(int k = 0; k < m_mapSize;k++) {
			std::cout << "------";
		}
		std::cout << std::endl;
	}
	std::cout << "Key:\n     ^ = player ship\n     o-- = meteor (watch out!)\n     ( ) = planet (refuel / repair ship)\n     X = destination\n" << std::endl;
}


void space::interactionCheck() {
	//Rows = i
	//Colums = j
	//inverted the rows to consider map from bottom left instead of top right
	//loops to check through every array location of meteor, planet and spaceship maps and call appropriate interaction functions

	int meteorDestroyCheck = (rand() % 4);				//random meteor destroy check, 0 = destroy, 1,2,3 = hit
	int meteorDodgeCheck = (rand() % 2);				//random meteor dodge check, 0 = dodge, 1 = hit

	if (spaceshipMap[m_mapSize - 1][m_mapSize - 1] != NULL) {	//check winning condition
		destinationReached = true;
	}
	else {
		for (int i = m_mapSize - 1; i > -1; i--) {
			for (int j = 0; j < m_mapSize; j++) {	//pointers to planet and spaceship in same location
				if (meteorMap[i][j] != NULL && planetMap[i][j] == NULL && spaceshipMap[i][j] != NULL) {			//pointers to meteor and spaceship in same location
					if (playerShip->getID() == 'g' && meteorDestroyCheck == 0) {															//if using gunship, meteor destroyed
						std::cout << "###   Meteor targeted ....... meteor destroyed!   ###" << std::endl << std::endl;
						delete (meteor*)meteorMap[i][j];															//meteor destroyed (deleted) on impact
						meteorMap[i][j] = NULL;	
					}
					else if (playerShip->getID() == 'r' && meteorDodgeCheck == 0) {															//if using racer, meteor dodged
						std::cout << "###   Meteor avoided!   ###" << std::endl;
					}
					else {
						spaceshipMap[i][j]->setHealth(-1 * meteorMap[i][j]->getHealth());							//apply damage to spaceship based on meteor size
						std::cout << std::endl << "###   Meteor encountered - you've been hit!! " << meteorMap[i][j]->getHealth() << " damage taken to the hull! ###" << std::endl << std::endl;
						delete (meteor*)meteorMap[i][j];															//meteor destroyed (deleted) on impact
						meteorMap[i][j] = NULL;
					}
				}	
				else if (meteorMap[i][j] == NULL && planetMap[i][j] != NULL && spaceshipMap[i][j] != NULL) {	//pointers to planet and spaceship in same location
					int action = 0;
					bool inputCheck = true;
					std::cout << std::endl << "You have safely landed on planet. Do you want to 1: repair, or 3: refuel?" << std::endl;					//message notifying player of landing on planet with repair or refuel options
					std::cout << "Any input between 0 - 9 (other than 1 and 3) will end your turn." << std::endl;
					std::cin >> action;

					while(inputCheck) {									//check for valid user input
						if(std::cin.fail() || action < 0 || action > 9) {
							std::cin.clear();
							std::cin.ignore(50,'\n');
							std::cout << "Invalid entry. Please enter valid input options: ";		//check to ensure valid integer input
							std::cin >> action;
						}
						if(!std::cin.fail())
							inputCheck = false;			//check to enable exit from while loop
						}

						switch (action) {				//spaceship repair or refuel action checks
							case 1:						//repair ship option
								spaceshipMap[i][j]->setHealth(1);
								planetMap[i][j]->setResources(-1);
								break;
							case 3:						//refuel ship options
								spaceshipMap[i][j]->setResources(2);
								planetMap[i][j]->setResources(-1);
								break;
							default:
								break;
						}
						if (planetMap[i][j]->getResources() == 0) {		//planet resource depletion check
							std::cout << std::endl << "You've used all the planet's resources! The planet has been destroyed!" << std::endl;
							std::cout << "A great disturbance was felt across space, as millions of voices cried out in terror and were suddenly silenced." << std::endl << std::endl;
							delete (planet*)planetMap[i][j];			//planet destroyed (deleted) on resource depletion - is removed from map in the next turn
							planetMap[i][j] = NULL;

						}
					}
				}
			}
	}
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
	playerShip->setResources(-1);										//update playerShip fuel
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
	playerShip->setResources(-1);										//update playerShip fuel
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
	playerShip->setResources(-1);										//update playerShip fuel
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
	playerShip->setResources(-1);										//update playerShip fuel
}


//meteor movement control based on random integer
void space::meteorMoveControl() {

	int meteorMove = 0;
	astroObjects* tempMeteor;

	for (int i = m_mapSize - 1; i > -1; i--) {		//loops to search through meteor map
		for (int j = 0; j < m_mapSize; j++) {
			if (meteorMap[i][j] != NULL) {			//check to find and apply movement to generated meteor objects only
				meteorMove = rand() % 4;			//random movement around map
				tempMeteor = meteorMap[i][j];
				switch (meteorMove) {
						case 0: moveMeteorUp(tempMeteor);
							break;
						case 1: moveMeteorDown(tempMeteor);
							break;
						case 2: moveMeteorLeft(tempMeteor);
							break;
						case 3: moveMeteorRight(tempMeteor);
							break;
						default: break;
				}
			}
		}
	}
}


//meteor movement functions

//function to move object up one row (increase y coordinate)
void space::moveMeteorUp(astroObjects* tempMeteor) {
	astroObjects* temp;											//temporary astroObjects pointer to enable swapping of objects

	int rowCoordinate = tempMeteor->getRowCoordinate();			//get row and column coordinate values from meteor object
	int columnCoordinate = tempMeteor->getColumnCoordinate();

	if (rowCoordinate != (m_mapSize - 1))	{								//edge of space (boundary) check
		if (meteorMap[rowCoordinate+1][columnCoordinate] == NULL) {		//if space is empty within map (NULL), move object up
			temp = meteorMap[rowCoordinate+1][columnCoordinate]; 
			meteorMap[rowCoordinate+1][columnCoordinate] = meteorMap[rowCoordinate][columnCoordinate];
			meteorMap[rowCoordinate][columnCoordinate] = temp;
			rowCoordinate = (rowCoordinate + 1);						//update object row coordinate (y coordinate)
		}
	}
	tempMeteor->setCoordinate(rowCoordinate,columnCoordinate);			//update meteor coordinate
}

//function to move object down one row (decrease y coordinate)
void space::moveMeteorDown(astroObjects* tempMeteor) {
	astroObjects* temp;											//temporary astroObjects pointer to enable swapping of objects

	int rowCoordinate = tempMeteor->getRowCoordinate();			//get row and column coordinate values from meteor object
	int columnCoordinate = tempMeteor->getColumnCoordinate();

	if (rowCoordinate != 0) {												//edge of space (boundary) check
		if (meteorMap[rowCoordinate-1][columnCoordinate] == NULL) {		//if space is empty within map (NULL), move object down
			temp = meteorMap[rowCoordinate-1][columnCoordinate]; 
			meteorMap[rowCoordinate-1][columnCoordinate] = meteorMap[rowCoordinate][columnCoordinate];
			meteorMap[rowCoordinate][columnCoordinate] = temp;
			rowCoordinate = (rowCoordinate - 1);						//update object row coordinate (y coordinate)
		}
	}
	tempMeteor->setCoordinate(rowCoordinate,columnCoordinate);			//update meteor coordinate
}

//function to move object left one column (decrease x coordinate)
void space::moveMeteorLeft(astroObjects* tempMeteor) {
	astroObjects* temp;											//temporary astroObjects pointer to enable swapping of objects

	int rowCoordinate = tempMeteor->getRowCoordinate();			//get row and column coordinate values from meteor object
	int columnCoordinate = tempMeteor->getColumnCoordinate();
	
	if (columnCoordinate != 0) {											//edge of space (boundary) check
		if (meteorMap[rowCoordinate][columnCoordinate-1] == NULL) {		//if space is empty within map (NULL), move object left
			temp = meteorMap[rowCoordinate][columnCoordinate-1]; 
			meteorMap[rowCoordinate][columnCoordinate-1] = meteorMap[rowCoordinate][columnCoordinate];
			meteorMap[rowCoordinate][columnCoordinate] = temp;
			columnCoordinate = (columnCoordinate - 1);					//update object column coordinate (x coordinate)
		}
	}
	tempMeteor->setCoordinate(rowCoordinate,columnCoordinate);			//update meteor coordinate
}

//function to move object right one column (increase x coordinate)
void space::moveMeteorRight(astroObjects* tempMeteor) {
	astroObjects* temp;											//temporary astroObjects pointer to enable swapping of objects

	int rowCoordinate = tempMeteor->getRowCoordinate();			//get row and column coordinate values from meteor object
	int columnCoordinate = tempMeteor->getColumnCoordinate();

	if (columnCoordinate != (m_mapSize - 1)) {								//edge of space (boundary) check
		if (meteorMap[rowCoordinate][columnCoordinate+1] == NULL) {		//if space is empty within map (NULL), move object left
			temp = meteorMap[rowCoordinate][columnCoordinate+1]; 
			meteorMap[rowCoordinate][columnCoordinate+1] = meteorMap[rowCoordinate][columnCoordinate];
			meteorMap[rowCoordinate][columnCoordinate] = temp;
			columnCoordinate = (columnCoordinate + 1);					//update object column coordinate (x coordinate)
		}
	}
	tempMeteor->setCoordinate(rowCoordinate,columnCoordinate);			//update meteor coordinate
}


//function to print status of ship (name, health and fuel)
void space::printShipStatus(){
	std::cout << "##############################" << std::endl;
	std::cout << "#   " << playerShip->getName() << " Status Report" << std::endl;
	std::cout << "#   Health: " << playerShip->getHealth();
	if (playerShip->getHealth() < 3) {
		std::cout << "  # Warning: Health Low";
	}
	std::cout << std::endl << "#   Fuel: " << playerShip->getResources();
	if (playerShip->getResources() < (m_mapSize / 1.5)) {
		std::cout << "  # Warning: Fuel Low";
	}
	std::cout << std::endl << "##############################" << std::endl << std::endl;
}

//check if spaceship has reached destination (top right map corner)
bool space::checkWinningCondition() {
	if (destinationReached == true) {
		std::cout << std::endl << "Congradulations!\nYou have safely reached your destination!" << std::endl << "Game over!\n" << std::endl;
	}
	return destinationReached;
}

//check if spaceship has used all fuel or has been too damaged
bool space::checkShipStatus() {
	if (playerShip->getHealth() < 1) {
		std::cout << std::endl << "Your ship has been destroyed!" << std::endl << "Game over!" << std::endl << std::endl;
		destinationReached = true;
	}
	if (playerShip->getResources() == 0) {
		std::cout << std::endl << "Your ship has run out of fuel!" << std::endl << "Game over!" << std::endl << std::endl;
		destinationReached = true;
	}
	return destinationReached;
}

//function to delete the map via loop
void space::deleteMap() {
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

space::~space() {
	//the default astroObjects destructor :D

}