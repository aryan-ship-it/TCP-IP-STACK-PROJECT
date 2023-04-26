#include "ApplicationLayer.h"
#include "IPAddress.h"
#include <vector>
#include <iostream>


using namespace std; 

ApplicationLayer::ApplicationLayer(HTTPRequest& Request) {
	vector <string> headers;
	for (const auto& key : Request.getBuffer()) {
		headers.push_back(key.first);
	}	
	setHeaders(headers);
}


void ApplicationLayer::setHeaders(vector<string>headers) { Headers = headers; }
vector<string> ApplicationLayer::getHeaders() { return Headers; }
