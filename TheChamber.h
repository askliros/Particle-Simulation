#ifndef THECHAMBER_H
#define THECHAMBER_H
#include "TheClasses.h"
#include "Directions.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
class TheChamber{

public:
       
		TheChamber(vector<Particle*> MyParticles,Directions& TheDirections,int maxxcoord,int minxcoord,int maxycoord,int minycoord);
	    void operator()();//executing the simulation
		void InteractingWithTheParticle();//interaction of the particle with the environment
		ostream& ShowTheChamber(ostream& o);//Prints the results into a file.
		void OriginalChamberState();//Gets the original chamber state.
		void UpdatingChamberState();//Updates the Chamber state.

private:
	int maxxcoord;
	int minxcoord;
	int maxycoord;
	int minycoord;
	//Particle* theParticlePtr;
	vector<Particle*> MyParticles;
	Directions* theDirectionsPtr;
	 vector<vector<string>> ChamberSnapshot;


};


#endif