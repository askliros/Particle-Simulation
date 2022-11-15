
#include<iostream>
using namespace std;
#include< vector>
#include "TheClasses.h"

//Neutrino




 void Neutrino::operator()(char direction) 
{
	
	if(xcoordinate>maxxcoord|| xcoordinate<minxcoord||ycoordinate>maxycoord||ycoordinate<minxcoord)
	{
		throw("N has left the chamber!");
	}
	else{
            this->setpreviouscoordinates(xcoordinate,ycoordinate);
			switch(direction)
			{
					case 'U':
						if(ycoordinate+ParticleVelocities[ycoordinate].at(xcoordinate)>maxycoord)
						{
						   ycoordinate=100000+maxycoord;
						   xcoordinate=100000+maxxcoord;
						   cout<<"N left the chamber from above"<<endl;
						}else
						{
						  ycoordinate=ycoordinate+ParticleVelocities[ycoordinate].at(xcoordinate);
						}

						break;
					case 'D':
						if(ycoordinate-ParticleVelocities[ycoordinate].at(xcoordinate)<minycoord)
						{
						   ycoordinate=-100000+minycoord;
						   xcoordinate=-100000+minxcoord;
						   cout<<"N left the chamber from below"<<endl;
						}else
						{
						  ycoordinate=ycoordinate-ParticleVelocities[ycoordinate].at(xcoordinate);
						}

						break;
					case 'L':
						if(xcoordinate-ParticleVelocities[ycoordinate].at(xcoordinate)<minxcoord)
						{
						   ycoordinate=-100000+minycoord;
						   xcoordinate=-100000+minxcoord;
						   cout<<"N left the chamber from the left"<<endl;
						}else
						{
						  xcoordinate=xcoordinate-ParticleVelocities[ycoordinate].at(xcoordinate);
						}

						break;
					case 'R':
						if(xcoordinate+ParticleVelocities[ycoordinate].at(xcoordinate)>maxxcoord)
						{
						   ycoordinate=100000+maxycoord;
						   xcoordinate=100000+maxxcoord;
						   cout<<"N left the chamber from the right"<<endl;
						}else
						{
						  xcoordinate=xcoordinate+ParticleVelocities[ycoordinate].at(xcoordinate);
						}

						break;

					default:
						cout<<"Wrong direction given!"<<endl;
						break;
	           }
	     }

  }


Particle* Neutrino::clone() const
{

  return new Neutrino(*this);

}
string Neutrino::IdentifyYourself() const
{

  return "N";

}



void Neutrino::EnvironmentAssessment(int maxxcoord, int minxcoord,int maxycoord, int minycoord)
{
   this->maxycoord=maxycoord;
   this->minycoord=minycoord;
   this->minxcoord=minxcoord;
   this->maxxcoord=maxxcoord;
   //Assessing the velocities.
   int nrows=this->maxycoord-this->minycoord+1;
   int ncolumns=this->maxxcoord-this->minxcoord+1;
   this->VelocitiesPtr->operator()(nrows,ncolumns);
   this->ParticleVelocities=this->VelocitiesPtr->getVelocities();
   
	 
}


Neutrino::Neutrino(int xcoordinate,int ycoordinate,Velocities& PartVelocities)
{
	
 
 this->xcoordinate=xcoordinate;
 this->ycoordinate=ycoordinate;
 this->VelocitiesPtr=PartVelocities.clone();



}

vector<int> Neutrino::getcoordinates() const
{
	if(xcoordinate>maxxcoord||xcoordinate<minxcoord||ycoordinate>maxycoord||ycoordinate<minycoord)
	{
		 throw("N  either left the chamber or is originally outside bounds.");
	}else{
		vector<int> coordinates;
		coordinates.push_back(xcoordinate);
		coordinates.push_back(ycoordinate);
		return coordinates;
	}

}

vector<int> Neutrino::getpreviouscoordinates() const
{
	vector<int> coordinates;
	coordinates.push_back(this->xpreviouscoordinate);
	coordinates.push_back(this->ypreviouscoordinate);
	return coordinates;

}

