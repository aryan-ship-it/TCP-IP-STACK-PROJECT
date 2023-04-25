#pragma once
#include<vector>
#include "Buffer.h"
#include "IPAddress.h"



class ApplicationLayer : public Buffer {
protected:

	vector <string> Layer1Message;
	string SourceIP; 
	string DestIP;
	string Host; 
	string UserAgent; 
	string Accept;
	string AcceptLanguage;
	string AcceptEncoding;
	string Connection; 

public:
	void RandomIPset();
	void setAppMessage(string Message);
	vector<string> getAppMessage();
	void setSourceIP(string IP);
	string getSourceIP();
	void setDestIP(string IP);
	string getDestIP();




};



