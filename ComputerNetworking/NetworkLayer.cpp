#include "NetworkLayer.h"
#include "IPAddress.h"

NetworkLayer::NetworkLayer() {
	IPAddress IP;
	string sourceIP = IP.getSourceIPAddress();
	string destIP = IP.getDestIPAddress();

	setSourceIP(sourceIP);
	setDestIP(destIP);

}

void NetworkLayer::setSourceIP(string sourceIP) { SourceIP= sourceIP; }
void NetworkLayer::setDestIP(string destIP) { DestIP = destIP; }
