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
#include "test.h"
#include <cstring>
#include <cctype>
//Spaceship Game!!
//Version:	0.7
//Date:		29-May-2019
//Status: 	COMPILES

#define UP 3
#define DOWN 2
#define RIGHT 5
#define LEFT 4


//time delay function to have an intro slide (Set to 0.1 seconds so input can be integers)
void delay(unsigned int deci){
  deci = deci*100000;
  clock_t goal = deci + clock();
  while (goal > clock());
}

//function that leaves a gap
void gap (int distance){
	for(int i = 0; i < distance;i++) {
		std::cout << "\n" << std::endl;
	}
}

int main()
{
	//Testing functions

	//test Tester = test();
	//Tester.gunShipTesting();
	//Tester.racerTesting();
	//Tester.planetTesting();
	//Tester.meteorTesting();
	//Tester.mapTesting();
	//Tester.boundaryTesting();


	int mapSize;					//space size variable as user input
	int lowerMapLimit = 5;			//upper and lower map limits
	int upperMapLimit = 20;
	int moveShip = 5;
	bool newGame = true;

	gap(30);

	//intro text!
	std::cout << "Hello.\n" << std::endl;
	delay (10);
	std::cout << "You are about to enter into a dangerous new realm in space.\n" << std::endl;
	delay (25);
	std::cout << "Your mission is to get to the other side of the board.\n" << std::endl;
	delay (20);
	std::cout << "Try to avoid meteors as they will harm your ship.\n" << std::endl;
	delay (20);
	std::cout << "Visit planets to gather resources to help you on your journey.\n" << std::endl;
	delay (25);
	std::cout << "Be wary about using all the resouces on a planet, however.\n" << std::endl;
	delay (25);
	std::cout << "Best of luck. Press anything to continue.\n" << std::endl;
	std::cin.ignore();


	std::string mapSizeInput;
	char Word[10];
	int wordCount = 0;

	while (newGame) {				//new game loop entry

		bool checkingInput = true;
		bool validNum = true;
		while(checkingInput){
			std::cout << "\n\nEnter map grid size from 6 to 20 (e.g. '10' = 10x10): ";		
			std::cin >> mapSizeInput;
			//Creates a char array storing the entries of mapSizeInput.
			int inputwordlength = mapSizeInput.size()+1;
			char *enteredNum = new char[inputwordlength];
			validNum = true;
			strcpy(enteredNum,&mapSizeInput[0]);

			for(int i = 0;i<inputwordlength;i++){
				//std::cout << *(enteredNum+i) << std::endl;
				if(*(enteredNum+i) == '.' || isalpha(*(enteredNum+i))){
					//std::cout << "warning, please enter a integer!" << std::endl;
					delete[] enteredNum;
					enteredNum = new char[inputwordlength];
					for(int i = 0; i<inputwordlength;i++){
						*(enteredNum+i) = NULL;
					}
				}
			}

			//checks if a valid input has been entered.
			if(*(enteredNum) == NULL){
				validNum = false;
			}
			//test for these conditions before setting mapSize.
			if(atoi(enteredNum) > lowerMapLimit && atoi(enteredNum) < upperMapLimit+1 && validNum == true){
				mapSize = atoi(enteredNum); //define space (map) size as grid (x*y)
				checkingInput = false;
			}else{
				std::cout << "Warning, please enter a integer in the range from 6 to 20" << std::endl;
			}
		}
		//ignores previous entries that were used.
		std::cin.ignore();
		//Player details to be added.
		std::string spaceshipName;
		int spaceshipType = -1;
		std::cout << std::endl << "Choose a spaceship type:" <<std::endl;
		std::cout << "1: Gunship - stronger and has a 25% chance of destroying encontered meteors." << std::endl;
		std::cout << "2: Racer - weaker than a Gunship, but is nimbler and has a 50% chance of dodging encountered meteors" << std::endl;
		std::cout << "\nEnter a number (1 or 2): ";
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
		delay (5);
		std::cout << "..." << std::endl;
		delay (4);
		std::cout << "......" << std::endl;
		delay (4);
		std::cout << "........." << std::endl;
		delay (4);

		gap(30);

		cout << "      /==============================================\\"	<< endl;
		cout << "      |                           o             *    |"		<< endl;
		cout << "      |     *       *         *         .   o--      |"		<< endl;
		cout << "      |                                              |"		<< endl;
		cout << "      |               *           ( )                |"		<< endl;
		cout << "      |        o                          *       o  |"		<< endl;
		cout << "      |             ( )      o                       |"		<< endl;
		cout << "      |  *                         *                 |"		<< endl;
		cout << "      |   --o                          *      ( )    |"		<< endl;
		cout << "      |          o   Welcome to space!       *       |"		<< endl;
		cout << "      |    *                  .                      |"		<< endl;
		cout << "      |                 *            .               |"		<< endl;
		cout << "      |  --o       o            *               *    |"		<< endl;
		cout << "      |                          ( )    *            |"		<< endl;
		cout << "      |      .           o--        .                |"		<< endl;
		cout << "      |          (_)           o            ( )      |"		<< endl;
		cout << "      |                              *               |"		<< endl;
		cout << "      |      *    --o                                |"		<< endl;
		cout << "      |                 *         -          o       |"		<< endl;
		cout << "      |                                              |"		<< endl;
		cout << "      \\==============================================/"	<< endl;

		gap(6);
		delay (30);

		//creating 0the map
		space spaceMap(mapSize, playerShip);

		//end game option 
		bool keepPlaying = true;
		spaceMap.printMap();			//space map print
		spaceMap.printShipStatus();		//print ship stats (name, health and fuel)
		
		while (keepPlaying) {
			
			//spaceship movement options by user integer input
			std::cout << "Navigate by entering one of the following options: " << std::endl;
			std::cout << "                 8 move up" << std::endl;
			std::cout << "4: move left     5: stay still     6: move right" << std::endl;
			std::cout << "                 2: move down" << std::endl;
			std::cout << "0: end game" << std::endl;
			std::cin >> moveShip;

			//valid entry check
			
			//run 		if(!std::cin.fail()) into while loop.
			//Add clear library to it.
			bool inputCheck = true;

			while(inputCheck) {
				if(std::cin.fail() || moveShip < 0 || moveShip > 9) {
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
			spaceMap.meteorMoveControl();	//random automatic movement of meteor objects
			spaceMap.printMap();			//space map print
			spaceMap.printShipStatus();		//print ship stats (name, health and fuel)
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
						std::cout << "Invalid entry. Please enter 1 to play again or 0 to exit: ";		//check to ensure valid integer input
						std::cin >> newGame;
					}
					if(!std::cin.fail())
					inputCheck = false;
					}
				}

			}
		//spaceMap.deleteMap();	//use a function as there are three separate maps that need to be deleted
	}
	std::cout << "Thanks for playing!" << std::endl;

	return 0;

}
