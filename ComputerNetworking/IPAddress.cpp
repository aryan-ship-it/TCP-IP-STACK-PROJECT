#include <cstdlib>
#include <ctime>
#include "IPAddress.h"

using namespace std;

IPAddress::IPAddress() {
	address = randomIPAddress();
}

string IPAddress::getIPAddress() {
	return address;
}

void IPAddress::setIPAddress(string address) {
	this->address = address;
}

string IPAddress::randomIPAddress() {
	srand(time(nullptr)); // ensures that it is a different random number every time it runs
	string address = "";
	for (int i = 0; i < 4; i++) {
		int octet = rand() % 256; // generate random number between 0 and 255
		address += to_string(octet); // convert the number to a string and append to the address
		if (i < 3) {
			address += "."; // add a dot seperator between octets
		}
	}
	return address;
}