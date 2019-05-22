# Spacegame Makefile

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall

# ****************************************************

spacegame: main.o astroObjects.o spaceship.o spaceship_gunship.o spaceship_racer.o meteor.o planet.o space.o
	$(CXX) $(CXXFLAGS) -o spacegame main.o astroObjects.o meteor.o planet.o spaceship.o gunShip.o racer.o space.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp


astroObjects.o: astroObjects.cpp astroObjects.h
	$(CXX) $(CXXFLAGS) -c astroObjects.cpp


meteor.o: meteor.cpp meteor.h
	$(CXX) $(CXXFLAGS) -c meteor.cpp


planet.o: planet.cpp planet.h
	$(CXX) $(CXXFLAGS) -c planet.cpp


spaceship.o: spaceship.cpp spaceship.h
	$(CXX) $(CXXFLAGS) -c spaceship.cpp

spaceship_gunship.o: gunShip.cpp gunShip.h
	$(CXX) $(CXXFLAGS) -c gunShip.cpp

spaceship_racer.o: racer.cpp racer.h
	$(CXX) $(CXXFLAGS) -c racer.cpp

space.o: space.cpp space.h
	$(CXX) $(CXXFLAGS) -c space.cpp