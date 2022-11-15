#ifndef Directions_H
#define Directions_H
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class Directions{
public:
	Directions(){};
	virtual vector<char> operator()(int SimulationNumber) const=0; 
	virtual Directions* clone() const=0;
	virtual int getNumberOfSimulations() const=0;
    ~Directions(){};
private:
	vector<vector<char>> DirectionsOfParticles;
	int NumberOfSimulations;
	int NumberOfParticles;
};

class DeterministicDirections:public Directions
{
public:
	DeterministicDirections(vector<vector<char>> DirectionsOfParticles);// constructor that accepts the directions of all particles.
	virtual vector<char> operator()(int SimulationNumber) const; // Returns the directions of all particles at the specific simulation number.
	virtual Directions* clone() const;//Returns the this pointer of that object.
	int getNumberOfSimulations() const;//Returns the number of simulation number that we need to make in order for us to implement all directions.
    ~DeterministicDirections(){};//Destructor.
private:
	vector<vector<char>> DirectionsOfParticles;
	int NumberOfSimulations;
};

class StochasticDirections:public Directions
{
public:
	StochasticDirections(int NumberOfSimulations,vector<vector<char>> DeterministicDirectionsOfParticles);
	virtual vector<char> operator()(int SimulationNumber) const;//same as above.
	virtual Directions* clone() const;//same as above
	int getNumberOfSimulations() const;//same as above
    ~StochasticDirections(){};
private:
	vector<vector<char>> DirectionsOfParticles;
	int NumberOfParticles;
	int NumberOfSimulations;
	
};



#endif