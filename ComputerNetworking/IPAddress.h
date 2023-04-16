#pragma once
#include <string>


using namespace std;

class IPAddress {
public:
	IPAddress();
	string getIPAddress();
	void setIPAddress(string);

private:
	string address;
	string randomIPAddress();
};


