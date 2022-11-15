#ifndef InitialiserClass_H
#define InitialiserClass_H

#include <iostream>
using namespace std;
#include <vector>
#include "FilenamesReader.h"
#include "TheClasses.h"
#include "TheChamber.h"
#include "ProcessingInput.h"
#include "Velocities.h"

class InitialiserClass{
public:
       InitialiserClass(FilenamesReader& filenames,Velocities& MyVelocities);
	   void operator()();
	   ~InitialiserClass(){};
	   vector<int> getChamberTerminalCoordinates();//returns the chamber's terminal coordinates.
	   vector<Particle* > getMyParticles();//returns the vector that contains the pointers of lla the particles' objects.
	   vector<vector<char>> getDirections(); // returns a 2D vector of all the directions of all the particles
	   
private:
	    FilenamesReader* filenamesptr;
		ProcessingInput* processinginputptr;
		vector<int> ChamberTerminalCoordinates;
		vector<Particle*> MyParticles;
		vector<vector<int>> ParticlesInitialCoordinates;
		vector<char>       ParticlesTypes;
		Velocities* VelocitiesPtr;
		
	  
};
#endif