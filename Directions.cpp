#include "Directions.h"
DeterministicDirections::DeterministicDirections(vector<vector<char>> DirectionsOfParticles)
{
  this->DirectionsOfParticles=DirectionsOfParticles;
 //We have already took action in the ProcessingInput class. The number of directions should be the same for every particle.
  this->NumberOfSimulations=this->DirectionsOfParticles[0].size();
}

Directions* DeterministicDirections::clone() const
{
	return new DeterministicDirections(*this);
}

vector<char> DeterministicDirections::operator ()(int SimulationNumber) const
{
  vector<char> CurrentDirections;
  if(SimulationNumber>this->NumberOfSimulations)
  {
	  throw("Wrong simulation number for the deterministic case!");
  }else
  {
	  for(size_t i=0;i!=DirectionsOfParticles.size();i++)
	  {
		  CurrentDirections.push_back(DirectionsOfParticles[i].at(SimulationNumber));
	  }
  }
   return CurrentDirections;

}

int DeterministicDirections::getNumberOfSimulations() const
{
  return this->NumberOfSimulations;
}

StochasticDirections::StochasticDirections(int NumberOfSimulations,vector<vector<char>> DeterministicDirectionsOfParticles)
{
   
	 this->DirectionsOfParticles=DeterministicDirectionsOfParticles;
 //We have already took action in the ProcessingInput class. 
 //The number of directions should be the same for every particle.
  this->NumberOfSimulations=NumberOfSimulations;
  this->NumberOfParticles=this->DirectionsOfParticles.size();
	
	srand((unsigned int)time(NULL));
}

Directions* StochasticDirections::clone() const
{
	return new StochasticDirections(*this);
}


vector<char> StochasticDirections::operator ()(int SimulationNumber) const
{
	vector<char> CurrentDirections;
	char direction;
	int temp;
	for(int i=0;i<this->NumberOfParticles;i++)
	{
        temp=rand()%4;
	  switch(temp)
	  {
	  case 0:
		  direction='U';
		  break;
	  case 1:
		  direction='D';
		  break;
	  case 2:
		  direction='L';
		  break;
	  case 3:
		  direction='R';
		  break;
	  default:
		  break;

	}
	  CurrentDirections.push_back(direction);
	}

     return CurrentDirections;
}

int StochasticDirections::getNumberOfSimulations() const
{
  return this->NumberOfSimulations;
}