void Neutrino::setpreviouscoordinates(int x,int y) 
{
	this->xpreviouscoordinate=x;
	this->ypreviouscoordinate=y;
}

vector<vector<int>> Neutrino::getParticleVelocities()
{
   return this->ParticleVelocities;

}
 
// Photon

void Photon::operator()(char direction) 
{
	this->setpreviouscoordinates(xcoordinate,ycoordinate);
	switch(direction)
	{
	case 'U':
		if(ycoordinate+ParticleVelocities[ycoordinate].at(xcoordinate)>=maxycoord)
		{
           ycoordinate=maxycoord-ParticleVelocities[maxycoord].at(xcoordinate);
		   throw("The P is reflected.");
		   
		}else
		{
          ycoordinate=ycoordinate+ParticleVelocities[ycoordinate].at(xcoordinate);
		  
		}

		break;
	case 'D':
		if(ycoordinate-ParticleVelocities[ycoordinate].at(xcoordinate)<=minycoord)
		{
          ycoordinate=minycoord+ParticleVelocities[minycoord].at(xcoordinate);
		   throw("The P is reflected.");
		}else
		{
          ycoordinate=ycoordinate-ParticleVelocities[ycoordinate].at(xcoordinate);
		  
		}

		break;
	case 'L':
		if(xcoordinate-ParticleVelocities[ycoordinate].at(xcoordinate)<=minxcoord)
		{
           xcoordinate=minxcoord+ParticleVelocities[ycoordinate].at(minxcoord);
		    throw("The P is reflected");
		}else
		{
          xcoordinate=xcoordinate-ParticleVelocities[ycoordinate].at(xcoordinate);
		 
		}

		break;
	case 'R':
		if(xcoordinate+ParticleVelocities[ycoordinate].at(xcoordinate)>=maxxcoord)
		{
          xcoordinate=maxxcoord-ParticleVelocities[ycoordinate].at(minxcoord);
		  throw("The P is reflected");
		}else
		{
          xcoordinate=xcoordinate+ParticleVelocities[ycoordinate].at(xcoordinate);
		  
		}

		break;
	default:
		cout<<"Wrong direction given!"<<endl;
		break;
	}
    
}
Particle* Photon::clone() const
{

  return new Photon(*this);

}

void Photon::EnvironmentAssessment(int maxxcoord, int minxcoord,int maxycoord, int minycoord)
{
   this->maxycoord=maxycoord;
   this->minycoord=minycoord;
   this->minxcoord=minxcoord;
   this->maxxcoord=maxxcoord;
   //Assessing the velocities.
   int nrows=this->maxycoord-this->minycoord+1;
   int ncolumns=this->maxxcoord-this->minxcoord+1;
   
	this->VelocitiesPtr->operator()(nrows,ncolumns);
   this->ParticleVelocities=this->VelocitiesPtr->getVelocities();
}

Photon::Photon(int xcoordinate,int ycoordinate,Velocities& PartVelocities)
{
 this->xcoordinate=xcoordinate;
 this->ycoordinate=ycoordinate;
 this->VelocitiesPtr=PartVelocities.clone();
}

vector<int> Photon::getcoordinates() const
{
	if(xcoordinate>maxxcoord||xcoordinate<minxcoord||ycoordinate>maxycoord||ycoordinate<minycoord)
	{
		throw("Photon's initial coordinates are outside the chamber's bounds");
	}else
	{
	vector<int> coordinates;
	coordinates.push_back(xcoordinate);
	coordinates.push_back(ycoordinate);
	return coordinates;
	}

}

vector<int> Photon::getpreviouscoordinates() const
{
	vector<int> coordinates;
	coordinates.push_back(this->xpreviouscoordinate);
	coordinates.push_back(this->ypreviouscoordinate);
	return coordinates;

}

void Photon::setpreviouscoordinates(int x,int y) 
{
	this->xpreviouscoordinate=x;
	this->ypreviouscoordinate=y;

}


