#pragma once
#include <string>
#include <vector> 

using namespace std;


class Buffer
{
protected:
	vector<string> Message;
public :
	void Layer1Parse();
	vector<string> getMessage();
	void setMessage(vector<string> message);

};

