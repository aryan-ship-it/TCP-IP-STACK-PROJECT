#pragma once
#include <string>
#include "NetworkLayer.h"

using namespace std;

class DataLinkLayer {
public:
	DataLinkLayer(NetworkLayer &Request);
	string getSourceMac();
	void setSourceMac(string);
	string getDestMac();
	void setDestMac(string);
	void setMessage(map<string,string>);
	map<string, string> getMessage();
private:
	map <string, string> Message;
	string sourceMAC;
	string destMAC;
	string randomDataLinkLayer();

};

