#ifndef FilenamesReader_H
#define FilenamesReader_H
#include <iostream>
using namespace std;
#include <string>
#include<vector>
#include<fstream>
class FilenamesReader
{
public:
	FilenamesReader(string Filenames);//constructor that accepts the name of the file which has the filenames
	vector<string> operator()();//Reads the filenames' names.
	FilenamesReader* clone() const;//returns the this pointer
	~FilenamesReader(){}; //destructor



private:
	string Filenames;



};
#endif