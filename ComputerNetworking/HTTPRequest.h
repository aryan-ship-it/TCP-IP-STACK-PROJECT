#pragma once
#include <string>
#include <vector> 
#include <map>

using namespace std;


class HTTPRequest
{
private:
	map <string, string> Buffer;
	map<string,string> parseBuffer();
public:
	HTTPRequest();
	void setBuffer(map <string,string>);
	map<string, string> getBuffer();
	

};

