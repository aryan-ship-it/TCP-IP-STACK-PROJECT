#include <cstdlib>
#include <ctime>
#include "IPAddress.h"

using namespace std;

IPAddress::IPAddress() {
	Address = randomIPAddress();
}

string IPAddress::getIPAddress() {
	return Address;
}

void IPAddress::setIPAddress(string address) {
	Address = address;
}

string IPAddress::randomIPAddress() {

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