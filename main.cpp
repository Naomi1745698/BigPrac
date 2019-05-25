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
#include <tgmath.h>		//could also use <maths.h>

using namespace std;

//Spaceship Game!!
//Version:	0.6
//Date:		25-May-2019
//Status: 	COMPILES


int main()
{
	int sizeInput;					//size that user inputs
	int mapSize;					//space size variable from sizeInput variable
	int lowerMapLimit = 5;			//upper and lower map limits
	int upperMapLimit = 20;
	int moveShip = 5;
	bool newGame = true;

	cout << endl << "OOP SPACEGAME!!!" << endl << endl;

	while (newGame) {				//new game loop entry

		cout << "Enter a number for the map size from 10 to 20 (e.g. 10 = 10x10): ";				
		cin >> sizeInput;

		while(sizeInput < 10 || sizeInput > 20){			//need to fix this; so user cant do characters or decimals
			cout << "Invalid entry. Please enter map grid size from 5 to 10 (e.g. '5' = 5x5): ";		//check to ensure valid integer input
	 		cin >> sizeInput;
	 	}

		sizeInput = mapSize;
		bool inputCheck = true;

		// //valid entry check 
		// bool inputCheck = true;

		// while(inputCheck){
		// 	if(cin.fail() || mapSize < lowerMapLimit || mapSize > upperMapLimit || mapSize < 0) {
		// 		cin.clear();
		// 		cin.ignore(50,'\n');
		// 		cout << "Invalid entry. Please enter map grid size from 5 to 10 (e.g. '5' = 5x5): ";		//check to ensure valid integer input
		// 		cin >> mapSize;
		// 	}
		// 	if(!cin.fail())
		// 	inputCheck = false;
		// };


		//ignores previous entries that were used.
		cin.ignore();
		//Player details to be added.
		string spaceshipName;
		int spaceshipType = -1;
		cout << endl << "Choose a spaceship type:" <<endl;
		cout << "1: Gunship - stronger and has a 25% chance of destroying encontered meteors." << endl;
		cout << "2: Racer - weaker than a Gunship, but is nimbler and has a 50% chance of dodging encountered meteors" << endl;	


		cin >> spaceshipType;
		while(cin.fail() || spaceshipType < 1 || spaceshipType > 2){
			//freshScreen();		
			cin.clear();
			cin.ignore(1,'\n');
			cout << "Please enter a valid input." << endl;
			cout << "1: Gunship" << endl;
			cout << "2: Racer" << endl;
			cin >> spaceshipType;
		}

		cout << endl << "Please enter the name of your spaceship: ";
		cin >> spaceshipName;

		//spaceship(string name, int health, int fuel);
		spaceship *playerShip;
		if(spaceshipType == 1) {
			playerShip = new gunship(spaceshipName,10,mapSize*1.5);
		}
		if(spaceshipType == 2) {
			playerShip = new racer(spaceshipName,5,mapSize*1.5);
		}

		cout << "Building your spaceship..." << endl;
		

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
			cout << "Navigate by entering one of the following options: " << endl;
			cout << "                 8: move up" << endl;
			cout << "4: move left     5: stay still     6: move right" << endl;
			cout << "                 2: move down" << endl;
			cout << "0: end game" << endl;
			cin >> moveShip;

			//valid entry check
			
			//run 		if(!cin.fail()) into while loop.
			//Add clear library to it.
			inputCheck = true;

			while(inputCheck || moveShip < 0 || moveShip > 9) {
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					cout << "Invalid entry. Please enter valid movement options: ";		//check to ensure valid integer input
					cin >> moveShip;
				}
				if(!cin.fail())
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
					//cout << "Invalid entry. Please enter valid movement options: " << endl;
					break;
			}
			spaceMap.printMap();			//space map print
			spaceMap.printShipStatus();		//print ship stats (name, health and fuel)
			spaceMap.meteorMoveControl();	//random automatic movement of meteor objects
			spaceMap.interactionCheck();	//meteor / planet / spaceship interaction

			if (spaceMap.checkWinningCondition() == true || spaceMap.checkShipStatus() == true || keepPlaying == false) {
				keepPlaying = false;
				cout << "Would you like to play again?" << endl;
				cout << "1: Yes, 0: No." << endl;
				cin >> newGame;

				inputCheck = true;
				while(inputCheck) {
					if(cin.fail() || newGame < 0 || newGame > 1) {
						cin.clear();
						cin.ignore(50,'\n');
						cout << "Invalid entry. Please enter 1 to play again or 0 to exit.";		//check to ensure valid integer input
						cin >> newGame;
					}
					if(!cin.fail())
					inputCheck = false;
					}
				}
			}
	}

	cout << "Thanks for playing!" << endl;

	return 0;
}