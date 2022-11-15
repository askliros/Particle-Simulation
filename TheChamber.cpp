#include "TheChamber.h"

//TheChamber::TheChamber(Particle& theParticle,Directions& theDirections,int maxxcoord,int minxcoord,int maxycoord,int minycoord)

TheChamber::TheChamber(vector<Particle*> MyParticles,Directions& theDirections,int maxxcoord,int minxcoord,int maxycoord,int minycoord)
{
  this->maxxcoord=maxxcoord;
  this->minxcoord=minxcoord;
  this->maxycoord=maxycoord;
  this->minycoord=minycoord;
  this->MyParticles=MyParticles;
 // this->theParticlePtr=theParticle.clone();
  this->theDirectionsPtr=theDirections.clone();

}
void TheChamber::InteractingWithTheParticle()
{
    
	 // this->theParticlePtr->EnvironmentAssessment(this->maxxcoord,this->minxcoord,this->maxycoord,this->minycoord);
	for(size_t i=0;i!=this->MyParticles.size();i++)
	{
      this->MyParticles[i]->EnvironmentAssessment(this->maxxcoord,this->minxcoord,this->maxycoord,this->minycoord);
	}


}

void TheChamber::operator ()()
{
    int NumberOfSimulations=this->theDirectionsPtr->getNumberOfSimulations();
	
	ofstream file( "output.txt" );
	if( !file ) // check stream for error (check if it opened the file correctly)
        cout << "error opening file for writing." << endl;
	
	vector<char> directions;
	
	srand((unsigned int)time(NULL));
	vector<int> OriginalParticleCoordinates;
	//Interacting with all the particles that have entered the chamber:
	this->InteractingWithTheParticle(); //The function invoked deals with all the particles.
	
  ///////////////////////////////////////////////////////////////////////////////////////
	//file<<"The particle is of type: "<<this->theParticlePtr->IdentifyYourself()<<endl;
     for(size_t i=0;i!=this->MyParticles.size();i++)
	{
		file<<"The particle is of type: "<<this->MyParticles[i]->IdentifyYourself()<<endl;
	 
	
	
	 
	 try{
		//OriginalParticleCoordinates=this->theParticlePtr->getcoordinates();
          OriginalParticleCoordinates=this->MyParticles[i]->getcoordinates();
	}catch(char* msg)
	{
		cout<<msg<<endl;
		cout<<"The program is terminated. Please press a key to continue."<<endl;
		getchar();
		exit(0);
	}
     
	file<<"The initial coordinates of the particle "<< this->MyParticles[i]->IdentifyYourself()<< " are:"<<endl;
	file<<"The x-coordinate: "<<OriginalParticleCoordinates[0]<<endl;
	file<<"The y-coordinate: "<<OriginalParticleCoordinates[1]<<endl;
	 }
//////////////////////////////////////////////////////////////////////////////////////////

	// Initialising the original chamber snapshot
	this->OriginalChamberState();//Filling in the Chamber. Deals with all the particles.
	this->ShowTheChamber(file);//Printing out the Chamber State.	
	file<<" "<<endl;
	
   for(int i=0;i<NumberOfSimulations;i++)
   {

		try{
				directions=this->theDirectionsPtr->operator ()(i); //Gives directions equal to the number of particles.
		   }catch(char* msg)
		   {
			   cout<<msg<<endl;
			   cout<<"Program is terminated. Please press a key to continue."<<endl;
			   getchar();
			   exit(0);
		   }
		   file<<"This is Simulation number: "<<i+1<<endl;	  
	   for(size_t k=0;k!=this->MyParticles.size();k++)
	   {
		   
		   file<<"The direction of "<< this->MyParticles[k]->IdentifyYourself()<<" is: "<<directions[k]<<endl;
	       //Here we set the new coordinates as well as the previous ones.
		  try{
				   this->MyParticles[k]->operator ()(directions[k]);
			  }
			   catch(char* message)
			  {
				 file<<message<<endl;
			  }
		   }


	 //Here we update the chamber state:
	 this->UpdatingChamberState();
	  
     for(size_t k=0;k!=this->MyParticles.size();k++)
	 {
		  file<<"The particle's "<<this->MyParticles[k]->IdentifyYourself()<< " new coordinates and the associated velocity are: "<<endl;
		  try{
			  file<<"The x-coordinate: "<<this->MyParticles[k]->getcoordinates().at(0)<<endl;
			  file<<"The y-coordinate: "<<this->MyParticles[k]->getcoordinates().at(1)<<endl;
			  file<<"The velocity at the new coordinates is: "<<this->MyParticles[k]->getParticleVelocities()[this->MyParticles[k]->getcoordinates().at(1)].at(this->MyParticles[k]->getcoordinates().at(1))<<" "<<endl;
		     }
		  catch(char* msg)
		  {
			  file<<msg<<endl;
		  }
	 }


	  //Here we print the new chamber snapshot:
	  this->ShowTheChamber(file);
	  file<<" "<<endl;






   }

 file.close();


}
void TheChamber::OriginalChamberState()
{
   //Assessing the velocities.
   int nrows=this->maxycoord-this->minycoord+1;
   int ncolumns=this->maxxcoord-this->minxcoord+1;
   
	 for(int i=0;i<nrows;i++)
		{
			this->ChamberSnapshot.push_back(vector<string>());
			for(int j=0;j<ncolumns;j++)
			{
			  this->ChamberSnapshot[i].push_back("o"); 
			}
		}

	 //this->ChamberSnapshot[this->theParticlePtr->getcoordinates().at(1)].at(this->theParticlePtr->getcoordinates().at(0))=this->theParticlePtr->IdentifyYourself();
     for(size_t i=0;i!=this->MyParticles.size();i++)
	 {
          if(this->ChamberSnapshot[this->MyParticles[i]->getcoordinates().at(1)].at(this->MyParticles[i]->getcoordinates().at(0))=="o")
		  {
		      this->ChamberSnapshot[this->MyParticles[i]->getcoordinates().at(1)].at(this->MyParticles[i]->getcoordinates().at(0))=this->MyParticles[i]->IdentifyYourself();
		  }else
		  {
            this->ChamberSnapshot[this->MyParticles[i]->getcoordinates().at(1)].at(this->MyParticles[i]->getcoordinates().at(0))=this->ChamberSnapshot[this->MyParticles[i]->getcoordinates().at(1)].at(this->MyParticles[i]->getcoordinates().at(0))+this->MyParticles[i]->IdentifyYourself();
		  }
	 }


}

