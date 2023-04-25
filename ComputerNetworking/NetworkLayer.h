#pragma once
#include "IPAddress.h"
#include <string>


class NetworkLayer
{
private: 
	string SourceIP;
	string DestIP; 
public: 
	NetworkLayer();
	void setSourceIP(string sourceIP);
	void setDestIP(string destIP);
	

	string getSourceIP();
	string getDestIP();


	
};

