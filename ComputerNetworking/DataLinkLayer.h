#pragma once
#include <string>
#include "NetworkLayer.h"

using namespace std;

/*
* The data link layer has a composition relationship with the network layer
* it is responsible for adding MAC addresses 
* the constructor of this class populates the data members with source and destination MAC addresses
* customized MAC addresses can be added using setters and getters of this class
* the method randomDataLinkLayer() generates and sets random source as well as destination MAC addresses
* message is thus encapsulated in the Message data member which is composed of a MAP
*/

class DataLinkLayer {
public:
	//constructor
	DataLinkLayer(NetworkLayer &Request);
	//setters and getters
	string getSourceMac();
	void setSourceMac(string);
	string getDestMac();
	void setDestMac(string);
	void setMessage(map<string,string>);
	map<string, string> getMessage();
private:
	map <string, string> Message;
	string sourceMAC;
	string destMAC;
	string randomDataLinkLayer();

};

