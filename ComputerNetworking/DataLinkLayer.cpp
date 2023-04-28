#include "DataLinkLayer.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

DataLinkLayer::DataLinkLayer(NetworkLayer &Request) {
	string source;
	string dest;
	while (source == dest) {
		source = randomDataLinkLayer();
		dest = randomDataLinkLayer();
	}
	setSourceMac(source);
	setDestMac(dest);

	setMessage(Request.getMessage());
	
	Message["SourceMAC"] = source;
	Message["DestMAC"] = dest;



	
	

	
}

void DataLinkLayer::setMessage(map<string, string> message) { Message = message;}
map<string, string> DataLinkLayer::getMessage() {return Message;}


string DataLinkLayer::getDestMac() { return destMAC; }
string DataLinkLayer::getSourceMac() { return sourceMAC; }

void DataLinkLayer::setSourceMac(string address) {sourceMAC = address;}
void DataLinkLayer::setDestMac(string address) { destMAC = address; }

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