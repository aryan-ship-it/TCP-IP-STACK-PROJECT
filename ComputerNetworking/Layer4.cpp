#include "Layer4.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

MacAddress::MacAddress() {
	address = randomMacAddress();
}

string MacAddress::getMacAddress() {
	return address;
}

void MacAddress::setMacAddress(string address) {
	this->address = address;
}

string MacAddress::randomMacAddress() {
	srand(time(nullptr));
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