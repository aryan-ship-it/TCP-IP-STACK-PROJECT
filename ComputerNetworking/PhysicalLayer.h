#pragma once
#include "HTTPRequest.h"
#include <iostream>
#include <bitset>

using namespace std; 

class PhysicalLayer
{
private: 
	string MapString;
	string stringToBinary(const string& input);
	string binaryToString(const string& binary);
	string mapTostring(map<string, string>& myMap);
	
public:
	PhysicalLayer(HTTPRequest &Request);
	string getMapString();
	void setMapstring(string myMap);


};

