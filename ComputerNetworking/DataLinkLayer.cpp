#include "DataLinkLayer.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;
/*
* The data link layer has a composition relationship with the network layer
* it is responsible for adding MAC addresses
* the constructor of this class populates the data members with source and destination MAC addresses
* customized MAC addresses can be added using setters and getters of this class
* the method randomDataLinkLayer() generates and sets random source as well as destination MAC addresses
* message is thus encapsulated in the Message data member which is composed of a MAP
*/

//constructor
DataLinkLayer::DataLinkLayer(NetworkLayer &Request) {
	string source; //source MAC variable
	string dest; //dest MAC variable 
	while (source == dest) { //generate different source and dest mac
		source = randomDataLinkLayer();
		dest = randomDataLinkLayer();
	}
	setSourceMac(source);
	setDestMac(dest);

	setMessage(Request.getMessage()); //get the message from the network layer object 
	
	Message["SourceMAC"] = source; //add source MAC address
	Message["DestMAC"] = dest; //add dest MAC address
	
	

	
}


//setters and getters

void DataLinkLayer::setMessage(map<string, string> message) { Message = message;}
map<string, string> DataLinkLayer::getMessage() {return Message;}


string DataLinkLayer::getDestMac() { return destMAC; }
string DataLinkLayer::getSourceMac() { return sourceMAC; }

void DataLinkLayer::setSourceMac(string address) {sourceMAC = address;}
void DataLinkLayer::setDestMac(string address) { destMAC = address; }

//generate a random MAC address
string DataLinkLayer::randomDataLinkLayer() {
	unsigned char mac[6];
	for (int i = 0; i < 6; i++) {
		mac[i] = rand() % 256;
	}

	stringstream ss;
	for (int i = 0; i < 6; i++) {
		ss << hex << setfill('0') << setw(2) << uppercase << static_cast<int>(mac[i]) << ":";
	}
	string address = ss.str();
	return address;
}