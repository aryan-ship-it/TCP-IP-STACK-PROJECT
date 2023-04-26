#pragma once
#include <string>
#include "HTTPRequest.h"

using namespace std;

class DataLinkLayer {
public:
	DataLinkLayer(HTTPRequest& Request);
	string getSourceMac();
	void setSourceMac(string);
	string getDestMac();
	void setDestMac(string);
private:
	string sourceMAC;
	string destMAC;
	string randomDataLinkLayer();

};