string Photon::IdentifyYourself() const
{

  return "P";

}

vector<vector<int>> Photon::getParticleVelocities()
{
   return this->ParticleVelocities;

}

// Electron

void Electron::operator()(char direction)
{
	this->setpreviouscoordinates(xcoordinate,ycoordinate);
	if(xcoordinate==maxxcoord|| xcoordinate==minxcoord||ycoordinate==maxycoord||ycoordinate==minxcoord)
	{
		throw("E is trapped on the chamber's wall!");
		ycoordinate=ycoordinate;
		xcoordinate=xcoordinate;
	}else
	{	
	switch(direction)
	{
	case 'U':
             if(ycoordinate+ParticleVelocities[ycoordinate].at(xcoordinate)>=maxycoord)
			 {
                   ycoordinate=maxycoord;
			 }else
			 {
                 ycoordinate=ycoordinate+ParticleVelocities[ycoordinate].at(xcoordinate);
			 }

		break;
	case 'D':
		      if(ycoordinate-ParticleVelocities[ycoordinate].at(xcoordinate)<=minycoord)
			 {
                   ycoordinate=minycoord;
			 }else
			 {
                 ycoordinate=ycoordinate-ParticleVelocities[ycoordinate].at(xcoordinate);
			 }

		break;
	case 'L':
		       if(xcoordinate-ParticleVelocities[ycoordinate].at(xcoordinate)<=minxcoord)
			 {
                   xcoordinate=minxcoord;
			 }else
			 {
                 xcoordinate=xcoordinate-ParticleVelocities[ycoordinate].at(xcoordinate);
			 }

		break;
	case 'R':
		       if(xcoordinate+ParticleVelocities[ycoordinate].at(xcoordinate)>=maxxcoord)
			 {
                   xcoordinate=maxxcoord;
			 }else
			 {
                 xcoordinate=xcoordinate+ParticleVelocities[ycoordinate].at(xcoordinate);
			 }

		break;

	default:
		cout<<"Wrong direction given!"<<endl;
		break;
	}
		}

}
Particle* Electron::clone() const
{

  return new Electron(*this);

}

void Electron::EnvironmentAssessment(int maxxcoord, int minxcoord,int maxycoord, int minycoord)
{
   this->maxycoord=maxycoord;
   this->minycoord=minycoord;
   this->minxcoord=minxcoord;
   this->maxxcoord=maxxcoord;
   //Assessing the velocities.
   int nrows=this->maxycoord-this->minycoord+1;
   int ncolumns=this->maxxcoord-this->minxcoord+1;
   
	 this->VelocitiesPtr->operator()(nrows,ncolumns);
   this->ParticleVelocities=this->VelocitiesPtr->getVelocities();
}

Electron::Electron(int xcoordinate,int ycoordinate,Velocities& PartVelocities)
{
	
 
 this->xcoordinate=xcoordinate;
 this->ycoordinate=ycoordinate;
 this->VelocitiesPtr=PartVelocities.clone();
 
}
vector<int> Electron::getcoordinates() const
{
	if(xcoordinate>maxxcoord||xcoordinate<minxcoord||ycoordinate>maxycoord||ycoordinate<minycoord)
	{
		throw("Electron's initial coordinates are outside the chamber's bounds!");
	}else{
	vector<int> coordinates;
	coordinates.push_back(xcoordinate);
	coordinates.push_back(ycoordinate);
	return coordinates;
	}

}

vector<int> Electron::getpreviouscoordinates() const
{
	vector<int> coordinates;
	coordinates.push_back(this->xpreviouscoordinate);
	coordinates.push_back(this->ypreviouscoordinate);
	return coordinates;

}

void Electron::setpreviouscoordinates(int x,int y)
{
	this->xpreviouscoordinate=x;
	this->ypreviouscoordinate=y;

}

string Electron::IdentifyYourself() const
{

  return "E";

}


vector<vector<int>> Electron::getParticleVelocities()
{
   return this->ParticleVelocities;

}
