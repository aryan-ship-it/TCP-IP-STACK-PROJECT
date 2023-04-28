#pragma once
#include "IPAddress.h"
#include "TransportLayer.h"
#include <string>


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

