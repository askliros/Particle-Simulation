#ifndef Velocities_H
#define Velocities_H
#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <ctime>
class Velocities{
public:
	Velocities(){};
	virtual void operator()(int nrows, int ncolumns) =0;
	virtual Velocities* clone() const=0;
	~Velocities(){};
	virtual vector<vector<int>> getVelocities()=0;
	
private:
   vector<vector<int>> MyVelocities;
};


class DeterministicVelocities:public Velocities
{
  public:
	  DeterministicVelocities(int a){};
	virtual void operator()(int nrows, int ncolumns);//fills in the velocities matrix.
	virtual Velocities* clone() const;//returns the this pointer.
	~DeterministicVelocities(){};
	virtual vector<vector<int>> getVelocities();//gets the velocities matrix.
private:
   vector<vector<int>> MyVelocities;
};


class StochasticVelocities:public Velocities
{
  public:
	StochasticVelocities(int a);
	virtual void operator()(int nrows, int ncolumns);
	virtual Velocities* clone() const;	
	virtual vector<vector<int>> getVelocities();
	~StochasticVelocities(){};
private:
  vector<vector<int>> MyVelocities;
};



#endif