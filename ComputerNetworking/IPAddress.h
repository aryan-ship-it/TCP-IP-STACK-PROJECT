#pragma once
#include <string>


using namespace std;

class IPAddress {
private:
	string sourceIP;
	string destIP;
	string randomIPAddress();
public:
	IPAddress();
	string getSourceIPAddress();
	void setSourceIPAddress(string);

	string getDestIPAddress();
	void setDestIPAddress(string);

	
};


