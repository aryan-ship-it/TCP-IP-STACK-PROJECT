#pragma once
#include <string>

#ifndef LAYER_H
#define LAYER_H

using namespace std;

class IPAddress {
public:
	IPAddress();
	string getIPAddress();

private:
	string address;
	string setIPAddress();
};

#endif

