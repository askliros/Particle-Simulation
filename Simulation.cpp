#include<iostream>
using namespace std;
#include< vector>
#include "TheClasses.h"
#include "TheChamber.h"
#include "ProcessingInput.h"
#include "FilenamesReader.h"
#include "InitialiserClass.h"
#include "Directions.h"
#include "Velocities.h"  



int main()
{
  
    DeterministicVelocities velocity(10); //It is an abstract class so we need to pass something.
	
   //Reading the filenames
   FilenamesReader textfilenames("Filenames.txt");
   InitialiserClass initialise(textfilenames,velocity);
   initialise();//Passing the input text files into the input processing engine.
   vector<int> ChamberTerminalCoordinates;
   try{
		ChamberTerminalCoordinates=initialise.getChamberTerminalCoordinates();//The terminal coordinates.
      }
   catch(char* msg)
   {
	   cout<<msg<<endl;
	   cout<<"Program is terminated. Please press a key to continue."<<endl;
	   getchar();
	   exit(0);
   }
   vector<Particle*> MyParticles=initialise.getMyParticles();// The particles   
   vector<vector<char>> TheDeterministicDirections=initialise.getDirections();//The directions.
   DeterministicDirections deterdir(TheDeterministicDirections);
   TheChamber chamber(MyParticles,deterdir,ChamberTerminalCoordinates[0],ChamberTerminalCoordinates[1],ChamberTerminalCoordinates[2],ChamberTerminalCoordinates[3]);
   chamber();
	return 0;

}