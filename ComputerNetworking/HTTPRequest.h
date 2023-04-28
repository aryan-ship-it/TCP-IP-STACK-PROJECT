#pragma once
#include <string>
#include <vector> 
#include <map>

using namespace std;


class HTTPRequest
{
private:
	map <string, string> Message;
	map<string,string> parseMessage(string);
	vector<string> Headers;
	string Method;
public:

	HTTPRequest(string method,string fileName);

	void setMethod(string);
	string getMethod();


	void setHeaders(map <string,string>);
	vector<string> getHeaders();

	void setMessage(map <string,string>);
	map<string, string> getMessage();
	

};

