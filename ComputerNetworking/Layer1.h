#pragma once
#include <string>

using namespace std;

class IPAddress {
public:
	IPAddress();
	string getIPAddress();

private:
	string address;
	string setIPAddress();
};


