#include "FilenamesReader.h"

FilenamesReader::FilenamesReader(string Filenames)
{
   this->Filenames=Filenames;
}

vector<string> FilenamesReader::operator()()
{
   vector<string> Aux;
	string line;
	ifstream inFile((this->Filenames).c_str());
	if(inFile.is_open())
	{
		while(!inFile.eof()){
			getline(inFile,line);
			Aux.push_back(line);
		}
	}
	inFile.close();
	if(Aux.size()!=4)
	{
	  throw("Wrong number of files given!");
	}
	else{
		  return Aux;
	    }
  

}

FilenamesReader* FilenamesReader::clone() const
{
    return new FilenamesReader(*this);

}
