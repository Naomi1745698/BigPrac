#include <string>
#include <iostream>
#include "astroObjects.h"
#include "meteor.h"
#include "spaceship.h"
#include "planet.h"
#include "gunShip.h"
#include "racer.h"
#include "space.h"
#include <ctime>
//Spaceship Game!!
//Version:	0.5
//Date:		18-May-2019
//Status: 	COMPILES

//Notes: 	Makefile created.
//			Original space class renamed to astroObjects
//			New space class is the container class for astroObjects
//			Three separate astroObjects maps are created within space (meteor, planet & spaceship)
//			Map print varies depending on astroObject location overlaps
//			Spaceship movement is controlled by the space class. Spaceship coordinates are passed back and forth from the spaceship object
//
//	TO-DO
//			Spaceship movement function might be added to spaceship superclass to allow different spaceship movement actions
//			Meteor movements can be controlled by space class (suggest making them random to simplify coding)
//			Planets do not move (but could if we wanted them to)
//
//			Ship take damage or meteor give damage and meteor destructor required upon spaceship and meteor object overlap
//				(damage automatic and based on meteor size - spaceship getHealth and meteor getSize probably needed)
//
//			Ship refuel and planet destruction required upon spaceship and planet overlap (option to refuel)
//
//			Add option for user to choose spaceship type


// -Allow player to enter name and spaceship type. - note not fully added in.
// -freshScreen function // Might want to find a alternative way. 
// -Added time delay.

//void freshScreen();


int main()
{
	int mapSize;					//space size variable as user input
	int moveShip = 5;				//use movement input integer
	int lowerMapLimit = 5;			//upper and lower map limits
	int upperMapLimit = 20;

	//freshScreen();
	std::cout << "Enter map grid size from 5 to 20 (e.g. '5' = 5x5): ";				
	std::cin >> mapSize;														//define space (map) size as grid (x*y)
	
	//valid entry check 
	bool inputCheck = true;

	while(inputCheck) {
		if(std::cin.fail() || mapSize < lowerMapLimit || mapSize > upperMapLimit) {
			//freshScreen();
			std::cin.clear();
			std::cin.ignore(50,'\n');
			std::cout << "Invalid entry. Please enter map grid size from 5 to 10 (e.g. '5' = 5x5): ";		//check to ensure valid integer input
			std::cin >> mapSize;
		}
		if(!std::cin.fail())
		inputCheck = false;
	};


	//ignores previous entries that were used.
	std::cin.ignore();
	//Player details to be added.
	char spaceshipName[20];
	int spaceshipType = -1;
	std::cout << "Please enter the name of your spaceship: ";
	std::cin.getline(spaceshipName,20);
	std::cout << "Great! lets get started" << std::endl;
	std::cout << "Gunship or Racer spaceship?" <<std::endl;
	std::cout << "1:Gunship" << std::endl << "2:Racer" << std::endl;	
	//----------issue if the user spams enter!---------------//
	/*
	while(std::cin.get() == '\n'){
		std::cout << "Good job" << std::endl;
		freshScreen();
		std::cout << "Please enter a valid input" << std::endl;
		std::cout << "1:Gunship" << std::endl;
		std::cout << "2:Racer" << std::endl;	
		}
		*/


	std::cin >> spaceshipType;
	while(std::cin.fail() || spaceshipType < 1 || spaceshipType > 2){
		//freshScreen();		
		std::cin.clear();
		std::cin.ignore(1,'\n');
		std::cout << "Please enter a valid input" << std::endl;
		std::cout << "1:Gunship" << std::endl;
		std::cout << "2:Racer" << std::endl;
		//----------issue if the user spams enter!---------------//
		/*
		while(std::cin.get() == '\n'){
			std::cout << "Good job" << std::endl;
			freshScreen();
			std::cout << "Please enter a valid input" << std::endl;
			std::cout << "1:Gunship" << std::endl;
			std::cout << "2:Racer" << std::endl;
		}
		*/
		//std::cin.ignore();
		std::cin >> spaceshipType;
		//if(std::cin.fail()){
		//	spaceshipType = -1;
		//}

	}


	//spaceship(std::string name, int fuel);
	spaceship *playerShip;
	if(spaceshipType == 1){
		playerShip = new gunship(spaceshipName,2*mapSize);
	}
	if(spaceshipType == 2){
	playerShip = new racer(spaceshipName,mapSize);
	}
	//racer or gunship type ship to be input by user 
	//spaceship *playerShip = new racer();

	std::cout << "Building your spaceship..." << std::endl;
	//creating the map
	space spaceMap(mapSize, playerShip);
	//Adding time delay of roughly 1 second. 
	/*
	time_t setTime;
	setTime = time(NULL);
	time_t currentTime;
	bool Timeup = false;
	while(Timeup == false){
		currentTime = time(NULL);
		if((currentTime - setTime > 1)){
			Timeup = true;
		}
	};
	*/
	//end game option 
	bool keepPlaying;
	keepPlaying = true;


	while(keepPlaying) {
		//freshScreen();
		spaceMap.printMap();		//space map print
		//spaceMap.interactionCheck();

		//spaceship movement options by user integer input
		std::cout << "Navigate by entering options 1 - 5: " << std::endl;
		std::cout << "Enter 8 to move up" << std::endl;
		std::cout << "Enter 2 to move down" << std::endl;
		std::cout << "Enter 4 to move left" << std::endl;
		std::cout << "Enter 6 to move right" << std::endl;
		std::cout << "Enter 5 to remain still" << std::endl;
		std::cout << "Enter 0 to end game" << std::endl;
		std::cin >> moveShip;

		//valid entry check
		
		//run 		if(!std::cin.fail()) into while loop.
		//Add clear library to it.
		inputCheck = true;

		while(inputCheck) {
			if(std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(50,'\n');
				std::cout << "Invalid entry. Please enter valid movement options: ";		//check to ensure valid integer input
				std::cin >> moveShip;
			}
			if(!std::cin.fail())
			inputCheck = false;
		}
	
		switch (moveShip) {
			case 8: spaceMap.moveUp();
				break;
			case 4: spaceMap.moveLeft();
				break;
			case 5:
				break;
			case 6: spaceMap.moveRight();
				break;
			case 2: spaceMap.moveDown();
				break;
			case 0:
				std::cout << "Game over!" << std::endl;
				keepPlaying = false;
				break;
			default:
				std::cout << "Invalid entry. Please enter valid movement options: " << std::endl;
				break;
		}
	}

	//dynamic memory clean-up
	// spaceMap.deleteMap();
	//delete playerShip????
	return 0;
}