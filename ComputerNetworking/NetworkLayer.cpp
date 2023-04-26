#include "NetworkLayer.h"
#include "IPAddress.h"

NetworkLayer::NetworkLayer(HTTPRequest &Request) {
	IPAddress IP;
	string sourceIP = IP.getSourceIPAddress();
	string destIP = IP.getDestIPAddress();

	setSourceIP(sourceIP);
	setDestIP(destIP);
	
	map<string, string> message = Request.getBuffer();
	message["Source IP"] = sourceIP;
	message["Dest IP"] = destIP;
	Request.setBuffer(message);

}

void NetworkLayer::setSourceIP(string sourceIP) { SourceIP= sourceIP; }
void NetworkLayer::setDestIP(string destIP) { DestIP = destIP; }

string NetworkLayer::getSourceIP() { return SourceIP; }
string NetworkLayer::getDestIP() { return DestIP; }