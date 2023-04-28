#include "NetworkLayer.h"
#include "IPAddress.h"

NetworkLayer::NetworkLayer(TransportLayer &Request) {
	IPAddress IP;
	string sourceIP = IP.getSourceIPAddress();
	string destIP = IP.getDestIPAddress();

	setSourceIP(sourceIP);
	setDestIP(destIP);

	setMessage(Request.getMessage());

	Message["Source IP"] = sourceIP;
	Message["Dest IP"] = destIP;

}

void NetworkLayer::setMessage(map<string, string> message) {Message = message;}
map<string, string> NetworkLayer::getMessage() {return Message;}

void NetworkLayer::setSourceIP(string sourceIP) { SourceIP= sourceIP; }
void NetworkLayer::setDestIP(string destIP) { DestIP = destIP; }


string NetworkLayer::getSourceIP() { return SourceIP; }
string NetworkLayer::getDestIP() { return DestIP; }