#pragma once
#include <string>
/*
* The IPAddress class is a helper class that generates custom as well as random sourceIP and destination IP addresses
* Source 
* 
* 
*/


using namespace std;

class IPAddress {
private:
	string sourceIP;
	string destIP;
	string randomIPAddress();
public:

	IPAddress();
	//setters and getters
	string getSourceIPAddress();
	void setSourceIPAddress(string);

	string getDestIPAddress();
	void setDestIPAddress(string);

	
};


