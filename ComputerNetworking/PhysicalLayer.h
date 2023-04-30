#pragma once
#include "DataLinkLayer.h"
#include "Serializer.h"
#include <iostream>
#include <bitset>
/*
* Physical Layer is the final layer that is responsible for converting the encapsulated message into a binary file
* it has a direct composition relation with the data link layer 
* the methods string to binary converts the encapsulated string message to binary
* the method binary to string converts a binary message to string 
* map to string generates a string representation of the map 
* the constructor takes in a datalink layer object
* setters and getters allow you to generate customized maps
* For serializiation this class has a dependency relation with the serializer class
*/
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

