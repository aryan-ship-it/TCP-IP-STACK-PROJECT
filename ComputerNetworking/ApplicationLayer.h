#pragma once
#include<vector>
#include "HTTPRequest.h"
#include "IPAddress.h"



class ApplicationLayer {
protected:


public:
	ApplicationLayer(HTTPRequest* );
	void setHeaders(string Message);
	void getHeaders();
	





};



