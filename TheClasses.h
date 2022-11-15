#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include "Velocities.h"
class Particle{
public: 
	Particle(){};
	virtual void operator()(char direction) =0;
	virtual Particle* clone() const=0;
	virtual void EnvironmentAssessment(int maxxcoord, int minxcoord,int maxycoord, int minycoord)=0;
	virtual vector<int> getcoordinates() const=0;
	virtual void setpreviouscoordinates(int x,int y)=0;
	virtual vector<int> getpreviouscoordinates() const=0;
	virtual string IdentifyYourself() const=0;
	virtual vector<vector<int>> getParticleVelocities()=0;
	~Particle(){};
private:
	int xcoordinate;
	int ycoordinate;
	int xpreviouscoordinate;
	int ypreviouscoordinate;
	int maxxcoord;
	int minxcoord;
	int maxycoord;
	int minycoord;
	vector<vector<int>> ParticleVelocities;
	Velocities* VelocitiesPtr;
};

class Neutrino:public Particle
{
public: 
	Neutrino(int xcoordinate,int ycoordinate, Velocities& PartVelocities);
	virtual void operator()(char direction);//updates the positions of each particle.
	virtual Particle* clone() const;//returns the this pointer.
	virtual void EnvironmentAssessment(int maxxcoord, int minxcoord,int maxycoord, int minycoord);//Sets the maximum coordinates that a particle can move as well as the velocities.
	virtual vector<int> getcoordinates() const;//gets the current coordinaes of the particle
    virtual void setpreviouscoordinates(int x,int y); 
	virtual vector<int> getpreviouscoordinates() const;//gets the previous,one step back, coordinates of the particle
	virtual string IdentifyYourself() const;//returns the type of the particle in a string format either 'P' or 'N' or 'E'.
	virtual vector<vector<int>> getParticleVelocities();//gets the velocities of the particle.
	~Neutrino(){};
private:
	int xcoordinate;
	int ycoordinate;
	int xpreviouscoordinate;
	int ypreviouscoordinate;
	int maxxcoord;
	int minxcoord;
	int maxycoord;
	int minycoord;
	vector<vector<int>> ParticleVelocities;
	Velocities* VelocitiesPtr;



};

class Electron:public Particle
{
public: 
	Electron(int xcoordinate,int ycoordinate, Velocities& PartVelocities);
	virtual void operator()(char direction);
	virtual Particle* clone() const;
	virtual void EnvironmentAssessment(int maxxcoord, int minxcoord,int maxycoord, int minycoord);
	virtual vector<int> getcoordinates() const;
	virtual void setpreviouscoordinates(int x,int y); 
	virtual vector<int> getpreviouscoordinates() const;
	virtual string IdentifyYourself() const;
	virtual vector<vector<int>> getParticleVelocities();
	~Electron(){};
private:
	int xcoordinate;
	int ycoordinate;
	int xpreviouscoordinate;
	int ypreviouscoordinate;
	int maxxcoord;
	int minxcoord;
	int maxycoord;
	int minycoord;
	vector<vector<int>> ParticleVelocities;
	Velocities* VelocitiesPtr;



};

class Photon:public Particle
{
public: 
	Photon(int xcoordinate,int ycoordinate,Velocities& PartVelocities);
	virtual void operator()(char direction);
	virtual Particle* clone() const;
	virtual void EnvironmentAssessment(int maxxcoord, int minxcoord,int maxycoord, int minycoord);
	virtual vector<int> getcoordinates() const;
	virtual void setpreviouscoordinates(int x,int y); 
	virtual vector<int> getpreviouscoordinates() const;
	virtual string IdentifyYourself() const;
	virtual vector<vector<int>> getParticleVelocities();
	~Photon(){};
private:
	int xcoordinate;
	int ycoordinate;
	int xpreviouscoordinate;
	int ypreviouscoordinate;
	int maxxcoord;
	int minxcoord;
	int maxycoord;
	int minycoord;
	vector<vector<int>> ParticleVelocities;
	Velocities* VelocitiesPtr;
};





#endif