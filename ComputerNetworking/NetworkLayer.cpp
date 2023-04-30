#include "NetworkLayer.h"
#include "IPAddress.h"
/*
* The primary function of this class is to set the IP address and then encapsulate the message
* The network layer has a Transport layer object thus forming a composition relationship with the TCP layer
* The constructor takes the Transport Layer object and then encapsulates the necessary parameters to it such as the source IP and dest IP
* data members are populated by the constructor itself with random values
* customized sourceIp and destIp can be added using setters and getters
*/

//constructor implementation 
NetworkLayer::NetworkLayer(TransportLayer &Request) {
	//temporary IP Object
	IPAddress IP;
	string sourceIP = IP.getSourceIPAddress(); //set sourceIP from the IP class
	string destIP = IP.getDestIPAddress(); //set DestIp from the IP class

	//set IP addresses
	setSourceIP(sourceIP);
	setDestIP(destIP);

	//setMessage
	setMessage(Request.getMessage()); //getmessage from the transport lyaer

	Message["Source IP"] = sourceIP; //add source Ip to the message
	Message["Dest IP"] = destIP; //add dest IP to the message

}

//setters and getters 
void NetworkLayer::setMessage(map<string, string> message) {Message = message;}
map<string, string> NetworkLayer::getMessage() {return Message;}

void NetworkLayer::setSourceIP(string sourceIP) { SourceIP= sourceIP; }
void NetworkLayer::setDestIP(string destIP) { DestIP = destIP; }


string NetworkLayer::getSourceIP() { return SourceIP; }
string NetworkLayer::getDestIP() { return DestIP; }