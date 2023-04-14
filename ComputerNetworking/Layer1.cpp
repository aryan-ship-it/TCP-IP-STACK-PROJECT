#include <cstdlib>
#include <ctime>
#include "Layer1.h"

using namespace std;

IPAddress::IPAddress() {
	address = setIPAddress();
}

string IPAddress::getIPAddress() {
	return address;
}

string IPAddress::setIPAddress() {
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
