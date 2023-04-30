#include "PhysicalLayer.h"


/*
* Physical Layer is the final layer that is responsible for converting the encapsulated message into a binary file
* it has a direct composition relation with the data link layer
* the methods string to binary converts the encapsulated string message to binary
* the method binary to string converts a binary message to string
* map to string generates a string representation of the map
* the constructor takes in a datalink layer object
* setters and getters allow you to generate customized maps
*/

//constructor 
PhysicalLayer:: PhysicalLayer(DataLinkLayer &Request){
	map<string, string> requestMap = Request.getMessage(); //copy of the map

	setMapstring(mapTostring(requestMap)); //set the string representation of the map 
	string binaryOutput = stringToBinary(MapString); //create a binary output 

	//take the get responses 
	setResponse(binaryOutput);
	//serialize the file into request.txt
	serializeFile("Request.txt");
	cout << endl;
	cout << binaryOutput;

}


//file serialzer 
void PhysicalLayer::serializeFile(string fileName){
	Serializer S(fileName,Response);
	
}
//setters and getters

void PhysicalLayer::setResponse(string response) { Response = response;}
string PhysicalLayer::getResponse() { return Response;}

void PhysicalLayer::setMessage(map<string, string> message) { Message = message; }
map<string, string> PhysicalLayer::getMessage() {return Message;}

//convert a string to binary
string PhysicalLayer::stringToBinary(const string& input) {
	string binary;
	for (char c : input) {
		binary += bitset<8>(c).to_string();
	}
	return binary;
}
//convert a binary to string
string PhysicalLayer:: binaryToString(const string& binary) {
	string decoded;
	for (size_t i = 0; i < binary.length(); i += 8) {
		bitset<8> bits(binary.substr(i, 8));
		decoded += char(bits.to_ulong());
	}
	return decoded;
}

//create a string of the given map in json format
string PhysicalLayer::mapTostring(map<string,string> &myMap) {
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
//setters and getters

void PhysicalLayer::setMapstring(string mapString) { MapString = mapString; }
string PhysicalLayer::getMapString() { return MapString; }