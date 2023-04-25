#pragma once
#include<vector>
#include "Buffer.h"
#include "IPAddress.h"



class ApplicationLayer : public Buffer {
protected:

	vector <string> Layer1Message;
	string Host; 
	string UserAgent; 
	string Accept;
	string AcceptLanguage;
	string AcceptEncoding;
	string Connection; 

public:
	void setAppMessage(string Message);
	vector<string> getAppMessage();





};



