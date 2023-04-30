#include <cstdlib>
#include <ctime>
#include "IPAddress.h"

using namespace std;

/*
* The IPAddress class is a helper class that generates custom as well as random sourceIP and destination IP addresses
* Source IP and the destination IP are set by the constructor
* The randomIPAddress() method generates a random IP address each time it is called
* setters and getters allow you to add custom IP addresses as well
*/

//constructor
IPAddress::IPAddress() {
	while (sourceIP == destIP) {
		sourceIP = randomIPAddress();
		destIP = randomIPAddress();

	}

}


string IPAddress::getSourceIPAddress() {return sourceIP;}
void IPAddress::setSourceIPAddress(string address) {sourceIP = address;}

string IPAddress::getDestIPAddress() {return destIP;}
void IPAddress::setDestIPAddress(string address) { destIP = address;}

//random IP generator
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