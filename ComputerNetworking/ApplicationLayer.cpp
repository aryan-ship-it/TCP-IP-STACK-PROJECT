#include "ApplicationLayer.h"
#include "IPAddress.h"
#include <vector>
#include <iostream>


using namespace std; 

void ApplicationLayer:: RandomIPset(){
	IPAddress source; 
	string sourceIP = source.getIPAddress();

	IPAddress dest;
	string destIP = dest.getIPAddress();

	setSourceIP(sourceIP);
	setDestIP(destIP);

	Message.push_back("sourceIP: " + sourceIP);
	Message.push_back("DestIP: " + destIP);
		


}

void ApplicationLayer::setSourceIP(string IP) { SourceIP = IP;}

void ApplicationLayer::setDestIP(string IP) { SourceIP = IP; }

string ApplicationLayer::getSourceIP() { return SourceIP; }
string ApplicationLayer::getDestIP() { return DestIP; }


