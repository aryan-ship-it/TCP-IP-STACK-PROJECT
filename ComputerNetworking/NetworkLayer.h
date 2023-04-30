#pragma once
#include "IPAddress.h"
#include "TransportLayer.h"
#include <string>
/*
* The primary function of this class is to set the IP address and then encapsulate the message
* The network layer has a Transport layer object thus forming a composition relationship with the TCP layer 
* The constructor takes the Transport Layer object and then encapsulates the necessary parameters to it such as the source IP and dest IP
* data members are populated by the constructor itself with random values
* customized sourceIp and destIp can be added using setters and getters
*/

class NetworkLayer
{
private:
	map <string, string> Message;
	string SourceIP;
	string DestIP; 
public: 
	NetworkLayer(TransportLayer &Request);
	void setSourceIP(string sourceIP);
	void setDestIP(string destIP);
	
	void setMessage(map<string,string>);
	map<string, string> getMessage();
	

	string getSourceIP();
	string getDestIP();


	
};

