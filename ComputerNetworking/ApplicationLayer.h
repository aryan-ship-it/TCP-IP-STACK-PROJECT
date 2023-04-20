#pragma once
#include<vector>
#include "Buffer.h"
#include "IPAddress.h"



class ApplicationLayer : public Buffer {
protected:

	vector <string> Layer1Message;
	string SourceIP; 
	string DestIP;

public:
	ApplicationLayer();
	void setMessage(string Message);
	string getMessage();
	void setSourceIP();
	string getSourceIP();



};



