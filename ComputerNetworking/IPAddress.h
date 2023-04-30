#pragma once
#include <string>
/*
* The IPAddress class is a helper class that generates custom as well as random sourceIP and destination IP addresses
* Source IP and the destination IP are set by the constructor 
* The randomIPAddress() method generates a random IP address each time it is called
* setters and getters allow you to add custom IP addresses as well 
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


