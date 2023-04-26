#include "PhysicalLayer.h"


PhysicalLayer:: PhysicalLayer(HTTPRequest &Request){
	map<string, string> requestMap = Request.getBuffer();
	string message = mapTostring(requestMap);
	string binaryOutput = stringToBinary(message);

	cout << message << endl;
	cout << endl;
	cout << binaryOutput;
	

	




}


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

void PhysicalLayer::setMapstring(string myMap) { MapString = myMap; }
string PhysicalLayer::getMapString() { return MapString; }