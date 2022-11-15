#include "InitialiserClass.h"


InitialiserClass::InitialiserClass(FilenamesReader& filenames,Velocities& MyVelocities)
{
  this->filenamesptr=filenames.clone();
  this->VelocitiesPtr=MyVelocities.clone();

}

void InitialiserClass::operator ()() 
{
   
	  vector<string> TheFilenames;
	  //Reading the names of the input filenames.
	   try
	   {
			 TheFilenames=this->filenamesptr->operator()();       
	   }
	   catch(char *msg)
	   {
			 cout<<msg<<endl;
			 cout<<"Program is terminated. Press a key to continue."<<endl;
			 getchar();
			 exit(0);
	   }
	   

	  
	 ProcessingInput InputProcess(TheFilenames[0],TheFilenames[2],TheFilenames[1],TheFilenames[3]);
	 // putting the four text files (checked above if they are four) into the processing engine.
	 InputProcess();
	 //processing the four input files, extracting the input and checking for errors in the input.
	  
	 //Setting the processing Inputpointer of the class:
	 this->processinginputptr=InputProcess.clone();// We have defined the InputProcess so we get back its clone now.

      

}

vector<int> InitialiserClass::getChamberTerminalCoordinates()
{
  this->ChamberTerminalCoordinates=this->processinginputptr->getChamberTerminalCoordinates();
  //We imposed in the processing input class that the chamber terminal coordinates are four.
 // For convenience we want to make sure that the chambers lowest coordinates are 0.
   if(this->ChamberTerminalCoordinates[1]!=0||this->ChamberTerminalCoordinates[3]!=0)
   {
	   throw("minimum y coordinate and minimum x coordinate must be 0.");
   }else
   {
     return this->ChamberTerminalCoordinates;
   }

}

vector<vector<char>> InitialiserClass::getDirections()
{
   return this->processinginputptr->getDirections();

}

vector<Particle*> InitialiserClass::getMyParticles()
{
    //Getting the particles' initial coordinates.
	this->ParticlesInitialCoordinates=this->processinginputptr->getInitialCoordinates();

	//Getting the particles'types.
	this->ParticlesTypes=this->processinginputptr->getTypes();

	//We have checked in the ProcessingInput class that the above vectors have the same number of rows.
    //We have also checked in the ProcessingInput class that we have correct coordinates and two coordinates in 
	// each line.
	//Otherwise we would have gotten error message and the program would be terminated.
    //Populating the particles' vector.
	int xcoordinate;
	int ycoordinate;
	char theType;

	vector<Particle*> MyParticles;
	

	for(size_t i=0;i!=ParticlesTypes.size();i++)
	{
      xcoordinate=this->ParticlesInitialCoordinates[i].at(0);
	  ycoordinate=this->ParticlesInitialCoordinates[i].at(1);
	  theType=this->ParticlesTypes[i];
	 
	  
	  // creating each object regarding its type.
	  switch(theType){
		  case 'P':
              		 			  
			  MyParticles.push_back(new Photon(xcoordinate,ycoordinate,(*this->VelocitiesPtr)));
			  break;
		  case 'E':			  			 			  
			  MyParticles.push_back(new Electron(xcoordinate,ycoordinate,(*this->VelocitiesPtr)));
			  break;
		  case 'N':			  			 			  
			  MyParticles.push_back(new Neutrino(xcoordinate,ycoordinate,(*this->VelocitiesPtr)));
			  break;
	      default:
		     cout<<"wrong type!"<<endl; // Will never hit this case because we have taken the precautions already.
			  break;

	  }

	}

	return MyParticles;


}