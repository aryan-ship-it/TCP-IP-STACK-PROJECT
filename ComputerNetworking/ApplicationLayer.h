#pragma once
#include<vector>
#include "HTTPRequest.h"
#include "IPAddress.h"
#include <vector>



class ApplicationLayer {
private:
	vector<string> Headers;

public:
	ApplicationLayer(HTTPRequest& Request);
	void setHeaders(vector<string> Message);
	vector<string> getHeaders();
	





};



