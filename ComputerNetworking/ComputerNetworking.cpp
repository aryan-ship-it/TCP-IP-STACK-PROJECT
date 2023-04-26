// ComputerNetworking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include "ApplicationLayer.h"
#include "TransportLayer.h"
#include "NetworkLayer.h"
#include "DataLinkLayer.h"
#include "PhysicalLayer.h"
#include "HTTPRequest.h"
#include <vector>


using namespace std;

string mapToString(const map<string, string>& myMap) {
	string result = "{";
	for (const auto& kv : myMap) {
		result += kv.first + ": " + kv.second + ",";
	}
	if (!myMap.empty()) {
		// Remove the trailing ", " if the map is not empty
		result = result.substr(0, result.length() - 2);
	}
	result += "}";
	return result;
}




int main()
{

	HTTPRequest Request;

	ApplicationLayer A(Request);
	vector<string> headers = A.getHeaders();
	//for (const auto& key : headers) {
	//	std::cout << key << " ";
	//	cout << endl;
	//}
	TransportLayer T(Request);
	NetworkLayer N(Request);
	DataLinkLayer D(Request);

	for (const auto& pair : Request.getBuffer()) {
		std::cout  << pair.first << ":" << pair.second << std::endl; 
	}

	cout << endl;
	


	string map = mapToString(Request.getBuffer());

	cout << map;

	
	
	

	
   
}




