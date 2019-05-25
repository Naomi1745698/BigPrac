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
//Version:	0.6
//Date:		25-May-2019
//Status: 	COMPILES


int main()
{
	int mapSize;					//space size variable as user input
	int lowerMapLimit = 5;			//upper and lower map limits
	int upperMapLimit = 20;
	int moveShip = 5;
	bool newGame = true;

	std::cout << std::endl << "OOP SPACEGAME!!!" << std::endl << std::endl;

	while (newGame) {				//new game loop entry

		std::cout << "Enter map grid size from 10 to 20 (e.g. '10' = 10x10): ";				
		std::cin >> mapSize;														//define space (map) size as grid (x*y)
		
		//valid entry check 
		bool inputCheck = true;

		while(inputCheck) {
			if(std::cin.fail() || mapSize < lowerMapLimit || mapSize > upperMapLimit) {
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
		std::string spaceshipName;
		int spaceshipType = -1;
		std::cout << std::endl << "Choose a spaceship type:" <<std::endl;
		std::cout << "1: Gunship - stronger and has a 25% chance of destroying encontered meteors." << std::endl;
		std::cout << "2: Racer - weaker than a Gunship, but is nimbler and has a 50% chance of dodging encountered meteors" << std::endl;	


		std::cin >> spaceshipType;
		while(std::cin.fail() || spaceshipType < 1 || spaceshipType > 2){
			//freshScreen();		
			std::cin.clear();
			std::cin.ignore(1,'\n');
			std::cout << "Please enter a valid input." << std::endl;
			std::cout << "1: Gunship" << std::endl;
			std::cout << "2: Racer" << std::endl;
			std::cin >> spaceshipType;
		}

		std::cout << std::endl << "Please enter the name of your spaceship: ";
		std::cin >> spaceshipName;

		//spaceship(std::string name, int health, int fuel);
		spaceship *playerShip;
		if(spaceshipType == 1) {
			playerShip = new gunship(spaceshipName,10,mapSize*1.5);
		}
		if(spaceshipType == 2) {
			playerShip = new racer(spaceshipName,5,mapSize*1.5);
		}

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
		bool keepPlaying = true;
		spaceMap.printMap();			//space map print
		spaceMap.printShipStatus();		//print ship stats (name, health and fuel)
		
		while (keepPlaying) {
			
			//spaceship movement options by user integer input
			std::cout << "Navigate by entering one of the following options: " << std::endl;
			std::cout << "                 8: move up" << std::endl;
			std::cout << "4: move left     5: stay still     6: move right" << std::endl;
			std::cout << "                 2: move down" << std::endl;
			std::cout << "0: end game" << std::endl;
			std::cin >> moveShip;

			//valid entry check
			
			//run 		if(!std::cin.fail()) into while loop.
			//Add clear library to it.
			inputCheck = true;

			while(inputCheck || moveShip < 0 || moveShip > 9) {
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
					keepPlaying = false;
					break;
				default:
					//std::cout << "Invalid entry. Please enter valid movement options: " << std::endl;
					break;
			}
			spaceMap.printMap();			//space map print
			spaceMap.printShipStatus();		//print ship stats (name, health and fuel)
			spaceMap.meteorMoveControl();	//random automatic movement of meteor objects
			spaceMap.interactionCheck();	//meteor / planet / spaceship interaction

			if (spaceMap.checkWinningCondition() == true || spaceMap.checkShipStatus() == true || keepPlaying == false) {
				keepPlaying = false;
				std::cout << "Would you like to play again?" << std::endl;
				std::cout << "1: Yes, 0: No." << std::endl;
				std::cin >> newGame;

				inputCheck = true;
				while(inputCheck) {
					if(std::cin.fail() || newGame < 0 || newGame > 1) {
						std::cin.clear();
						std::cin.ignore(50,'\n');
						std::cout << "Invalid entry. Please enter 1 to play again or 0 to exit.";		//check to ensure valid integer input
						std::cin >> newGame;
					}
					if(!std::cin.fail())
					inputCheck = false;
					}
				}
			}
	}

	std::cout << "Thanks for playing!" << std::endl;

	return 0;
}