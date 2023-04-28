#pragma once
#include "DataLinkLayer.h"
#include "Serializer.h"
#include <iostream>
#include <bitset>

using namespace std; 

class PhysicalLayer
{
private: 
	string MapString;
	map <string, string> Message;
	string Response;

	string stringToBinary(const string& input);
	string binaryToString(const string& binary);


	string mapTostring(map<string, string>& myMap);
	
public:
	PhysicalLayer(DataLinkLayer &Request);

	void setMessage(map<string, string>);
	map<string, string> getMessage();
	
	void setResponse(string response);
	string getResponse();
	
	void serializeFile(string fileName);

	string getMapString();
	void setMapstring(string myMap);
	


};

