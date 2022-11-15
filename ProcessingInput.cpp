#include "ProcessingInput.h"

ProcessingInput::ProcessingInput(string DirectionsFile,string InitialCoordinatesFile,string ObjectTypeFile, string ChamberTerminalCoordinatesFile)
{
   this->DirectionsFile=DirectionsFile;
   this->InitialCoordinatesFile=InitialCoordinatesFile;  
   this->ObjectTypeFile=ObjectTypeFile;
   this->ChamberTerminalCoordinatesFile=ChamberTerminalCoordinatesFile;
}

void ProcessingInput::operator ()() //OK
{
	try{
        this->setDirections();
	}
	catch(char* msg1)
	{
		cout<<msg1<<endl;
		cout<<"Program is terminated. Please press a key to continue."<<endl;
		getchar();
		exit(0);
	}
	
	try{
         this->setInitialCoordinates();
	}
	catch(char* msg2)
	{
		cout<<msg2<<endl;
		cout<<"Program is terminated. Please press a key to continue."<<endl;
		getchar();
		exit(0);
	}

  
 
  try{
      this->setTypes();
     }
  catch(char* msg)
  {
	  cout<<msg<<endl;
	  cout<<"Program is terminated. Please press a key to continue."<<endl;
		getchar();
	  exit(0);
  }


  try{
	  this->setChamberTerminalCoordinates();
  }catch(char* msg)
  {
    cout<<msg<<endl;
	cout<<"Program is terminated. Please press a key to continue."<<endl;
	getchar();
	exit(0);

  }

  try{
	  this->FinalCheck();
  }
  catch(char* msg)
  {
    cout<<msg<<endl;
	cout<<"Program is terminated. Please press a key to continue."<<endl;
	getchar();
	exit(0);
  }

}

void ProcessingInput::setDirections()//OK
{
    //Getting the contents of the Directions File
	vector<string> Aux=this->ProcessingFile(this->DirectionsFile);
	vector<vector<char>> Trial=this->splittingString(Aux);
	int trialsum=0;
	int ActualNumberOfDirections=Trial[0].size();
	for(size_t i=0;i!=Trial.size();i++)
	{
		
		if(Trial[i].size()!=ActualNumberOfDirections)
		{
			throw("Number of directions mismatch with that of the first particle's or wrong filename!");
		}
		else
		{
			for(size_t j=0;j!=Trial[i].size();j++)
			{
				if(Trial[i].at(j)!='U'&&Trial[i].at(j)!='D'&&Trial[i].at(j)!='L'&&Trial[i].at(j)!='R')
				{
					throw("Wrong type of direction given or wrong filename!");
					
			        
				}
			}
		}


	}
	
	this->Directions=this->splittingString(Aux);
	     
	

}
	
void ProcessingInput::setInitialCoordinates() //NotOK
{
   //Getting the contents of the Initial Coordinates' file.
	vector<string> Aux=this->ProcessingFile(this->InitialCoordinatesFile);
	try{
	      this->InitialCoordinates=this->splittingTheString(Aux);
	   }
	catch(char* msg)
	{
         cout<<msg<<endl;
		 cout<<"Program is terminated. Please press a key to continue."<<endl;
		 getchar();
		 exit(0);
	}
	

}

void ProcessingInput::setChamberTerminalCoordinates()
{
   //Getting the contents of the Initial Coordinates' file.
	vector<vector<int>> ChamberCoords;
	vector<string> Aux=this->ProcessingFile(this->ChamberTerminalCoordinatesFile);
	try{
	      ChamberCoords=this->splittingTheString(Aux);
	   }
	catch(char* msg)
	{
         cout<<msg<<endl;
		 cout<<"Program is terminated. Please press a key to continue."<<endl;
		 getchar();
		 exit(0);
	}
    if(ChamberCoords.size()!=4)
	{
		throw("Wrong number of chamber coordinates given or wrong filename!");
	}else
	{
	for(size_t i=0;i!=ChamberCoords.size();i++)
	{
        if(ChamberCoords[i].size()!=1)
		{
           throw("Not the right number of chamber's coordinates in a line or wrong filename!");
         
		}
		else
		{
           this->ChamberTerminalCoordinates.push_back(ChamberCoords[i].at(0));
		}

	}
	}

   
}

	

	
void ProcessingInput::setTypes()//OK
{
    //Getting the contents of the object types' file.
	vector<string> Aux=this->ProcessingFile(this->ObjectTypeFile);
    vector<vector<char>> CharObjectType=this->splittingString(Aux);
	//We need to make sure that there is one particle per line as well.
	for(size_t i=0;i!=CharObjectType.size();i++)
	{
		 if(CharObjectType[i].size()!=1)
		 {
			 throw("There are more than one particle types at a line or wrong filename!");
		 }else
		 {
			
			if(CharObjectType[i].at(0)!='P'&&CharObjectType[i].at(0)!='N'&&CharObjectType[i].at(0)!='E')
			{
				throw("You did not give the correct type of particle or wrong filename!");
				
				
			}else{
					this->Types.push_back(CharObjectType[i].at(0));
				 }
		 }
		
	}
	
}
	
