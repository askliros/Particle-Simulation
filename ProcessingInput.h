#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

#ifndef ProcessingInput_H
#define ProcessingInput_H
class ProcessingInput{

public:
	ProcessingInput(string DirectionsFile,string InitialCoordinatesFile,string ObjectTypeFile,string ChamberTerminalCoordinatesFile);
	void setDirections();//Sets the directions for each particle
	void setInitialCoordinates(); //sets the initial coordinates for each particle
	void setTypes();//set the types of each particle
	void setChamberTerminalCoordinates();//sets the chamber's terminal coordinates.
	vector<vector<int>> getInitialCoordinates() const;	//returns the Initial coordinates of each particle.
	vector<char> getTypes() const;//Returns the type of each particle.
	vector<vector<char>> getDirections() const; //returns the directions.
	vector<vector<char>> splittingString(vector<string> Aux) const;	//splits the string vector of directions.
	vector<vector<int>> splittingTheString(vector<string> Aux) const;// splits the string vector for the initial coordinates of the particle as well as the chamber's termianl coordinates.
	vector<int> getChamberTerminalCoordinates() const;//gets the Chamber's terminal coordinates.
	void operator()();// assesses all the setter functions.
	vector<string> ProcessingFile(string File);//processes the files that contain the directions, the chamber's terminal coordinates, the initial directions of the particles and the particles' types.
	string remove_unwanted_characters( string MyString, char MyChar ) const;
	bool IsInteger(string MyString) const;//assesses if a character is an integer.
	void FinalCheck() const;
	ProcessingInput* clone() const;//returns the this pointer of that object
	~ProcessingInput(){};

private:
	vector<vector<int>> InitialCoordinates;	
	vector<char> Types;
	vector<vector<char>> Directions;
	string DirectionsFile;
	string InitialCoordinatesFile;	
	string ObjectTypeFile;
	string ChamberTerminalCoordinatesFile;
	vector<int> ChamberTerminalCoordinates;



};
#endif