void TheChamber::UpdatingChamberState()
{
    vector<int> PreviousCoordinates;
	string str;
	string str2;

	//Loop across all the particles. Set all previous coordinates to "o"( Since all the particles are moving.)
	for(size_t k=0;k!=MyParticles.size();k++)
	{
		  PreviousCoordinates=this->MyParticles[k]->getpreviouscoordinates();
		 this->ChamberSnapshot[PreviousCoordinates[1]].at(PreviousCoordinates[0])="o"; 
		  
	}
			 
	for(size_t k=0;k!=MyParticles.size();k++)//Set all current coordinates to their current state.
	{	  
		  //If this position on the chamber unoccupied:
		  try{
				  if(this->ChamberSnapshot[this->MyParticles[k]->getcoordinates().at(1)].at(this->MyParticles[k]->getcoordinates().at(0))=="o") 
				  {
					  
					   this->ChamberSnapshot[this->MyParticles[k]->getcoordinates().at(1)].at(this->MyParticles[k]->getcoordinates().at(0))=this->MyParticles[k]->IdentifyYourself();
						  
				  }else
				  {
		             
					  this->ChamberSnapshot[this->MyParticles[k]->getcoordinates().at(1)].at(this->MyParticles[k]->getcoordinates().at(0))=this->MyParticles[k]->IdentifyYourself()+this->ChamberSnapshot[this->MyParticles[k]->getcoordinates().at(1)].at(this->MyParticles[k]->getcoordinates().at(0));
						  
						  
				 
				   }
		     }
	         catch(char* msg)
	            {
					cout<<msg<<endl;
			    }
	

	}

      

		  


}


ostream& TheChamber::ShowTheChamber(ostream& o)
{
  
	vector<vector<string> >::reverse_iterator it=this->ChamberSnapshot.rbegin(), end=this->ChamberSnapshot.rend();
    while (it!=end) 
{
    vector<string>::iterator it1=it->begin(),end1=it->end();
    copy(it1,end1,ostream_iterator<string>(o, " "));
    o << endl;
    ++it;
}
 return o;

}