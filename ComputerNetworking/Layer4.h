#pragma once
#include <string>

#ifndef LAYER4_H
#define LAYER4_H

using namespace std;

class MacAddress {
public:
	MacAddress();
	string getMacAddress();
	void setMacAddress(string);
private:
	string address;
	string randomMacAddress();

};

#endif