vector<vector<int>> ProcessingInput::getInitialCoordinates() const
{
   return this->InitialCoordinates;


}
	

	
vector<char> ProcessingInput::getTypes() const //OK
{
    return this->Types;


}
	
vector<vector<char>> ProcessingInput::getDirections() const //OK
{
   
   return this->Directions;

}


vector<int> ProcessingInput::getChamberTerminalCoordinates() const
{

   return this->ChamberTerminalCoordinates;

}

vector<string> ProcessingInput::ProcessingFile(string File) //OK
{

    vector<string> Aux;
	string line;
	ifstream inFile((File).c_str());
	if(inFile.is_open())
	{
		while(!inFile.eof()){
			getline(inFile,line);
			Aux.push_back(line);
		}
	}
	inFile.close();
	return Aux;



}

vector<vector<char>> ProcessingInput::splittingString(vector<string> Aux) const //OK
{
  vector<vector<char>> FileContentsChar;  
  vector<char> AuxChar;
 
  for(size_t i=0;i!=Aux.size();i++)
  {
      vector<char> AuxChar(Aux[i].begin(),Aux[i].end());
	  FileContentsChar.push_back(AuxChar);
      
	  
  }
  
 return FileContentsChar;
}


vector<vector<int>> ProcessingInput::splittingTheString(vector<string> Aux) const //OK
{
   string s;
  vector<vector<int>> FileContentsString;
  char* MyChar;
  int Number;
  for(size_t i=0;i!=Aux.size();i++)
  {
    FileContentsString.push_back(vector<int>());
    stringstream ss(Aux[i]);
		while (getline(ss, s, ',')) {
		 s=remove_unwanted_characters( s, '(');
         s=remove_unwanted_characters( s, ')');
		 s=remove_unwanted_characters( s, ' ');
		 if(!IsInteger(s))
		 {
			 throw("Coordinate is not an integer!");
			 
			
		 }else
		 {
             Number=strtol(s.c_str(),&MyChar,10);
			 if(Number<0)
			 {
				 throw("No negative coordinates for any particle or chamber position allowed!");
			 }
			 {
			     FileContentsString[i].push_back(Number);
			 }
		 }
		}
  }

  
 return FileContentsString;
 
}


string ProcessingInput::remove_unwanted_characters( string MyString, char MyChar ) const
{
    MyString.erase( remove( MyString.begin(), MyString.end(),MyChar ), MyString.end() ) ;
    return MyString ;
}

bool ProcessingInput::IsInteger(string MyString) const
{
  char* MyChar;
  strtol(MyString.c_str(),&MyChar,10);
  return *MyChar==0;

}

void ProcessingInput::FinalCheck() const
{
   if(!(this->InitialCoordinates.size()==this->Types.size()&&this->InitialCoordinates.size()==this->Directions.size()))
   {
	   throw("Number of entries mismatch!");
	   
		   
   }
   else 
   {  for(size_t i=0;i!=this->InitialCoordinates.size();i++)
      {
		   if(!(this->InitialCoordinates[i].size()==2))
		   {
			  throw("Coordinates' dimensions not of the right size!");
			  
			 
		   }
		   else
		   {
			 
		   }
      }

   }


}

ProcessingInput* ProcessingInput::clone() const
{
    return new ProcessingInput(*this);

}