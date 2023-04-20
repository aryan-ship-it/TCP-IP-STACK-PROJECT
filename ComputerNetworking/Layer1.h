#pragma once
#include <string>

#ifndef LAYER1_H
#define LAYER1_H

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

#endif

