#include "PhysicalLayer.h"


PhysicalLayer:: PhysicalLayer(DataLinkLayer &Request){
	map<string, string> requestMap = Request.getMessage();

	setMapstring(mapTostring(requestMap));
	string binaryOutput = stringToBinary(MapString);


	setResponse(binaryOutput);
	serializeFile("Request.txt");
	cout << endl;
	cout << binaryOutput;

}


void PhysicalLayer::serializeFile(string fileName){
	Serializer S(fileName,Response);
	
}

void PhysicalLayer::setResponse(string response) { Response = response;}
string PhysicalLayer::getResponse() { return Response;}

void PhysicalLayer::setMessage(map<string, string> message) { Message = message; }
map<string, string> PhysicalLayer::getMessage() {return Message;}


string PhysicalLayer::stringToBinary(const string& input) {
	string binary;
	for (char c : input) {
		binary += bitset<8>(c).to_string();
	}
	return binary;
}

string PhysicalLayer:: binaryToString(const string& binary) {
	string decoded;
	for (size_t i = 0; i < binary.length(); i += 8) {
		bitset<8> bits(binary.substr(i, 8));
		decoded += char(bits.to_ulong());
	}
	return decoded;
}


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

void PhysicalLayer::setMapstring(string mapString) { MapString = mapString; }
string PhysicalLayer::getMapString() { return MapString; }