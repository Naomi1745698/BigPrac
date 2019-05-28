#include "test.h"
#include <iostream>
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
#include <cstring>
#include <cctype>

test::test(){
	spaceshipName = "Callum";
	//Declaring testing objects
	planet1 = new planet(planetResourceName,startResources,1,1);	
	playerShip = new gunship(spaceshipName,health,100);
	playerShip1 = new racer(spaceshipName,health+50,150);
	meteor1 = new meteor(meteorSize,1,1);
	std::cout << "testing class has been created" << std::endl << std::endl << std::endl;
};
void test::mapTesting(){
	space spaceMap(15, playerShip);
	//Starting positon.
	playerShip->setCoordinate(0,0);
	std::cout << "Starting location" << std::endl;
	std::cout << "Row coordinate " << playerShip->getRowCoordinate() << std::endl;
	std::cout << "Col coordinate " << playerShip->getColumnCoordinate() << std::endl << std::endl;
	int initalRow = playerShip->getRowCoordinate();	//Set reference point to determine direction 
	int initalColumn = playerShip->getColumnCoordinate();
	PASS = 0;
 	for(int i = 0; i<4;i++){		//Go into a direction of sqaure to test all movements.
		switch (i) {
			case 0: 
				spaceMap.moveUp();
				std::cout << "MoveUp" << std::endl;
				std::cout << "Row coordinate " << playerShip->getRowCoordinate() << std::endl;
				std::cout << "Col coordinate " << playerShip->getColumnCoordinate() << std::endl << std::endl;
				if(initalColumn+1 == playerShip->getRowCoordinate()){
					PASS++;
				}else{ 	
					std::cout << "ERROR moveUp" << std::endl;
					PASS--;
				}
				break;
			case 3: 
				spaceMap.moveLeft();
				std::cout << "Moveleft" << std::endl;
				std::cout << "Row coordinate " << playerShip->getRowCoordinate() << std::endl;
				std::cout << "Col coordinate " << playerShip->getColumnCoordinate() << std::endl << std::endl;
				if(initalRow == playerShip->getRowCoordinate()){
					PASS++;
				}else{
					std::cout << "ERROR moveLeft" << std::endl;
					PASS--;
				}
				break;
			case 1: 
				spaceMap.moveRight();
				std::cout << "MoveRight" << std::endl;
				std::cout << "Row coordinate " << playerShip->getRowCoordinate() << std::endl;
				std::cout << "Col coordinate " << playerShip->getColumnCoordinate() << std::endl << std::endl;
				if(initalRow+1 == playerShip->getRowCoordinate()){
					PASS++;
				}else{
					std::cout << "ERROR moveRight" << std::endl;
					PASS--;
				}
				break;
			case 2: 
				spaceMap.moveDown();
				std::cout << "MoveDown" << std::endl;
				std::cout << "Row coordinate " << playerShip->getRowCoordinate() << std::endl;
				std::cout << "Col coordinate " << playerShip->getColumnCoordinate() << std::endl << std::endl;
				if(initalColumn == playerShip->getRowCoordinate()){
					PASS++;
				}else{
					std::cout << "ERROR moveDown" << std::endl;
					PASS--;
				}
				break;
			default:

				break;
		}
};

	if(PASS == 4){
		std::cout << "<------------------MOVEMENT CONDITIONS PASSED--------------->" << std::endl;
	};
};
void test::boundaryTesting(){
	space spaceMap(15, playerShip);
	PASS = 0;
	playerShip->setCoordinate(0,0);
	//spaceMap.printMap();			//space map print
	std::cout << "Starting location" << std::endl;
	std::cout << "Row coordinate " << playerShip->getRowCoordinate() << std::endl;
	std::cout << "Col coordinate " << playerShip->getColumnCoordinate() << std::endl << std::endl;
	int initalRow = playerShip->getRowCoordinate();
	int initalColumn = playerShip->getColumnCoordinate();
	for(int i = 0; i<4;i++){
		playerShip->setCoordinate(0,0);
		switch (i) {
			case 0:
				//while loop to continue in the move up direction and stop once the boundary has been reached.  
				while(true){ 
					int preYCoordinate = playerShip->getRowCoordinate();
					spaceMap.moveUp();
					std::cout << "MoveUp" << std::endl;
					std::cout << "Row coordinate " << playerShip->getRowCoordinate() << std::endl;
					std::cout << "Col coordinate " << playerShip->getColumnCoordinate() << std::endl << std::endl;
					if(preYCoordinate == playerShip->getRowCoordinate()){
						std::cout << "Reached top of map (" << playerShip->getRowCoordinate() << "," << playerShip->getColumnCoordinate() << ")";
						std::cout << "" << std::endl;
						PASS++;
						break;
					};
				}
				break;
			case 3: 
				//while loop to continue in the move left direction and stop once the boundary has been reached. 
				while(true){
					int preXCoordinate = playerShip->getColumnCoordinate();
					spaceMap.moveLeft();
					std::cout << "Moveleft" << std::endl;
					std::cout << "Row coordinate " << playerShip->getRowCoordinate() << std::endl;
					std::cout << "Col coordinate " << playerShip->getColumnCoordinate() << std::endl << std::endl;
					if(preXCoordinate == playerShip->getColumnCoordinate()){
						std::cout << "Reached left of map (" << playerShip->getRowCoordinate() << "," << playerShip->getColumnCoordinate() << ")";
						std::cout << "" << std::endl;
						PASS++;
						break;						
					}
				}
				break;
			case 1:
				//while loop to continue in the move right direction and stop once the boundary has been reached.  
				while(true){
					int preXCoordinate = playerShip->getColumnCoordinate();
					spaceMap.moveRight();
					std::cout << "MoveRight" << std::endl;
					std::cout << "Row coordinate " << playerShip->getRowCoordinate() << std::endl;
					std::cout << "Col coordinate " << playerShip->getColumnCoordinate() << std::endl << std::endl;
					if(preXCoordinate == playerShip->getColumnCoordinate()){
						std::cout << "Reached right of map (" << playerShip->getRowCoordinate() << "," << playerShip->getColumnCoordinate() << ")";
						std::cout << "" << std::endl;
						PASS++;
						break;						
					}
				}
				break;
			case 2: 
				while(true){
				//while loop to continue in the move down direction and stop once the boundary has been reached.  
					int preYCoordinate = playerShip->getRowCoordinate();
					spaceMap.moveDown();
					std::cout << "MoveDown" << std::endl;
					std::cout << "Row coordinate " << playerShip->getRowCoordinate() << std::endl;
					std::cout << "Col coordinate " << playerShip->getColumnCoordinate() << std::endl << std::endl;
					if(preYCoordinate == playerShip->getRowCoordinate()){
						std::cout << "Reached down of map (" << playerShip->getRowCoordinate() << "," << playerShip->getColumnCoordinate() << ")";
						std::cout << "" << std::endl;
						PASS++;
						break;
					};
				}
				break;
			default:
			
				break;
		}
};
if(PASS == 4 ){
	std::cout << "<------------------boundaryTesting PASS--------------->" << std::endl;
}
};
void test::gunShipTesting(){							
	PASS = 0;
	std::cout << "Name is: " << playerShip->getName() << std::endl;
	if(playerShip->getName() == spaceshipName){
		PASS++;
	}else{
		std::cout << "ERROR getName" << std::endl;
		PASS--;
	};
	std::cout  << " Health is: " << playerShip->getHealth() << std::endl;	
	if(playerShip->getHealth() == health){
		PASS++;
	}else{
		std::cout << "ERROR getHealth" << std::endl;
		PASS--;
	};
	std::cout << " Fuel is: " << playerShip->getResources() << std::endl;
	if(playerShip->getResources() == 100){
		PASS++;
	}else{
		std::cout << "ERROR getResources" << std::endl;
		PASS--;
	}
	std::cout << "add 50 to both health and fuel" << std::endl;
	playerShip->setHealth(addHealth);	// adds addHealth to the original health
	playerShip->setResources(addResources); //adds addResources to the original Resources

	std::cout << " added Health is: " << playerShip->getHealth() << std::endl;
	std::cout <<  " added Fuel is: " << playerShip->getResources() << std::endl;
	if(PASS == 3){
		std::cout << "<---------------------PASS---------------->" << std::endl;
	}
};
void test::racerTesting(){														
	PASS = 0;
	std::cout << "Name is: " << playerShip1->getName() << std::endl;
	if(playerShip1->getName() == spaceshipName){
		PASS++;
	}else{
		std::cout << "ERROR getName" << std::endl;
		PASS--;
	};
	std::cout  << " Health is: " << playerShip1->getHealth() << std::endl;		
	if(playerShip1->getHealth() == health+50){
		PASS++;
	}else{
		std::cout << "ERROR getHealth" << std::endl;
		PASS--;
	};
	std::cout << " Fuel is: " << playerShip1->getResources() << std::endl;
	if(playerShip1->getResources() == 150){
		PASS++;
	}else{
		std::cout << "ERROR getResources" << std::endl;
		PASS--;
	};
	std::cout << "add 50 to both health and fuel" << std::endl;
	playerShip1->setHealth(addHealth);	// adds addHealth to the original health
	playerShip1->setResources(addResources); //adds addResources to the original Resources

	std::cout << " added Health is: " << playerShip1->getHealth() << std::endl;
	std::cout <<  " added Fuel is: " << playerShip1->getResources() << std::endl;
	if(PASS == 3){
		std::cout << "<---------------------PASS---------------->" << std::endl;
	};
};
void test::planetTesting(){
	PASS = 0;											
	std::cout << "resourceType is: " << planet1->getName() << std::endl; 
	if(planet1->getName() == "K9"){
		PASS++;
	}else{
		std::cout << "ERROR getName" << std::endl;
		PASS--;
	};
	std::cout << " Resource size is: " << planet1->getResources() << std::endl;
	if(planet1->getResources() == startResources){
		PASS++;
	}else{
		std::cout << "ERROR getResources" << std::endl;
		PASS--;
	};
	std::cout << "add 50 to fuel" << std::endl; 
	planet1->setResources(addResources); // adds addResources to the original set of resources
	std::cout << " Change resource size is: " << planet1->getResources() << std::endl;
	if(planet1->getResources() == 70){
		PASS++;
	}else{
		std::cout << "ERROR setResources" << std::endl;
		PASS--;
	};
	if(PASS == 3){
		std::cout << "<---------------------PASS---------------->" << std::endl;
	}
};
void test::meteorTesting(){
	PASS = 0;
	std::cout << "the meteor size is: " << meteor1->getHealth() << std::endl;
	if(meteor1->getHealth() == 25){
		PASS++;
	}else{
		PASS--;
		std::cout << "ERROR meteorsize" << std::endl;
	};
	std::cout << "set meteor size to original + 20" << std::endl;
	meteor1->setHealth(20); //adds 20 to size
	std::cout << "the meteor size is: " << meteor1->getHealth() << std::endl;
	if(meteor1->getHealth() == 45){
		PASS++;
	}else{
		PASS--;
		std::cout << "ERROR set meteorsize" << std::endl;
	}
	if(PASS == 2){
		std::cout << "<---------------------PASS---------------->" << std::endl;		
	};
};
test::~test(){
	delete playerShip;
	delete playerShip1;	
	delete planet1;
	delete meteor1;

};