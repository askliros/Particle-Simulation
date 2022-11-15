#include "Velocities.h"




void DeterministicVelocities::operator ()(int nrows, int ncolumns)
{

  for(int i=0;i<nrows;i++)
		{
			this->MyVelocities.push_back(vector<int>());
			for(int j=0;j<ncolumns;j++)
			{
			  this->MyVelocities[i].push_back(1); 
			}
		}
    

}
vector<vector<int>> DeterministicVelocities::getVelocities()
{

	return this->MyVelocities;

}

Velocities* DeterministicVelocities::clone() const
{

  return new DeterministicVelocities(*this);

}



Velocities* StochasticVelocities::clone() const
{
	return new StochasticVelocities(*this);
}

StochasticVelocities::StochasticVelocities(int a)
{
	srand((unsigned int)time(NULL));
}


void StochasticVelocities::operator ()(int nrows,int ncolumns)
{
     int RandomNumber;
	 for(int i=0;i<nrows;i++)
		{
			this->MyVelocities.push_back(vector<int>());
			for(int j=0;j<ncolumns;j++)
			{
			    RandomNumber=rand()%4;
				this->MyVelocities[i].push_back(1+RandomNumber); 
			}
		}
  

}

vector<vector<int>> StochasticVelocities::getVelocities()
{

	return this->MyVelocities;

}

