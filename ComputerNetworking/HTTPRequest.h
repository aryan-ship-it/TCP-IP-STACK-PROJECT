#pragma once
#include <string>
#include <vector> 
#include <map>

/*
* The http request Layer is the first layer that processes the message.
* Message is a map data type that creates key value pairs from the text file 
* parseMessage() method parses the message from the text message from the text file and generates a map 
* The parseMessage() method then calls the setter for Message and sets the key value pair
* Headers is a private data members that stores all the headers retrieved from the request
* Method clarifies whether the incoming request is a POST request or a GET request
* The constructor of this class  parses the message and sets the key value pair
*/
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

	//setter
	void setMethod(string);
	//getter
	string getMethod();


	void setHeaders(map <string,string>);
	vector<string> getHeaders();

	void setMessage(map <string,string>);
	map<string, string> getMessage();
	

};

